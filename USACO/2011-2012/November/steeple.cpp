#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 255;

struct obstacle{
    int x1, y1, x2, y2, l;
    obstacle(int x1, int y1, int x2, int y2, int l) : x1(x1), y1(y1), x2(x2), y2(y2), l(l) {}
};

struct edge{
    int to, rev;
    long long flow, c;
    edge(int to, int rev, long long flow, long long c) : to(to), rev(rev), flow(flow), c(c){}
};

int N, level[MAXN], start[MAXN], sz;
vector<edge> adj[MAXN];
vector<obstacle> vert, hori;

void addEdge(int s, int e, long long c){
    adj[s].push_back(edge(e, adj[e].size(), 0, c));
    adj[e].push_back(edge(s, adj[s].size() - 1, 0, 0));
}
 
bool findLevels(int s, int t){
    for(int i = 0; i < sz; i++){
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
        for(int i = 0; i < sz; i++){
            start[i] = 0;
        }
        while(long long flow = sendFlow(s, 1e18, t))
            ret += flow;
    }
    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int x1, y1, x2, y2, l;
        cin >> x1 >> y1 >> x2 >> y2 >> l;
        if(x1 > x2)
            swap(x1, x2);
        if(y1 > y2)
            swap(y1, y2);
        if(y1 == y2){
            hori.push_back(obstacle(x1, y1, x2, y2, l));
        }
        else{
            vert.push_back(obstacle(x1, y1, x2, y2, l));
        }
    }
    sz = N + 2;
    for(int i = 0; i < hori.size(); i++){
        addEdge(0, i + 1, hori[i].l);
    }
    for(int i = 0; i < vert.size(); i++){
        addEdge(i + hori.size() + 1, N + 1, hori[i].l);
    }
    for(int i = 0; i < hori.size(); i++){
        for(int j = 0; j < vert.size(); j++){
            if(hori[i].x1 <= vert[j].x1 && hori[i].x2 >= vert[j].x1 && vert[j].y1 <= hori[i].y1 && vert[j].y2 >= hori[i].y1){
                addEdge(i + 1, j + hori.size() + 1, 1e18);
            }
        }
    }
    cout << N - getMaxFlow(0, N + 1);
}