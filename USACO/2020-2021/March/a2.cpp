#include <iostream>

using namespace std;

const int MAXN = 2e5 + 5;

int N, a[MAXN], t[4 * MAXN], lazy[4 * MAXN], recent[MAXN], recent2[MAXN], mn[4 * MAXN], mx[4 * MAXN];
bool hasGood[4 * MAXN], hasBad[4 * MAXN];
long long ans;

void push(int v, int tl, int tr){
    int tm = (tl + tr) / 2;
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    t[2 * v] += (tm - tl + 1) * lazy[v];
    t[2 * v + 1] += (tr - (tm + 1) + 1) * lazy[v];
    mn[2 * v] += lazy[v];
    mn[2 * v + 1] += lazy[v];
    mx[2 * v] += lazy[v];
    mx[2 * v + 1] += lazy[v];
    lazy[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int amt){
    if(l > r)
        return;
    if(tl == l && tr == r){
        t[v] += (tr - tl + 1) * amt;
        lazy[v] += amt;
        mn[v] += amt;
        mx[v] += amt;
    }
    else{
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        upd(2 * v, tl, tm, l, min(r, tm), amt);
        upd(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, amt);
        t[v] = t[2 * v] + t[2 * v + 1];
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
}

void upd(int v, int tl, int tr, int x){
    if(tl == tr){
        hasGood[v] = false;
        hasBad[v] = true;
    }
    else{
        int tm = (tl + tr) / 2;
        if(x <= tm)
            upd(2 * v, tl, tm, x);
        else
            upd(2 * v + 1, tm + 1, tr, x);
        hasGood[v] = (hasGood[2 * v] || hasGood[2 * v + 1]);
        hasBad[v] = (hasBad[2 * v] || hasBad[2 * v + 1]);
    }
}

int sum(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(mx[v] <= 2 || !hasGood[v])
        return 0;
    if(tl == l && tr == r){
        if(mn[v] >= 2){
            if(!hasBad[v])
                return t[v] - 2 * (tr - tl + 1);
        }
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, min(r, tm)) + 
        sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i <= N; i++){
        recent[i] = N;
        recent2[i] = N;
    }
    for(int i = 0; i <= 4 * N + 4; i++){
        hasGood[i] = true;
    }
    for(int i = N - 1; i >= 0; i--){
        upd(1, 0, N, i, recent[a[i]] - 1, 1);
        upd(1, 0, N, recent[a[i]], recent2[a[i]] - 1, -1);
        upd(1, 0, N, recent[a[i]]);
        // cout << i + 1 << " " << sum(1, 0, N, i, recent[a[i]] - 1) << "\n";
        ans += sum(1, 0, N, i, recent[a[i]] - 1);
        recent2[a[i]] = recent[a[i]];
        recent[a[i]] = i;
    }
    cout << ans << '\n';
}