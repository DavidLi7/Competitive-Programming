#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e4 + 5;
const int MAXK = 1e3 + 5;

int N, K, s[MAXN], dp[MAXN][MAXK], mx[MAXN][MAXK];

int main(){
    setIO("teamwork");
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> s[i];
    }
    for(int i = 1; i <= N; i++){
        mx[i][0] = s[i];
        for(int j = 1; j <= K && i + j <= N; j++){
            mx[i][j] = max(mx[i][j - 1], s[i + j]);
        }
    }
    for(int i = 1; i <= N; i++){
        dp[i][1] += s[i];
        dp[i + 1][1] = dp[i][1];
        for(int j = 2; j <= K && j <= i; j++){
            dp[i][j] = dp[i - j + 1][1] - s[i - j + 1] + mx[i - j + 1][j - 1] * j;
            //dp[i][j] = dp[i - 1][j - 1] + mx[i - j + 1][i];
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][j]);
        }
    }
    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= K; j++){
    //         cout << i << " " << j << " " << dp[i][j] << "\n";
    //     }
    // }
    cout << dp[N + 1][1];
}