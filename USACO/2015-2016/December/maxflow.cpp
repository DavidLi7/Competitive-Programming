#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 50000;

int N, K, LCA[MAXN][17], depth[MAXN], pre[MAXN], ans, lc[MAXN];
vector<int> adj[MAXN];

void dfs(int i, int p, int d){
    depth[i] = d;
    LCA[i][0] = p;
    for(int v: adj[i]) if(v != p){
        dfs(v, i, d + 1);
    }
}

void initLCA(){
    for(int d = 1; d < 17; d++){
        for(int i = 0; i < N; i++){
            LCA[i][d] = LCA[LCA[i][d-1]][d-1];
        }
    }
}

int getLCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    for(int d = 16; d >= 0; d--){
        if(depth[a] - (1<<d) >= depth[b])
            a = LCA[a][d];
    }
    for(int d = 16; d >=0; d--){
        if(LCA[a][d] != LCA[b][d]){
            a = LCA[a][d];
            b = LCA[b][d];
        }
    }
    if(a != b){
        a = LCA[a][0];
    }
    return a;
}

void dfs2(int i, int p){
    for(int v: adj[i]) if(v != p){
        dfs2(v, i);
        pre[i] += pre[v];
        pre[i] -= lc[v];
    }
    ans = max(ans,  pre[i]);
}

int main(){
    setIO("maxflow");
    cin >> N >> K;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    dfs(0, 0, 0);
    initLCA();
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        int lca = getLCA(a, b);
        lc[lca]++;
        pre[a]++;
        pre[b]++;
        pre[lca]--;
    }
    dfs2(0, 0);
    //for(int i = 0; i < N; i++){
    //   cout << pre[i]<<endl;;
    //}
    cout << ans;



}