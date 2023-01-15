/*
ID: divadxl1
LANG: C++
TASK: nocows
*/

#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 202;
const int MOD = 9901;

int dp[MAXN][MAXN/2], N, K;

int main(){
    setIO("nocows");
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(i == 1){
                dp[i][j] = 1;
                continue;
            }
            for(int k = 1; k <= i - 2; k++){
                dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << (dp[N][K] - dp[N][K - 1] + MOD)%MOD << endl;
}