#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1000;
const int MOD = 1e9 + 9;

long long dp[MAXN][MAXN][11];
int J[MAXN], P[MAXN], N, M, K;

int main(){
    setIO("team");

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        cin >> J[i];
    }
    for(int i = 0; i < M; i++){
        cin >> P[i];
    }
    sort(J, J + N);
    sort(P, P + M);
    reverse(J, J + N);
    reverse(P, P + M);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 1; k <= K; k++){
                if(i != 0)
                    dp[i][j][k] += dp[i - 1][j][k];
                if(j != 0)
                    dp[i][j][k] += dp[i][j - 1][k];
                if(i != 0 && j != 0){
                    dp[i][j][k] -= dp[i - 1][j - 1][k];
                }
                if(J[i] > P[j]){
                    if(k==1)
                        dp[i][j][k]++;
                    else{  
                        if(i != 0 && j != 0)
                            dp[i][j][k] += dp[i - 1][j - 1][k - 1];
                    }
                }
                dp[i][j][k] %= MOD;
                if(dp[i][j][k] < 0)
                    dp[i][j][k] += MOD;
            }
        }
    }
    cout << dp[N-1][M-1][K];




}