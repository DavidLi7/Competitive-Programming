#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

int T, N, a, b;
vector<pair<int, int> > adj[MAXN];
set<int> A;
bool ok;

void dfs1(int v, int p, int x){
    if(x == 0 && v == b){
        ok = true;
        //cout << v << " " << p << " " << x << " 1\n";
    }
    if(v == b)
        return;
    A.insert(x);
    for(pair<int, int> u : adj[v]) if(u.first != p){
        dfs1(u.first, v, x ^ u.second);
    }
}

void dfs2(int v, int p, int x){
    if(v != b && A.find(x) != A.end()){
        ok = true;
        //cout << x << " " << p << " " << x << " 2\n";
    }
    for(pair<int, int> u : adj[v]) if(u.first != p){
        dfs2(u.first, v, x ^ u.second);
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        ok = false;
        cin >> N >> a >> b;
        a--; b--;
        for(int i = 0; i < N; i++){
            adj[i].clear();
        }
        A.clear();
        for(int i = 1; i < N; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        dfs1(a, -1, 0);
        dfs2(b, -1, 0);
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
