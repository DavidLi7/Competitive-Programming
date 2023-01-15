#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int N, K;
long long A[MAXN], dp[MAXN][MAXN][2][2];//0 is down, 1 is up

void solve(int a, int b, int t1, int t2){
    if(a == b && t1 != t2){
        dp[a][b][t1][t2] = 1e17;;
    }
    if(a == b && t1 == t2){
        if(t1 == 0)
            dp[a][b][t1][t2] = A[a];
        else
            dp[a][b][t1][t2] = K - A[a] + 1;
    }
    if(dp[a][b][t1][t2] != -1)
        return;
    dp[a][b][t1][t2] = 1e18;
    solve(a + 1, b, 0, t2);
    solve(a + 1, b, 1, t2);
    solve(a, b - 1, t1, 0);
    solve(a, b - 1, t1, 1);
    if(t2 == 0){
        if(A[b - 1] != 0 || dp[a][b - 1][t1][0] == 0)
            dp[a][b][t1][t2] = min(dp[a][b][t1][t2], dp[a][b - 1][t1][0] + max(0LL, A[b] - A[b - 1]));
        else
            dp[a][b][t1][t2] == min(dp[a][b][t1][t2], max(dp[a][b - 1][t1][0], K + 1LL));
        
        dp[a][b][t1][t2] = min(dp[a][b][t1][t2], dp[a][b - 1][t1][1] + A[b]);
    }
    if(t1 == 0){
        if(A[a + 1] != 0 || dp[a + 1][b][0][t2] == 0)
            dp[a][b][t1][t2] = min(dp[a][b][t1][t2], dp[a + 1][b][0][t2] + max(0LL, A[a] - A[a + 1]));
        else
            dp[a][b][t1][t2] = min(dp[a][b][t1][t2], max(dp[a + 1][b][0][t2], K + 1LL));
        dp[a][b][t1][t2] = min(dp[a][b][t1][t2], dp[a + 1][b][1][t2] + A[a]);
    }
    if(t2 == 1){
        dp[a][b][t1][t2] = min(dp[a][b][t1][t2], dp[a][b - 1][t1][0] + K - A[b] + 1);
        dp[a][b][t1][t2] = min(dp[a][b][t1][t2], dp[a][b - 1][t1][1] + max(0LL, A[b - 1] - A[b]));
    }
    if(t1 == 1){
        dp[a][b][t1][t2] = min(dp[a][b][t1][t2], dp[a + 1][b][0][t2] + K - A[a] + 1);
        dp[a][b][t1][t2] = min(dp[a][b][t1][t2], dp[a + 1][b][1][t2] + max(0LL, A[a + 1] - A[a]));
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        for(int j = i; j < N; j++){
            dp[i][j][0][0] = -1;
            dp[i][j][0][1] = -1;
            dp[i][j][1][0] = -1;
            dp[i][j][1][1] = -1;
        }
    }
    solve(0, N - 1, 0, 0);
    solve(0, N - 1, 0, 1);
    solve(0, N - 1, 1, 0);
    solve(0, N - 1, 1, 1);
    cout << min(dp[0][N - 1][0][0], min(dp[0][N - 1][0][1], min(dp[0][N - 1][1][0], dp[0][N - 1][1][1])));
}