#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

int N, p[MAXN], t[4 * MAXN], s[4 * MAXN];
bool marked[4 * MAXN], hasHi[4 * MAXN];

void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
        hasHi[2 * v + 1] = hasHi[v];
        hasHi[2 * v] = hasHi[v];
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}

void updateHi(int v, int tl, int tr, int l, int r){
    if (l > r)
        return;
    if(l == tl && tr == r){
        t[v] = 2;
        marked[v] = true;
        hasHi[v] = true;
    }
    else{
        push(v);
        int tm = (tl + tr) / 2;
        updateHi(2 * v, tl, tm, l, min(r, tm));
        updateHi(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        hasHi[v] = (hasHi[2 * v] || hasHi[2 * v + 1]);
    }
}

void updateLo(int v, int tl, int tr, int l, int r){
    if(l > r)
        return;
    if(hasHi[v] == false){
        marked[v] = true;
        t[v] = 1;
    }
    else{
        if(l == tl && r == tr){
            if(marked[v] && t[v] == 2){
                updateSum(v, tl, tr, l, r, 1);
            }
            else{
                push(v);
                int tm = (tl + tr) / 2;
                updateLo(2 * v, tl, tm, l, min(r, tm));
                updateLo(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
                hasHi[v] = (hasHi[2 * v] || hasHi[2 * v + 1]);
            }
            hasHi[v] = false;
        }
        else{
            push(v);
            int tm = (tl + tr) / 2;
            updateLo(2 * v, tl, tm, l, min(r, tm));
            updateLo(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
            hasHi[v] = (hasHi[2 * v] || hasHi[2 * v + 1]);
        }
    }
}

void updateSum(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        s[v] += add;
    } 
    else {
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), add);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

int getSum(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(2 * v, tl, tm, pos);
    else
        return t[v] + get(2 * v + 1, tm + 1, tr, pos);
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
        update(1, 0, N, l1, r1, 1);
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
        cout << get(1, 0, N + 1, i) << "\n";
    }

}