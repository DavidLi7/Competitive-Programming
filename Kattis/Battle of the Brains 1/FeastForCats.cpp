#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2005;

int T, M, N, par[MAXN], sz[MAXN];
//long long D[MAXN], dist[MAXN][MAXN];
bool vis[MAXN];
vector<pair<long long, pair<int, int> > > edges;

/*long long prims(){
    for(int i = 1; i <= N; i++){
        D[i] = 1e18;
        vis[i] = false;
    }
    D[1] = 0;
    long long ret = 0;
    for(int it = 0; it < N; it++){
        int mini = 0;
        for(int i = 1; i <= N; i++){
            if(!vis[i] && (mini == 0 || D[i] < D[mini]))
                mini = i;
        }
        vis[mini] = true;
        for(int i = 1; i <= N; i++){
            if(!vis[i]){
                //if(D[mini] + dist[mini][i] < D[i]){
                //    D[i] = D[mini] + dist[mini][i];
                //}
                D[i] = min(D[i], dist[mini][i]);
            }
        }
        ret += D[mini];
    }
    return ret;
}*/

int find(int p){
    while(p != par[p])
        p = par[p];
    return p;
}

bool merge(int p, int q){
    p = find(p);
    q = find(q);
    if(p == q)
        return false;
    if(sz[p] < sz[q]){
        sz[q] += sz[p];
        par[p] = par[q];
    }
    else{
        sz[p] += sz[q];
        par[q] = par[p];
    }
    return true;
}

long long kruskal(){
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= N; i++){
        par[i] = i;
        sz[i] = 1;
    }
    long long ans = 0;
    for(auto it: edges){
        if(merge(it.second.second, it.second.first))
            ans += it.first;
    }
    return ans;
}

void solve(){
    cin >> M >> N;
    int tot = N * (N - 1) / 2;
    edges.clear();
    for(int i = 0; i < tot; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a++;
        b++;
        /*dist[a][b] = c;
        dist[b][a] = c;*/
        edges.push_back(make_pair(c, make_pair(a, b)));
    }
    long long ans = kruskal() + N;
    if(ans <= M)
        cout << "yes\n";
    else{
        cout << "no\n";
    }
    //cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    //setIO("");
    cin >> T;
    while(T--){
        solve();
    }
}