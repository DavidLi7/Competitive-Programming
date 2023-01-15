#include <iostream>

using namespace std;

const int MAXN = 1005;
const int MOD = 1e9 + 7;

bool grid[MAXN][MAXN];
int N, M, par[MAXN*MAXN], sz[MAXN*MAXN], h[MAXN*MAXN];
long long c[MAXN*MAXN];

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int find(int p){
    while(p != par[p])
        p = par[p];
    return p;
}

void merge(int p, int q, int l){
    p = find(p);
    q = find(q);
    if(p==q)
        return;
    if(sz[p] < sz[q]){
        par[p] = q;
        sz[q] += sz[p];
        h[q] = l;
    }
    else{
        par[q] = p;
        sz[p] += sz[q];
        h[p] = l;
    }
}
void vmerge(int p, int q, int l){
    p = find(p);
    q = find(q);
    if(p == q)
        return;
    long long prod = 1LL*c[p] * (c[q] + 1LL);
    prod %= MOD;
    if(sz[p] < sz[q]){
        par[p] = q;
        sz[q] += sz[p];
        
        if(l < h[q]){
            c[q] = prod;
            h[q] = l;
        }
        else{
            prod = 1LL*c[p]*c[q];
            prod %= MOD;
            c[q] = prod;
        }
    }
    else{
        par[q] = p;
        sz[p] += sz[q];
        
        if(l < h[q]){
            c[p] = prod;
            h[p] = l;
        }
        else{
            prod = 1LL*c[p]*c[q];
            prod %= MOD;
            c[p] = prod;
        }
    }
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
    setIO("cave");
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0;j < M; j++){
            par[M * i + j] = M * i + j;
            sz[M * i + j] = 1;
            c[M * i + j] = 1LL;
            h[M * i + j] = i;
            char x;
            cin >> x;
            grid[i][j] = x == '.';
        }
    }
    
    for(int i = N - 2; i > 0; i--){
        for(int j = 1; j < M - 1; j++) if(grid[i][j]){
            if(grid[i][j + 1])
                merge(M * i + j, M * i + j + 1, i);
            if(grid[i + 1][j]){
                vmerge(M * i + j, M * (i + 1) + j, i);
            }
        }
    }
    long long ans = 1LL;
    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < M - 1; j++) if(grid[i][j]){
            int k = M * i + j;
            int p = par[k];
            if(k == p){
                ans *= 1LL*(c[p] + 1LL);
                ans %= MOD;
            }
        }
    }
    cout << ans;
}
