/*
ID: divadxl1
LANG: C++
TASK: milk6
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct edge{
    long long a, b, c;
    edge(long long A, long long B, long long C) : a(A), b(B), c(C) {}
};

const int MAXN = 33;

long long N, M, level[MAXN], pt[MAXN], edges;
long long c[MAXN][MAXN], c2[MAXN][MAXN], flow;
vector<int> adj[MAXN];
queue<int> q;
vector<edge> Edges;

bool bfs(){
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u: adj[v]){
            if(c[v][u] == 0 || level[u] != -1)
                continue;
            level[u] = level[v] + 1;
            q.push(u);
        }
    }
    return level[N] != -1;
}

long long dfs(int v, long long push){
    if(push == 0)   
        return 0;
    if(v == N)
        return push;
    for(; pt[v] < adj[v].size(); pt[v]++){
        int u = adj[v][pt[v]];
        if(level[v] + 1 != level[u] || c[v][u] == 0)
            continue;
        long long temp = dfs(u, min(push, c[v][u]));
        if(temp == 0)
            continue;
        c[v][u] -= temp;
        c[u][v] += temp;
        return temp;
    }
    return 0;
}

long long getFlow(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            c[i][j] = c2[i][j];
        }
    }
    long long f = 0;
    while(true){
        for(int i = 1; i <= N; i++){
            level[i] = -1;
            pt[i] = 0;
        }
        level[1] = 0;
        q.push(1);
        if(!bfs()) 
            break;
        while(long long push = dfs(1, 1e18)){
            f += push;
        }
    }
    return f;
}

vector<int> minCut(){
    long long f = getFlow();
    vector<int> ans;
    for(int i = 0; i < M; i++){
        c2[Edges[i].a][Edges[i].b] -= Edges[i].c;
        long long newf = getFlow();
        if(f - newf == Edges[i].c){
            ans.push_back(i + 1);
            f = newf;
        }
        else{
            c2[Edges[i].a][Edges[i].b] += Edges[i].c;
        }
    }
    return ans;
}

int main(){
    setIO("milk6");
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        long long s, e, cost;
        cin >> s >> e >> cost;
        cost *= 10000;
        cost++;
        Edges.push_back(edge(s, e, cost));
        c2[s][e] += cost;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    long long flow = getFlow();
    edges = flow % 10000;
    flow /= 10000;
    cout << flow << " " << edges << "\n";
    vector<int> ans = minCut();
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }

}