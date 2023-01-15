#include <iostream>
#include <map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

struct node {
    int val;
    struct node* C[2];

    node() {
        val = 0;
        C[0] = C[1] = NULL;
    }

    node* getc(int c) {
        if (!C[c]) {
            C[c] = new node;
        }
        return C[c];
    }

    void add(int tl, int tr, int amt, int loc){
        val += amt;
        if(tl == tr)
            return;
        int tm = (tl + tr) / 2;
        if(loc <= tm)
            getc(0)->add(tl, tm, amt, loc);
        else
            getc(1)->add(tm + 1, tr, amt, loc);
    }

    int query(int tl, int tr, int l, int r){
        if(tl == l && r == tr)
            return val;
        int tm = (tl + tr) / 2;
        return ((C[0] && l <= min(r, tm)) ? C[0]->query(tl, tm, l, min(r, tm)) : 0) + 
            ((C[1] && max(l, tm + 1) <= r) ? C[1]->query(tm + 1, tr, max(l, tm + 1), r) : 0);
    }
};

node BIT[MAXN];
int N, K, a[MAXN], m[MAXN], c[MAXN];

void bit_add(int loc, int idx) {
    idx++;
    for (; idx; idx -= idx & -idx) {
        BIT[idx].add(1, N, 1, loc);
        c[idx]++;
    }
}

int bit_get(int val, int idx) {
    idx++;
    int sum = 0;
    for (; idx < N + 5; idx += idx & -idx) {
        sum += c[idx] - BIT[idx].query(1, N, max(1, val - K), min(N, val + K));
    }
    return sum;
}

int main(){
    setIO("friendcross");
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        m[x] = i;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += bit_get(a[i], m[a[i]]);
        bit_add(a[i], m[a[i]]);
        //cout << a[i] << " " << m[a[i]] << " " << ans << "\n";
    }
    cout << ans;

}