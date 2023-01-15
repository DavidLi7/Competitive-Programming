#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 505;
const int MAXK = 11;

int N, M, K, g[MAXN][MAXN], dp[MAXN][MAXN][MAXK];
bool isPass[MAXN][MAXN];

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> g[i][j];
            for(int k = 0; k <= K; k++){
                dp[i][j][k] = 1e9;
            }
        }
    }
    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < M - 1; j++){
            if(g[i][j] != -1 && g[i - 1][j] != -1 && g[i + 1][j] != -1 && g[i][j - 1] != -1 && g[i][j + 1] != -1 && g[i][j] < g[i + 1][j] && g[i][j] < g[i - 1][j] && g[i][j] > g[i][j - 1] && g[i][j] > g[i][j + 1]){
                isPass[i][j] = true;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(g[i][0] != -1)
            dp[i][0][0] = g[i][0];
    }
    for(int j = 1; j < M; j++){
        for(int i = 0; i < N; i++) if(g[i][j] != -1){
            for(int k = isPass[i][j]; k <= K; k++){
                for(int d = -1; d <= 1; d++) if(i + d < N && i + d >= 0) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i + d][j - 1][k - isPass[i][j]] + g[i][j]);
                }
            }
        }
    }
    // for(int j = 0; j < M; j++){
    //     for(int i = 0; i < N; i++){
    //         for(int k = 0; k <= K; k++)
    //             cout << i + 1 << " " << j + 1 << " " << k << " " << dp[i][j][k] << "\n";
    //     }
    // }
    int ans = 1e9;
    for(int i = 0; i < N; i++){
        ans = min(ans, dp[i][M - 1][K]);
    }
    if(ans == 1e9){
        cout << "impossible\n";
    } else{
        cout << ans << "\n";
    }
}