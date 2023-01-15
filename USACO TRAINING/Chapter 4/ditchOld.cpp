/*
ID: divadxl1
LANG: C++
TASK: ditch
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 201;

int N, M, ans, f[MAXN][MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

int dfs(int i, int mn){
    //cout << i << "\n";
    vis[i] = true;
    if(i == M){
        //cout << mn << "end\n";
        ans += mn;
        return mn;
    }
    for(int v: adj[i]) if(!vis[v] && f[i][v] != 0){
        int stop = dfs(v, min(mn, f[i][v]));
        if(stop != 0){
            f[i][v] -= stop;
            f[v][i] += stop;
            return stop;
        }
    }
    return 0;
}

int main(){
    setIO("ditch");
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int s, e, c;
        cin >> s >> e >> c;
        f[s][e] += c;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    while(true){
        for(int i = 1; i <= M; i++){
            vis[i] = false;
        }
        if(dfs(1, 1e9) == 0)
            break;
    }
    cout << ans << "\n";

}