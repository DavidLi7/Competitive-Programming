#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

int N, M, lo[MAXN], disc[MAXN], curr, sz[MAXN], rt[MAXN], in[MAXN], in2[MAXN], dp1[MAXN], dp2[MAXN];
vector<int> adj[MAXN], radj[MAXN], adj2[MAXN], nodes; 
bool onStack[MAXN];
stack<int> s;
set<int> sadj2[MAXN];

void compress(){
    for(int i = 0; i < N; i++){
        for(int v: adj[i]){
            sadj2[rt[i]].insert(rt[v]);
        }
    }
    for(int i = 0; i < N; i++){
        for(int v: sadj2[i]){
            if(v == i)
                continue;
            adj2[i].push_back(v);
            in[v]++;
            radj[v].push_back(i);
            in2[i]++;
        }
    }
}

void dfs(int v){
    disc[v] = lo[v] = ++curr;
    s.push(v);
    onStack[v] = true;
    for(int u: adj[v]){
        if(disc[u] == -1){
            dfs(u);
            lo[v] = min(lo[v], lo[u]);
        }
        else if(onStack[u]){
            lo[v] = min(lo[v], disc[u]);
        }
    }
    int pop = -1;
    if(lo[v] == disc[v]){
        while(pop != v){
            pop = s.top();
            onStack[pop] = false;
            rt[pop] = v;
            sz[v]++;
            s.pop();
        }
        nodes.push_back(v);
    }
}

void getSCC(){
    for(int i = 0; i < N; i++){
        onStack[i] = false;
        lo[i] = disc[i] = -1;
    }
    for(int i = 0; i < N; i++){
        if(disc[i] == -1)
            dfs(i);
    }
}

int main(){
    setIO("grass");
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    getSCC();
    compress();
    for(int i = 0; i < N; i++){
        dp1[i] = dp2[i] = -1;
    }
    dp1[0] = dp2[0] = sz[rt[0]];

    // for(int i: nodes){
    //     cout << i << ": ";
    //     for(int v: adj2[i])
    //         cout << v << " ";
    //     cout << "\n";
    // }


    stack<int> topo;
    for(int i: nodes){
        if(in[i] == 0)
            topo.push(i);
    }
    while(topo.size()){
        int t = topo.top();
        topo.pop();
        for(int v: adj2[t]){
            if(dp1[t] != -1)
                dp1[v] = max(dp1[v], dp1[t] + sz[v]);
            in[v]--;
            if(in[v] == 0)
                topo.push(v);
        }
    }

    for(int i: nodes){
        if(in2[i] == 0)
            topo.push(i);
    }
    while(topo.size()){
        int t = topo.top();
        topo.pop();
        for(int v: radj[t]){
            if(dp2[t] != -1)
                dp2[v] = max(dp2[v], dp2[t] + sz[v]);
            in2[v]--;
            if(in2[v] == 0)
                topo.push(v);
        }
    }

    int ans = 0;
    for(int i: nodes){
        // cout << i + 1 << " " << dp1[i] << " " << dp2[i] << "\n";
        for(int v: adj2[i]){
            if(dp2[i] != -1 && dp1[v] != -1){
                ans = max(ans, dp2[i] + dp1[v]);
            }
        }
    }
    cout << ans - sz[rt[0]];
}