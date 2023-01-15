/*
ID: divadxl1
LANG: C++
TASK: stall4
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

const int MAXN = 405;

struct edge{
    int to, rev;
    long long flow, c;
    edge(int to, int rev, long long flow, long long c) : to(to), rev(rev), flow(flow), c(c){}
};

int N, M, level[MAXN], start[MAXN], nodeCount;
vector<edge> adj[MAXN];

void addEdge(int s, int e, int c){
    adj[s].push_back(edge(e, adj[e].size(), 0, c));
    adj[e].push_back(edge(s, adj[s].size() - 1, 0, 0));
}

bool findLevels(int s, int t){
    for(int i = 0; i < nodeCount; i++){
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
        // cout << ret << "\n";
        for(int i = 0; i < nodeCount; i++){
            start[i] = 0;
        }
        while(long long flow = sendFlow(s, 1e18, t))
            ret += flow;
    }
    return ret;
}

int main(){
    setIO("stall4");
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        int amt;
        cin >> amt;
        for(int j = 0; j < amt; j++){
            int e;
            cin >> e;
            e += N;
            addEdge(i, e, 1);
        }
    }
    for(int i = 1; i <= N; i++){
        addEdge(0, i, 1);
    }
    for(int i = 1; i <= M; i++){
        addEdge(N + i, N + M + 1, 1);
    }
    nodeCount = N + M + 2;
    cout << getMaxFlow(0, N + M + 1) << "\n";
    // for(int i = 0; i <= N + M + 1; i++){
    //     cout << i << ":";
    //     for(auto x: adj[i]) if(x.c == 1)
    //         cout << x.to << ", ";
    //     cout << "\n";
    // }

}