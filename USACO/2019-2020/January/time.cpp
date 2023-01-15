#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1005;

int N, M;
long long C, dp[MAXN][MAXN], m[MAXN];//loc, days
vector<int> adj[MAXN];

int main(){
    setIO("time");
    cin >> N >> M >> C;
    for(int i = 0; i < N; i++){
        cin >> m[i];
    }
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    for(int i = 0; i < N; i++){
        for(int d = 0; d < MAXN; d++){
            dp[i][d] = -1e9;
        }
    }
    dp[0][0] = 0;
    long long ans = 0;
    for(long long d = 1; d < MAXN; d++){
        for(int i = 0; i < N; i++){
            for(int v: adj[i]){
                dp[i][d] = max(dp[i][d], dp[v][d - 1] + m[i] - C * d * d + C * (d - 1) * (d - 1));
            }
        }
        ans = max(ans, dp[0][d]);
    }
    cout << ans;
}
