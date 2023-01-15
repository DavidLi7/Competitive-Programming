#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1005;

int N, M;
vector<pair<int, int> > adj[MAXN];
pair<pair<int, int>, int > edges[MAXN];
map<int, vector<int> > ind;
bool vis[MAXN];

int main(){
    setIO("pump");
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        edges[i].first.first--;
        edges[i].first.second--;
        int f;
        cin >> f;
        ind[1e6 * f].push_back(i);
    }
    int ans = 0;
    for(map<int, vector<int> >::iterator it = ind.end(); it != ind.begin(); it--){
        pair<int, vector<int> > temp = *prev(it);
        for(int x: temp.second){
            adj[edges[x].first.first].push_back(make_pair(edges[x].first.second, edges[x].second));
            adj[edges[x].first.second].push_back(make_pair(edges[x].first.first, edges[x].second));
        }
        for(int i = 0; i < N; i++){
            vis[i] = false;
        }
        priority_queue<pair<int, int> >PQ;
        PQ.push(make_pair(0, 0));
        while(!PQ.empty()){
            pair<int, int> t = PQ.top();
            PQ.pop();
            if(t.second == N - 1){
                ans = max(ans, -temp.first / t.first);
                break;
            }
            if(vis[t.second])
                continue;
            vis[t.second] = true;
            for(auto it: adj[t.second]){
                if(!vis[it.first]){
                    PQ.push(make_pair(t.first - it.second, it.first));
                }
            }
        }
    }
    cout << ans;

}