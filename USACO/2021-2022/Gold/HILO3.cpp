#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

int N, p[MAXN], t[4 * MAXN];
vector<int> ans[MAXN];

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

int main(){

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    set<int> pre;
    pre.insert(0);
    pre.insert(N + 1);
    for(int i = 0; i < N; i++){
        int l1 = *prev(pre.lower_bound(p[i]));
        int r1 = p[i] - 1;
        int l2 = p[i];
        int r2 = *pre.lower_bound(p[i]) - 1;
        for(int j = l1; j <= r1; j++){
            ans[j].push_back(-1 * p[i]);
        }
        for(int j = l2; j <= r2; j++){
            ans[j].push_back(1 * p[i]);
        }
        //update(1, 0, N + 1, max(l1, l2), min(r1, r2), 1);
        pre.insert(p[i]);
    }

    for(int i = 0; i <= N; i++){
        int pr = 0;
        for(int x: ans[i])
            cout << x << " ";
        cout << "\n";
        //cout << get(1, 0, N + 1, i) << "\n";
    }

}