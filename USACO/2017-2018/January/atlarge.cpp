#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5 + 5;

int N, K, d[MAXN], ans;
vector<int> adj[MAXN];

void dfs(int i, int p){
    d[i] = 1e9;
    for(int v: adj[i]) if(v != p){
        dfs(v, i);
        d[i] = min(d[i], d[v] + 1);
    }
    if(adj[i].size() == 1 && adj[i][0] == p)
        d[i] = 0;
}

void dfs2(int i, int p, int dist){
    if(dist >= d[i]){
        ans++;
        return;
    }
    for(int v: adj[i]) if(v != p){
        dfs2(v, i, dist + 1);
    }
}

int main(){
    setIO("atlarge");
    cin >> N >> K;
    K--;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(K, -1);
    dfs2(K, -1, 0);
    cout << ans;
}