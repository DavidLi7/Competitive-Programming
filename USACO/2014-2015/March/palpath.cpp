#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 501;
const int MOD = 1e9 + 7;

int N;
long long dp[2][MAXN][MAXN];//2x + 1, r1, r2
string grid[MAXN];

int main(){
    setIO("palpath");
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }
    for(int i = 1; i <= N; i++){
        dp[0][i][i] = 1;
    }
    long long ans = 0;
    for(int i = 1; i < N; i++){
        for(int r1 = 1; r1 <= N; r1++){
            int c1 = N + 1 - r1 - i;
            for(int r2 = r1; r2 <= N; r2++){
                int c2 = N + 1 - r2 + i;
                // cout << r1 << " " << c1 << " " << r2 << " " << c2 << "\n";
                if(c1 < 1 || c1 > N || c2 < 1 || c2 > N)
                    continue;
                int d = i % 2;
                dp[d][r1][r2] = 0;
                if(grid[r1][c1] == grid[r2][c2]){
                    dp[d][r1][r2] = (dp[d][r1][r2] + dp[1 - d][r1 + 1][r2]) % MOD;
                    dp[d][r1][r2] = (dp[d][r1][r2] + dp[1 - d][r1 + 1][r2 - 1]) % MOD;
                    dp[d][r1][r2] = (dp[d][r1][r2] + dp[1 - d][r1][r2]) % MOD;
                    dp[d][r1][r2] = (dp[d][r1][r2] + dp[1 - d][r1][r2 - 1]) % MOD;
                    // cout << d << " " << r1 << " " << r2 << "\n";
                }
                // cout << d << " " << r1 << " " << r2 << " " << dp[d][r1][r2] << "\n";
                if(i == N - 1)
                    ans = (ans + dp[d][r1][r2]) % MOD;
            }
        }
    }
    cout << ans;
    
}