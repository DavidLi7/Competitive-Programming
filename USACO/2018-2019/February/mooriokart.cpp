#include <iostream>
#include <vector>
#include <map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1505;
const int MAXY = 2505;
const int MOD = 1e9 + 7;

int N, M, X, Y;
pair<long long, long long> c[MAXY], t[MAXY];
vector<pair<int, int> > adj[MAXN];
vector<long long> dists, el;
bool vis[MAXN];

void dfs1(int i, int p){
    el.push_back(i);
    for(auto it:adj[i]) if(it.first != p){
        dfs1(it.first, i);
    }
    vis[i] = true;
}

void dfs2(int i, int p, int ori, int d){
    for(auto it: adj[i]) if(it.first != p){
        if(ori < it.first){
            dists.push_back(it.second + d);
        }
        dfs2(it.first, i, ori, d + it.second);
    }
}


int main(){
    setIO("mooriokart");

    cin >> N >> M >> X >> Y;
    for(int i = 0; i < M; i++){
        int a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        adj[a].push_back(make_pair(b, d));
        adj[b].push_back(make_pair(a, d));
    }
    int K = N - M;
    long long prod = 1;
    for(int i = 1; i < K; i++){
        prod *= 2;
        prod *= i;
        prod %= MOD;
    }
    c[min(Y, K * X)] = make_pair(K * X, 1);
    for(int i = 0; i < N; i++) if(!vis[i]){
        dists.clear();
        el.clear();
        dfs1(i, -1);
        for(int x: el)
            dfs2(x, -1, x, 0);
        map<int, pair<int, int> >m;
        for(int x: dists){
            m[min(x, Y)].first += x;
            m[min(x, Y)].second++;
            m[min(x, Y)].first %= MOD;
            m[min(x, Y)].second %= MOD;
        }
        for(auto it: m){
            for(int s = 0; s <= Y; s++){
                long long a = c[s].second * it.second.second;
                a %= MOD;
                t[min(it.first + s, Y)].second += a;
                t[min(it.first + s, Y)].second %= MOD;
                a = (c[s].first * it.second.second) % MOD + (c[s].second * it.second.first) % MOD;
                t[min(it.first + s, Y)].first += a;
                t[min(it.first + s, Y)].first %= MOD;
            }
        }
        for(int j = 0; j <= Y; j++){
            c[j] = t[j];
            t[j] = make_pair(0, 0);
        }
    }
    long long ans = c[Y].first * prod;
    ans %= MOD;
    if(ans < 0)
        ans += MOD;
    cout << ans;



}