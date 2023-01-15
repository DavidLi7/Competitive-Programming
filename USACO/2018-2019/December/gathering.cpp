#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;

stack<int>topo;
set<int>el, el2;
vector<int> adj[MAXN], res[MAXN];
int N, M, curr, pre[MAXN], BIT[MAXN + 5], sz[MAXN], par[MAXN], in[MAXN];

void dfs(int i, int p){
    pre[i] = curr++;
    par[i] = p;
    for(int v: adj[i]) if(v != p){
        dfs(v, i);
        sz[i] += sz[v] + 1;
    }
}

void upd(int i, int c){
    i++;
    while(i < N + 5){
        BIT[i] += c;
        i += i & -i;
    }
}

int get(int i){
    i++;
    int ret = 0;
    while(i > 0){
        ret += BIT[i];
        i -= i & -i;
    }
    return ret;
}

int main(){
    setIO("gathering");
    cin >> N >> M;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        in[b]++;
        res[a].push_back(b);
        el.insert(a);
        el.insert(b);
        if(pre[b] <= pre[a] + sz[a] && pre[b] >= pre[a]){
            for(int v: adj[a]) if(v != par[a]){
                if(pre[b] >= pre[v] && pre[b] <= pre[v] + sz[v]){
                    upd(0, 1);
                    upd(pre[v], -1);
                    upd(pre[v] + sz[v] + 1, 1);
                    break;
                }
            }
        }
        else{
            upd(pre[a], 1);
            upd(pre[a] + sz[a] + 1, -1);
        }
    }
    for(int i = 0; i < N; i++){
        if(in[i] == 0 && el.find(i) != el.end()){
            topo.push(i);
        }
    }
    while(!topo.empty()){
        int i = topo.top();
        topo.pop();
        el2.insert(i);
        for(int v: res[i]){
            in[v]--;
            if(!in[v]){
                topo.push(v);
            }
        }
    }
    if(el.size() != el2.size()){
        upd(0, 1);
    }
    
    for(int i = 0; i < N; i++){
        cout << !get(pre[i])<< "\n";
    }

}