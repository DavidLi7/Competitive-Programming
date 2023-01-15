#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 200005;

long long mn[4 * MAXN], sum[4 * MAXN], lazy[4 * MAXN];
int N, Q;

void push(int v, int l, int r, int m){
    mn[2 * v] += lazy[v];
    sum[2 * v] += lazy[v] * (m - l + 1);
    lazy[2 * v] += lazy[v];
    mn[2 * v + 1] += lazy[v];
    sum[2 * v + 1] += lazy[v] * (r - m);
    lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int l, int r, int tl, int tr, int c){
    if(l > r)
        return;
    if(tl == l && tr == r){
        mn[v] += c;
        sum[v] += 1LL * c * (tr - tl + 1);
        lazy[v] += c;
    }
    else{
        int tm = (tl + tr) / 2;
        push(v, tl, tr, tm);
        update(2 * v, l, min(r, tm), tl, tm, c);
        update(2 * v + 1, max(l, tm + 1), r, tm + 1, tr, c);
        mn[v] = min(mn[2 * v + 1], mn[2 * v]);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }
}

long long getSum(int v, int l, int r, int tl, int tr){
    if(l > r){
        return 0;
    }
    if(tl == l && tr == r){
        return sum[v];
    }
    else{
        int tm = (tl + tr) / 2;
        push(v, tl, tr, tm);
        return getSum(2 * v, l, min(r, tm), tl, tm) +
                    getSum(2 * v + 1, max(tm + 1, l), r, tm + 1, tr);
    }
}

long long getMin(int v, int l, int r, int tl, int tr){
    if(l > r){
        return 1e18;
    }
    if(tl == l && tr == r){
        return mn[v];
    }
    else{
        int tm = (tl + tr) / 2;
        push(v, tl, tr, tm);
        return min(getMin(2 * v, l, min(r, tm), tl, tm),
                    getMin(2 * v + 1, max(tm + 1, l), r, tm + 1, tr));
    }
}

long long getMin(int a, int b){
    return getMin(1, a, b, 1, N);
}

long long getSum(int a, int b){
    return getSum(1, a, b, 1, N);
}

void update(int a, int b, int c){
    update(1, a, b, 1, N, c);
}

int main(){
    setIO("haybales");
    cin >> N >> Q;
    for(int i = 1;i <= N; i++){
        int x;
        cin >> x;
        update(i, i, x);
    }
    
    for(int i = 0; i < Q; i++){
        char x;
        cin >> x;
        if(x == 'M'){
            int a, b;
            cin >> a >> b;
            cout << getMin(a, b) << "\n";
        }
        else if(x == 'P'){
            int a, b, c;
            cin >> a >> b >> c;
            update(a, b, c);
        }
        else{
            int a, b;
            cin >> a >> b;
            cout << getSum(a, b) << "\n";
        }
    }




}