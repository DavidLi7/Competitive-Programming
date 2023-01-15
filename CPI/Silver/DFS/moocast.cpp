#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1005;

int N, par[MAXN], sz[MAXN], x[MAXN], y[MAXN];
vector<pair<int, pair<int, int> > > edges;  //a.first = length. a.second = edge. a.second.first = one node in the edge, a.second.second = other node

int d(int i, int j){
    return (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) *(y[j] - y[i]);
}

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
        sz[p] += sz[q];
        par[q] = par[p];
    }
    else{
        sz[q] += sz[p];
        par[p] = par[q];
    }
    return true;
}

int main(){

    setIO("moocast");

    cin >> N;
    for(int i = 0; i < N; i++){
        par[i] = i;
        sz[i] = 1;
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            edges.push_back(make_pair(d(i, j), make_pair(i, j)));
        }
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    int numComponents = N;
    for(auto it: edges){
        if(merge(it.second.first, it.second.second)){
            ans = it.first;
            if(--numComponents == 1)
                break;
        }
    }
    cout << ans;

}