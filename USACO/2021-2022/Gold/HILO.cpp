#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5 + 5;

int N, p[MAXN], t[4 * MAXN];

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
    pre.insert(-1);
    pre.insert(N + 1);
    for(int i = 0; i < N - 1; i++){
        int j = i + 1;
        int l1 = *prev(pre.lower_bound(p[i])) + 1;
        int r1 = p[i] - 1;
        int l2 = p[j];
        int r2 = *pre.upper_bound(p[j]) - 1;
        update(1, 0, N + 1, max(l1, l2), min(r1, r2), 1);
        pre.insert(p[i]);
    }
    for(int i = 0; i <= N; i++){
        cout << get(1, 0, N + 1, i) << "\n";
    }

}