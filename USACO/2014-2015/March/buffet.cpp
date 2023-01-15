#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1005;

int N, E, Q[MAXN], d[MAXN];
vector<int> adj[MAXN];
pair<int, int> nums[MAXN];//Q[i], index
bool vis[MAXN];

int main(){
    setIO("buffet");
    cin >> N >> E;
    for(int i = 0; i < N; i++){
        int d;
        cin >> Q[i] >> d;
        nums[i] = make_pair(Q[i], i);
        for(int j = 0; j < d; j++){
            int x;
            cin >> x;
            x--;
            adj[i].push_back(x);
        }
    }
    sort(nums, nums + N);
    for(int t = 0; t < N; t++){
        for(int i = 0; i < N; i++){
            vis[i] = false;
        }
        int j = t;
        queue<pair<int, int> > bfs;//steps, node
        while(j < N && nums[j].first == nums[t].first){
            int i = nums[t].second;
            d[i] += Q[i];
            vis[i] = true;
            bfs.push(make_pair(1, i));
            j++;
        }
        while(bfs.size()){
            pair<int, int> temp = bfs.front();
            bfs.pop();
            for(int v: adj[temp.second]){
                if(!vis[v]){
                    vis[v] = true;
                    d[v] = max(d[v], d[nums[t].second] - E * temp.first);
                    bfs.push(make_pair(temp.first + 1, v));
                }
            }
        }
        t = j - 1;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, d[i]);
    }
    cout << ans;


}