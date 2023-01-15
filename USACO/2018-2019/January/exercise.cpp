#include <iostream>
#include <vector>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 2e5 + 5;
const int MAXD = 18;

int N, M, LCA[MAXN][MAXD], depth[MAXN];
vector<int> adj1[MAXN], ed[MAXN];
pair<int, int> edges[MAXN];

void dfs(int i, int p){
    for(int v: adj1[i]) if(v != p){
        depth[v] = depth[i] + 1;
        LCA[v][0] = i;
        dfs(v, i);
    }
}

void initLCA(){
    for(int d = 1; d < MAXD; d++){
        for(int i = 0; i < N; i++){
            LCA[i][d] = LCA[LCA[i][d - 1]][d - 1];
        }
    }
}

int getLCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int d = MAXD - 1; d >= 0; d--){
        if(depth[a] - (1 << d) >= depth[b])
            a = LCA[a][d];
    }
    for(int d = MAXD - 1; d >= 0; d--){
        if(LCA[a][d] != LCA[b][d]){
            a = LCA[a][d];
            b = LCA[b][d];
        }
    }
    if(a != b)
        a = LCA[a][0];
    return a;
}

int main(){
    //setIO("exercise");
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(i < N - 1){
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
        else{
            edges[i - (N - 1)] = make_pair(a, b);
            ed[a].push_back(i - (N - 1));
            ed[b].push_back(i - (N - 1));
        }
    }
    dfs(0, -1);
    initLCA();
    M -= (N - 1);
    int ans = 0;
    for(int i = 0; i < M; i++){
        set<int> nums;
        int a = edges[i].first;
        int b = edges[i].second;
        int lca = getLCA(a, b);
    }
    cout << ans;
}