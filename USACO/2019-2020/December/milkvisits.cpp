#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5 + 5;
const int MAXD = 18;

int N, M, T[MAXN], depth[MAXN], pre[MAXN], sz[MAXN], curr, LCA[MAXN][MAXD];
vector<int> adj[MAXN];
vector<pair<int, pair<int, int> > > queries[MAXN];
vector<int> s[MAXN];
bool ans[MAXN];

int getLCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = MAXD - 1; i >= 0; i--){
        if(depth[a] - (1 << i) >=  depth[b])
            a = LCA[a][i];
    }
    for(int i = MAXD - 1; i >= 0; i--){
        if(LCA[a][i] != LCA[b][i]){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    if(a != b)
        a = LCA[a][0];
    return a;
}

void initLCA(){
    for(int d = 1; d < MAXD; d++){
        for(int i = 0; i < N; i++){
            LCA[i][d] = LCA[LCA[i][d - 1]][d - 1];
        }
    }
}

void dfs(int i, int p){
    sz[i]++;
    pre[i] = curr++;
    for(int v: adj[i]) if(v != p){
        LCA[v][0] = i;
        depth[v] = depth[i] + 1;
        dfs(v, i);
        sz[i] += sz[v];
    }
}

void solve(int i, int p){
    s[T[i]].push_back(i);
    for(auto it: queries[i]){
        int a = i;
        int b = it.second.first;
        int c = it.second.second;
        int lca = getLCA(a, b);
        if(s[c].size() == 0)
            continue;
        int idx = s[c].back();
        if(pre[idx] >= pre[lca] && pre[idx] < pre[lca] + sz[lca])
            ans[it.first] = true;
        // cout << a << " " << b << " " << c << " " << lca << " " << idx << "\n";
    }
    for(int v: adj[i]) if(v != p)
        solve(v, i);
    s[T[i]].pop_back();
}

int main(){
    setIO("milkvisits");
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> T[i];
    }
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    initLCA();
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        queries[a].push_back(make_pair(i, make_pair(b, c)));
        queries[b].push_back(make_pair(i, make_pair(a, c)));
    }
    solve(0, -1);
    for(int i = 0; i < M; i++){
        cout << ans[i];
    }
}