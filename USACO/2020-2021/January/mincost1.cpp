#include <iostream>

using namespace std;

const int MAXN = 2e3 + 5;
const int MAXM = 2e3 + 5;

int N, M, Q;
long long c[MAXM], dp[MAXN][MAXM];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> c[i];
    }
    dp[1][1] = 0;
    for(int i = 2; i <= N; i++){
        dp[i][1] = dp[i - 1][1] + c[1];
    }
    for(int j = 2; j <= M; j++){
        dp[1][j] = dp[1][j - 1] + 1;
    }
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= M; j++){
            dp[i][j] = min(dp[i - 1][j] + c[j], dp[i][j - 1] + (long long)(i * i));
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}