#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e4 + 5;

int N, p[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int i){
    vis[i] = true;
    for(int v: adj[i]) if(!vis[v]){
        dfs(v);
    }
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans;



}