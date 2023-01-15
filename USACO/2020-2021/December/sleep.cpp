#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 3005;
const int MOD = 1e9 + 7;

int N;
long long dp[2][2 * MAXN][2];
pair<int, int> a[2 * MAXN];//loc, type

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i].first;
        a[i].second = 0;
    }
    for(int i = N; i < 2 * N; i++){
        cin >> a[i].first;
        a[i].second = 1;
    }
    sort(a, a + 2 * N);
    dp[0][0][0] = 1;
    //0 -> using everything
    //1 -> not using everything
    for(int i = 0; i < 2 * N; i++){
        int c = i % 2;
        int o = 1 - c;
        for(int j = 0; j < 2 * N; j++){
            dp[o][j][0] = dp[o][j][1] = 0;
        }
        if(a[i].second == 0){//a cow
            for(int j = 0; j < 2 * N; j++){//amt we still need to match
                dp[o][j + 1][0] = (dp[o][j + 1][0] + dp[c][j][0]) % MOD;
                dp[o][j + 1][1] = (dp[o][j + 1][1] + dp[c][j][1]) % MOD;
                dp[o][j][1] = (dp[o][j][1] + dp[c][j][0] + dp[c][j][1]) % MOD;
            }
        }
        else{//a barn
            for(int j = 0; j < 2 * N; j++){
                if(j != 0){
                    dp[o][j - 1][0] = (dp[o][j - 1][0] + dp[c][j][0] * (1LL * j)) % MOD;
                    dp[o][j - 1][1] = (dp[o][j - 1][1] + dp[c][j][1] * (1LL * j)) % MOD;
                }
                dp[o][j][0] = (dp[o][j][0] + dp[c][j][0]) % MOD;
            }
        }
    }
    cout << dp[0][0][0] + dp[0][0][1] << "\n";
    
}