#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int N, K;
long long M, dp[MAXN];

int main(){
    setIO("spainting");
    cin >> N >> M >> K;
    dp[0] = 1;
    long long tot = 1;
    long long sum = 0;
    for(int i = 1; i < K; i++){
        dp[i] = (dp[i - 1] * M) % MOD;
        tot = (tot * M) % MOD;
        sum = (dp[i] + sum) % MOD;
    }
    for(int i = K; i <= N; i++){
        // for(int j = i - 1; j > i - K; j--){
        //     dp[i] = (dp[i] + (dp[j] * (M - 1)) % MOD) % MOD;
        // }
        dp[i] = (dp[i] + (sum * (M - 1LL)) % MOD) % MOD;
        sum = (sum - dp[i - K + 1] + dp[i]) % MOD;
        tot = (tot * M) % MOD;
    }
    cout << ((tot - dp[N]) % MOD + MOD) % MOD;
}