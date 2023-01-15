#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100005;

int N, M, T, s, t, K;
long long dist[MAXN], lo, hi;
bool spider[MAXN], vis[MAXN];
vector<pair<int, long long> > adj[MAXN];
vector<int> spid;

void findDists(){
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > PQ;
    for(int x: spid){
        PQ.push(make_pair(0, x));
    }
    while(!PQ.empty()){
        pair<long long, int> temp = PQ.top();
        PQ.pop();
        if(dist[temp.second] != -1)
            continue;
        dist[temp.second] = temp.first;
        for(auto it: adj[temp.second]) if(dist[it.first] == -1){
            PQ.push(make_pair(it.second + temp.first, it.first));
        }
        hi = max(hi, temp.first);
    }
}

bool ok(int D){
    for(int i = 0; i < N; i++){
        if(dist[i] >= D){
            vis[i] = false;
        }
        else{
            vis[i] = true;
        }
    }
    if(vis[s] || vis[t])
        return false;
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > PQ;
    PQ.push(make_pair(0, s));
    while(!PQ.empty()){
        pair<long long, int> temp = PQ.top();
        PQ.pop();
        if(vis[temp.second])
            continue;
        if(temp.second == t){
            return temp.first <= T;
        }
        vis[temp.second] = true;
        for(auto it: adj[temp.second]) if(!vis[it.first]){
            PQ.push(make_pair(it.second + temp.first, it.first));
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> T;
    for(int i = 0; i < N; i++){
        dist[i] = -1;
    }
    for(int i = 0; i < M; i++){
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back(make_pair(v, d));
        adj[v].push_back(make_pair(u, d));
    }
    cin >> s >> t >> K;
    spid.resize(K);
    for(int i = 0; i < K; i++){
        cin >> spid[i];
        spider[spid[i]] = true;
    }
    findDists();
    /*cout << "\n";
    for(int i = 0; i < N; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";*/
    hi++;
    //cout << lo << " " << hi << "\n";
    while(lo < hi - 1){
        long long mid = (lo + hi) / 2;
        if(ok(mid)){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    cout << lo;
}