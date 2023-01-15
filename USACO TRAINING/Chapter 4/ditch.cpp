/*
ID: divadxl1
LANG: C++
TASK: ditch
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 205;

struct edge{
    int to, rev;
    long long flow, c;
    edge(int to, int rev, long long flow, long long c) : to(to), rev(rev), flow(flow), c(c){}
};

int N, M, level[MAXN], start[MAXN];
vector<edge> adj[MAXN];

bool findLevels(int s, int t){
    for(int i = 0; i < N; i++){
        level[i] = -1;
    }
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto x: adj[v]){
            if(level[x.to] == -1 && x.flow < x.c){
                level[x.to] = level[v] + 1;
                q.push(x.to);
            }
        }
    }
    return (level[t] != -1);
}

long long sendFlow(int v, long long flow, int t){
    if(v == t)
        return flow;
    for(; start[v] < adj[v].size(); start[v]++){
        edge &e = adj[v][start[v]];
        if(level[e.to] == level[v] + 1 && e.flow < e.c){
            long long currflow = min(flow, e.c - e.flow);
            long long tempflow = sendFlow(e.to, currflow, t);
            if(tempflow > 0){
                e.flow += tempflow;
                adj[e.to][e.rev].flow -= tempflow;
                return tempflow;
            }
        }
    }
    return 0;
}

long long getMaxFlow(int s, int t){
    if(s == t)
        return -1;
    long long ret = 0;
    while(findLevels(s, t)){
        for(int i = 0; i < N; i++){
            start[i] = 0;
        }
        while(long long flow = sendFlow(s, 1e18, t))
            ret += flow;
    }
    return ret;
}

int main(){
    setIO("ditch");
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        int s, e, c;
        cin >> s >> e >> c;
        s--; e--;
        adj[s].push_back(edge(e, adj[e].size(), 0, c));
        adj[e].push_back(edge(s, adj[s].size() - 1, 0, 0));
    }
    cout << getMaxFlow(0, N - 1) << "\n";

}