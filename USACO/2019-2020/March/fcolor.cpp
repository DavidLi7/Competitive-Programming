#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 2e5 + 5;

int N, M, par[MAXN];
vector<int> adj[MAXN];
queue<int> q;

void merge(int a, int b){
    
}

int main(){
    //setIO("fcolor");
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    for(int i = 0; i < N; i++){
        par[i] = i;
        if(adj[i].size() > 1)
            q.push(i);
    }
    while(!q.empty()){
        int x = q.front();
        if(adj[x].size() <= 1){
            q.pop();
            continue;
        }
        int a = adj[x].back();
        adj[x].pop_back();
        merge(a, adj[x].back());
    }

    
    
}