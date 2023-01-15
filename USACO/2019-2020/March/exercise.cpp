#include <iostream>
#include <map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 7505;

int N, MOD;
long long ans, dp[MAXN], fact[MAXN];
bool comp[MAXN];

long long pow(long long a, int p){
    long long ret = 1;
    while(p > 0){
        if(p & 1)
            ret = (ret * a) % MOD;
        p >>= 1;
        a = (a * a) % MOD;
    }
    return ret;
}

int solve(int x){
    for(int i = 1; i <= N; i++)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 1; i <= N; i++){
        long long ways = 1;
        for(int j = 1; j <= i; j++){
            if(j % x != 0)
                dp[i] = (dp[i] + (ways * dp[i - j]) % MOD) % MOD;
            ways = (ways * (i - j)) % MOD;
        }
        // cout << x << " " << i << " " << dp[i] << "\n";
    }
    return ((fact[N] - dp[N]) % MOD + MOD) % MOD;
}

int main(){
    // setIO("exercise");
    cin >> N >> MOD;
    ans = 1;
    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for(int i = 2; i <= N; i++){
        if(!comp[i]){
            for(int j = i; j <= N; j += i)
                comp[j] = true;
            for(int j = i; j <= N; j *= i){
                ans = ans * pow(i, solve(j));
                ans %= MOD;
            }
        }
    }
    cout << ans;
}
