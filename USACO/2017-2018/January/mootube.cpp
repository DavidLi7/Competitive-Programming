#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

int N, Q, par[MAXN], sz[MAXN], ans[MAXN];
pair<int, pair<int, int> > queries[MAXN];
pair<int, pair<int, int> > edges[MAXN];

int find(int p){
    while(p != par[p])
        p = par[p];
    return p;
}

void merge(int p, int q){
    p = find(p);
    q = find(q);
    if(p == q)
        return;
    if(sz[q] > sz[p])
        swap(p, q);
    par[q] = p;
    sz[p] += sz[q];
}

int main(){
    setIO("mootube");
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        sz[i] = 1;
        par[i] = i;
    }
    for(int i = 0; i < N - 1; i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        edges[i].second.first--;
        edges[i].second.second--;
    }
    for(int i = 0; i < Q; i++){
        cin >> queries[i].first >> queries[i].second.first;
        queries[i].second.second = i;
        queries[i].second.first--;
    }
    sort(edges, edges + N - 1);
    sort(queries, queries + Q);
    int j = N - 2;
    for(int i = Q - 1; i >= 0; i--){
        while(j >= 0 && edges[j].first >= queries[i].first){
            merge(edges[j].second.first, edges[j].second.second);
            j--;
        }
        ans[queries[i].second.second] = sz[find(queries[i].second.first)];
    }
    for(int i = 0; i < Q; i++){
        cout << ans[i] - 1 << "\n";
    }
}