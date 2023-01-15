#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct path{
    int a, b, l;
    bool operator < (const path &s1) const{
        return l < s1.l;
    }
};

const int MAXN = 50000;

int N, M, LCA[MAXN][17], depth[MAXN], ans[MAXN], pre[MAXN], sz[MAXN], curr;
vector<pair<int, int> > adj[MAXN];
pair<int, int> par[MAXN];
path paths[MAXN];

void dfs(int i, int p, int d, int in){
    pre[i] = curr++;
    depth[i] = d;
    par[i] = make_pair(p, in);
    LCA[i][0] = p;
    for(auto it:adj[i]) if(it.first != p){
        dfs(it.first, i, d + 1, it.second);
        sz[i] += sz[it.first] + 1;
    }
}

void initLCA(){
    for(int d = 1; d < 17; d++){
        for(int i = 0; i < MAXN; i++){
            LCA[i][d] = LCA[LCA[i][d-1]][d-1];
        }
    }
}

int getLCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int d = 16; d >=0; d--){
        if(depth[a] - (1<<d) >= depth[b]){
            a = LCA[a][d];
        }
    }
    for(int d = 16; d>=0; d--){
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

int main(){
    setIO("disrupt");
    cin >> N >> M;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(make_pair(b - 1, i));
        adj[b - 1].push_back(make_pair(a - 1, i));
        ans[i] = -1;
    }
    dfs(0, 0, 0, -1);
    initLCA();
    for(int i = 0; i < M; i++){
        cin >> paths[i].a >> paths[i].b >> paths[i].l;
        paths[i].a--;
        paths[i].b--;
    }
    sort(paths, paths + M);
    for(int i = 0; i < M; i++){
        int a = paths[i].a;
        int b = paths[i].b;
        int lca = getLCA(a, b);
        while(pre[a] > pre[lca] && pre[a] <= pre[lca] + sz[lca]){
            if(ans[par[a].second] == -1)
                ans[par[a].second] = paths[i].l;
            int prev = a;
            a = par[a].first;
            par[prev].first = lca;
        }
        while(pre[b] > pre[lca] && pre[b] <= pre[lca] + sz[lca]){
            if(ans[par[b].second] == -1)
                ans[par[b].second] = paths[i].l;
            int prev = b;
            b = par[b].first;
            par[prev].first = lca;
        }
    }
    for(int i = 1; i < N; i++){
        cout << ans[i] << "\n";
    }

}