#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;
const int MAXY = 2e5;

struct slingshot{
    long long x, y, t;
    int i;
};

struct query{
    long long a, b;
    int i;
};

int N, M;
long long ans[MAXN], mn[4 * MAXY][4]; //0 is -y - x, 1 is y - x, 2 is x - y, 3 is y + x
slingshot s[MAXN];
query q[MAXN];
map<long long, int> yindex;
vector<int> ys;

bool scmp(const slingshot& s1, const slingshot& s2){
    return s1.x < s2.x;
}

bool qcmp(const query& q1, const query& q2){
    return q1.a < q2.a;
}

void setup(int v, int tl, int tr){
    for(int i = 0; i < 4; i++){
        mn[v][i] = 1e18;
    }
    if(tl == tr)
        return;
    int tm = (tl + tr) / 2;
    setup(2 * v, tl, tm);
    setup(2 * v + 1, tm + 1, tr);
}

void update(int v, int tl, int tr, int index, long long x, long long y, long long t){
    if(tl == tr){
        mn[v][0] = min(mn[v][0], x + y + t);
        mn[v][1] = min(mn[v][1], x - y + t);
        mn[v][2] = min(mn[v][2], -x + y + t);
        mn[v][3] = min(mn[v][3], -x - y + t);
    }
    else{
        int tm = (tl + tr) / 2;
        if(index <= tm){
            update(2 * v, tl, tm, index, x, y, t);
        }
        else{
            update(2 * v + 1, tm + 1, tr, index, x, y, t);
        }
        for(int i = 0; i < 4; i++){
            mn[v][i] = min(mn[2 * v][i], mn[2 * v + 1][i]);
        }
    }
}

long long get(int v, int tl, int tr, int l, int r, int w){
    if(l > r)
        return 1e18;
    if(tl == l && tr == r){
        return mn[v][w];
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, min(r, tm), w),
            get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, w));
}

int main(){
    setIO("slingshot");
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s[i].x >> s[i].y >> s[i].t;
        s[i].i = i;
        ys.push_back(s[i].y);
    }
    sort(s, s + N, scmp);
    for(int i = 0; i < M; i++){
        cin >> q[i].a >> q[i].b;
        q[i].i = i;
        ans[i] = max(q[i].a, q[i].b) - min(q[i].a, q[i].b);
        ys.push_back(q[i].b);
    }
    sort(q, q + M, qcmp);

    sort(ys.begin(), ys.end());
    for(int i = 0; i < ys.size(); i++){
        yindex[ys[i]] = i;
    }

    setup(1, 0, ys.size());
    int sindex = 0;
    for(int qindex = 0; qindex < M; qindex++){
        while(sindex < N && s[sindex].x <= q[qindex].a){
            update(1, 0, ys.size(), yindex[s[sindex].y], s[sindex].x, s[sindex].y, s[sindex].t);
            sindex++;
        }
        long long left = get(1, 0, ys.size(), 0, yindex[q[qindex].b], 3) + q[qindex].a + q[qindex].b;
        long long right = get(1, 0, ys.size(), yindex[q[qindex].b], ys.size(), 2) + q[qindex].a - q[qindex].b;
        ans[q[qindex].i] = min(ans[q[qindex].i], min(left, right));
    }
    setup(1, 0, ys.size());
    sindex = N - 1;
    for(int qindex = M - 1; qindex >= 0; qindex--){
        while(sindex >= 0 && s[sindex].x >= q[qindex].a){
            update(1, 0, ys.size(), yindex[s[sindex].y], s[sindex].x, s[sindex].y, s[sindex].t);
            sindex--;
        }
        long long left = get(1, 0, ys.size(), 0, yindex[q[qindex].b], 1) - q[qindex].a + q[qindex].b;
        long long right = get(1, 0, ys.size(), yindex[q[qindex].b], ys.size(), 0) - q[qindex].a - q[qindex].b;
        ans[q[qindex].i] = min(ans[q[qindex].i], min(left, right));
    }

    for(int i = 0; i < M; i++){
        cout << ans[i] << "\n";
    }


}