/*
ID: divadxl1
LANG: C++
TASK: race3
*/
#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 51;

int N;
vector<int> adj[MAXN];
bool vis[MAXN], vis2[MAXN];

void dfs(int loc){
    vis[loc] = true;
    for(int v: adj[loc]) if(!vis[v]){
        dfs(v);
    }
}

void dfs2(int loc){
    vis2[loc] = true;
    for(int v: adj[loc]) if(!vis2[v]){
        dfs2(v);
    }
}

int main(){
    setIO("race3");
    int x;
    cin >> x;
    while(x != -1){
        while(x != -2){
            adj[N].push_back(x);
            cin >> x;
        }
        cin >> x;
        N++;
    }
    vector<int> unavoid;
    vector<int> split;
    for(int i = 1; i < N - 1; i++){
        for(int j = 0; j < N; j++){
            vis[j] = false;
            vis2[j] = false;
        }
        vis[i] = true;
        dfs(0);
        if(!vis[N - 1]){
            unavoid.push_back(i);
            vis[i] = false;
            dfs2(i);
            bool ok = true;
            for(int j = 0; j < N; j++){
                if(vis[j] && vis2[j]){
                    ok = false;
                }
            }
            if(ok) split.push_back(i);
        }
    }
    cout << unavoid.size();
    for(int x: unavoid){
        cout << " " << x;
    }
    cout << "\n";
    cout << split.size();
    for(int x: split){
        cout << " " << x;
    }
    cout << "\n";
}