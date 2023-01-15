/*
ID: divadxl1
LANG: C++
TASK: stall4
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

const int MAXN = 402;

int N, M, ans, f[MAXN][MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

int dfs(int i, int mn){
    //cout << i << "\n";
    vis[i] = true;
    if(i == 401){
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
    setIO("stall4");
    cin >> N >> M;
    //0 is s, 401 is t
    for(int i = 1; i <= N; i++){
        adj[0].push_back(i);
        adj[i].push_back(0);
        f[0][i] = 1;
        int S;
        cin >> S;
        for(int j = 0; j < S; j++){
            int x;
            cin >> x;
            adj[i].push_back(200 + x);
            adj[200 + x].push_back(i);
            f[i][200 + x] = 1;
        }
    }
    for(int i = 1; i <= M; i++){
        adj[200 + i].push_back(401);
        adj[401].push_back(200 + i);
        f[200 + i][401] = 1;
    }
    while(true){
        for(int i = 0; i <= 401; i++){
            vis[i] = false;
        }
        if(dfs(0, 1) == 0)
            break;
    }
    cout << ans << "\n";

}