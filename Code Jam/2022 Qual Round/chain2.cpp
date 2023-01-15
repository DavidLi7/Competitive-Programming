#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int T, N, f[MAXN], p[MAXN], dp[MAXN];
bool alive[MAXN];
vector<int> nodes, radj[MAXN];

int dfs(int i){
    dp[i] = 1e9;
    for(int v: radj[i]){
        dp[i] = min(dp[i], dfs(v]));
    }
    return dp[i];
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cout << "Case #" << t << ": ";
        cin >> N;
        for(int i = 1; i <= N; i++)
            cin >> f[i];
        for(int i = 1; i <= N; i++){
            cin >> p[i];
            radj[p[i]].push_back(i);
            if(p[i] == 0)
                nodes.push_back(i);
        }
        for(int x: nodes)
            dfs(x);
        int ans = 0;
        while(nodes.size() != 0){
            int i = nodes.back();
            nodes.pop_back();
            ans += max(dp[i], f[i]);
            while(radj[i].size() != 0){
                
                for(int v: radj[i]){

                }
                int temp = radj[i].back().second;
                radj[i].pop_back();
                i = temp;
                for(int v: radj[i])
            }
        }
    }
}