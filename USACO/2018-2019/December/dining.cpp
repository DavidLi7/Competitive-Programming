#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 50005;

int N, M, K, h[MAXN];
vector<pair<int, int> > adj[MAXN];
long long d1[MAXN], d2[MAXN];

int main(){
    setIO("dining");
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        adj[a].push_back(make_pair(b, t));
        adj[b].push_back(make_pair(a, t));
    }
    for(int i = 0; i < K; i++){
        int a, y;
        cin >> a >> y;
        a--;
        h[a] = y;
    }
    for(int i = 0; i < N; i++){
        d1[i] = -1;
        d2[i] = -1;
    }
    //pair<int, int>
    priority_queue<pair<int, int> >PQ;
    PQ.push(make_pair(0, N - 1));
    while(!PQ.empty()){
        pair<int, int> temp = PQ.top();
        PQ.pop();
        if(d1[temp.second] != -1)
            continue;
        d1[temp.second] = -temp.first;
        for(auto it: adj[temp.second]) if(d1[it.first] == -1){
            PQ.push(make_pair(temp.first - it.second, it.first));
        }
    }
    for(int i = 0; i < N; i++){
        if(h[i] != 0)
            PQ.push(make_pair(-d1[i] + h[i], i));
    }
    while(!PQ.empty()){
        pair<int, int> temp = PQ.top();
        PQ.pop();
        if(d2[temp.second] != -1)
            continue;
        d2[temp.second] = -temp.first;
        for(auto it: adj[temp.second]) if(d2[it.first] == -1){
            PQ.push(make_pair(temp.first - it.second, it.first));
        }
    }
    for(int i = 0; i < N - 1; i++){
        // cout << d1[i] << " " << d2[i] << "\n";
        cout << (d2[i] <= d1[i]) << "\n";
    }
}