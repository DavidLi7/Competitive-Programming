#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

int N, Q, x[MAXN], y[MAXN], mn[4 * MAXN], s[4 * MAXN];

void upd1(int v, int tl, int tr, int x, int newval){
    if(tl == tr){
        s[v] = newval;
    }
    else{
        int tm = (tl + tr) / 2;
        if(x <= tm)
            upd1(2 * v, tl, tm, x, newval);
        else
            upd1(2 * v + 1, tm + 1, tr, x, newval);
        s[v] = s[2 * v] + s[2 * v + 1];
    }
}

void upd2(int v, int tl, int tr, int x, int newval){
    if(tl == tr){
        mn[v] = newval;
    }
    else{
        int tm = (tl + tr) / 2;
        if(x <= tm)
            upd2(2 * v, tl, tm, x, newval);
        else
            upd2(2 * v + 1, tm + 1, tr, x, newval);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }
}

int getSum(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(tl == l && r == tr){
        return s[v];
    }
    int tm = (tl + tr) / 2;
    return getSum(2 * v, tl, tm, l, min(r, tm)) + 
        getSum(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
}

int getMn(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 1e9;
    if(tl == l && r == tr){
        return mn[v];
    }
    int tm = (tl + tr) / 2;
    return min(getMn(2 * v, tl, tm, l, min(r, tm)),
        getMn(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

int dist(int a, int b){
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

int main(){
    setIO("marathon");
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i < N; i++){
        upd1(1, 1, N - 1, i, dist(i, i - 1));
    }
    for(int i = 1; i < N - 1; i++){
        upd2(1, 1, N - 2, i, dist(i - 1, i + 1) - dist(i, i - 1) - dist(i, i + 1));
    }
    // cout << getSum(1, 1, N - 1, 1, N - 1) << "h\n";
    // cout << getMn(1, 1, N - 2, 1, N - 2) << "h\n";
    for(int j = 0; j < Q; j++){
        char type;
        cin >> type;
        if(type == 'Q'){
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << getSum(1, 1, N - 1, a + 1, b) + getMn(1, 1, N - 2, a + 1, b - 1) << "\n";
            // cout << getSum(1, 1, N - 1, a + 1, b) << " " << getMn(1, 1, N - 2, a + 1, b - 1) << "u\n";
        }
        else{
            int a, nx, ny;
            cin >> a >> nx >> ny;
            a--;
            x[a] = nx;
            y[a] = ny;
            if(a != 0)
                upd1(1, 1, N - 1, a, dist(a, a - 1));
            if(a != N - 1)
                upd1(1, 1, N - 1, a + 1, dist(a, a + 1));
            if(a != 0 && a != N - 1){
                upd2(1, 1, N - 2, a, dist(a - 1, a + 1) - dist(a, a - 1) - dist(a, a + 1));
            }
            if(a != N - 1 && a != N - 2){
                upd2(1, 1, N - 2, a + 1, dist(a, a + 2) - dist(a + 1, a) - dist(a + 1, a + 2));
            }
            if(a != 0 && a != 1){
                upd2(1, 1, N - 2, a - 1, dist(a - 2, a) - dist(a - 1, a - 2) - dist(a - 1, a));
            }
        }
    }
}