#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5 + 1;

int N, pos[MAXN], seg[4 * MAXN];
vector<int> ok[MAXN];

void update(int v,  int tl, int tr, int pos, int val){
    if(tl == tr){
        seg[v] = val;
    }
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        seg[v] = max(seg[2 * v + 1], seg[2 * v]);
    }
}

int mx(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return seg[v];
    int tm = (tl + tr) / 2;
    return max(mx(2 * v, tl, tm, l, min(r, tm)), mx(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int mx(int l, int r){
    return mx(1, 0, N - 1, l, r);
}

void update(int i, int v){
    update(1, 0, N - 1, i, v);
}

int main(){
    setIO("nocross");

    cin >> N;

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        pos[a] = i;
    }

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        for(int j = max(1, a - 4); j <= min(a + 4, N); j++){
            ok[pos[j]].push_back(i);
        }
    }

    for(int i = 0; i < N; i++){
        //sort(ok[i].begin(), ok[i].end());
        for(int j = ok[i].size() - 1; j >= 0; j--){
            update(ok[i][j], mx(0, ok[i][j] - 1) + 1);
        }
    }

    cout << mx(0, N - 1);
    



}