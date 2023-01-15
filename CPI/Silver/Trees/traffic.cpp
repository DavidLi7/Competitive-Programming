#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005;

vector<int> adj[MAXN];
long long sz[MAXN], ans[MAXN], tot;

void dfs(int i, int p = -1){
    for(int v: adj[i]) if(v != p){
        dfs(v, i);
        sz[i] += sz[v];
        ans[i] = max(ans[i], sz[v]);
    }
    ans[i] = max(ans[i], tot - sz[i]);
}

int LocateCentre(int N, int P[], int S[], int D[]){
    for(int i = 0; i < N; i++){
        sz[i] = P[i];
        tot += sz[i];
        if(i != N - 1){
            adj[S[i]].push_back(D[i]);
            adj[D[i]].push_back(S[i]);
        }
    }

    int mxi = 0;
    for(int i = 1; i < N; i++){
        if(ans[i] < ans[mxi]){
            mxi = i;
        }
    }
    return mxi;
}