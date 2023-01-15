#include "grader.h"
#include <vector>

using namespace std;

const int MAXN = 1e5;

int N, Q, sz[MAXN], LCA[MAXN][18], depth[MAXN], x[MAXN], y[MAXN];
vector<int> adj[MAXN];

void dfs(int i, int p){
    sz[i]++;
    for(int v: adj[i]) if(v != p){
        depth[v] = depth[i]+1;
        dfs(v, i);
        sz[i] += sz[v];
        LCA[v][0] = i;
    }
}

void initLCA(){
    for(int d = 1; d < 17; d++){
        for(int i = 0; i < MAXN; i++){
            LCA[i][d] = LCA[LCA[i][d-1]][d-1];
        }
    }
}

int getLCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int d = 16; d >=0; d--){
        if(depth[a] - (1<<d) >= depth[b]){
            a = LCA[a][d];
        }
    }
    for(int d = 16; d>=0; d--){
        if(LCA[a][d] != LCA[b][d]){
            a = LCA[a][d];
            b = LCA[b][d];
        }
    }
    if(a != b){
        a = LCA[a][0];
    }
    return a;

}

void build(int i, int p, int x1, int y1, int x2, int y2){
    x[i] = x1;
    y[i] = y1;
    setFarmLocation(i, x1++, y1++);
    for(int v: adj[i]) if(v != p){
        build(v, i, x1, y2 - sz[v] + 1, x1 + sz[v] - 1, y2);
        x1 += sz[v];
        y2 -= sz[v];
    }
}
void addRoad(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
	// Fill in code here
}

void buildFarms(){
    N = getN();
    dfs(0, -1);
    initLCA();
    build(0, -1, 1, 1, N, N);
	// Fill in code here
}

void notifyFJ(int a, int b){
    int lca = getLCA(a, b);
    addBox(x[lca], y[lca], x[a], y[a]);
    if(b == lca)
        return;
    int ogb = b;
    for(int i = 17; i >= 0; i--){
        if(depth[b] - (1 << i) > depth[lca])
            b = LCA[b][i];
    }
    addBox(x[b], y[b], x[ogb], y[ogb]);
}