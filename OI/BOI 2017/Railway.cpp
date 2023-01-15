#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXD = 18;

int N, M, K, LCA[MAXN][MAXD], depth[MAXN];
vector<pair<int, int> > adj[MAXN];
vector<int> add[MAXN], sub[MAXN], ans;

void dfs(int i, int p){
    for(auto it: adj[i]) if(it.first != p){
        depth[it.first] = depth[i] + 1;
        LCA[it.first][0] = i;
        dfs(it.first, i);
    }
}

set<int> dfs2(int i, int p, int from){
    set<int> curr;
    for(auto it: adj[i]) if(it.first != p){
        set<int> temp = dfs2(it.first, i, it.second);
        if(temp.size() > curr.size())
            swap(temp, curr);
        curr.insert(temp.begin(), temp.end());
    }
    for(int x: add[i]){
        curr.insert(x);
    }
    for(int x: sub[i]){
        curr.erase(x);
    }
    if((int)curr.size() >= K){
        if(from != 0)
            ans.push_back(from);
    }
    return curr;
}

void initLCA(){
    for(int d = 1; d < MAXD; d++){
        for(int i = 1; i <= N; i++){
            LCA[i][d] = LCA[LCA[i][d - 1]][d - 1];
        }
    }
}

int getLCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int d = MAXD - 1; d >= 0; d--){
        if(depth[a] - (1 << d) >= depth[b]){
            a = LCA[a][d];
        }
    }
    for(int d = MAXD - 1; d >= 0; d--){
        if(LCA[a][d] != LCA[b][d]){
            a = LCA[a][d];
            b = LCA[b][d];
        }
    }
    if(a != b)
        a = LCA[a][0];
    return a;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(make_pair(a, i));
        adj[a].push_back(make_pair(b, i));
    }
    dfs(1, 0);
    initLCA();
    for(int i = 0; i < M; i++){
        int s;
        cin >> s;
        vector<int> nums(s);
        int lca = -1;
        for(int i = 0; i < s; i++){
            cin >> nums[i];
            if(lca == -1){
                lca = nums[i];
            }
            else{
                lca = getLCA(lca, nums[i]);
            }
        }
        for(int x: nums){
            add[x].push_back(i);
        }
        sub[lca].push_back(i);
    }
    dfs2(1, 0, 0);
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int x: ans){
        cout << x << " ";
    }
    

}