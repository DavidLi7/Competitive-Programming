#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 401;

//loc, loc c, changes

int N, K, a[MAXN], mx[MAXN][MAXN], sum[MAXN][MAXN], best[MAXN][MAXN];

int main(){
    setIO("snakes");
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        sum[i][i] = a[i];
        mx[i][i] = a[i];
    }
    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            sum[i][j] = sum[i][j - 1] + a[j];
            mx[i][j] = max(mx[i][j - 1], a[j]);
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K + 1; j++){
            best[i][j] = 1e9;
        }
    }
    int dp[N + 1][N + 1][K + 2];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 1; k <= K + 1 && k <= j; k++){
                if(k == 1 && j != 1)
                    continue;
                //j to i
                dp[i][j][k] = best[j - 1][k - 1] + mx[j][i] * (i - j + 1) - sum[j][i];
                best[i][k] = min(best[i][k], dp[i][j][k]);
                // cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
            }
        }
    }
    int ans = 1e9;
    for(int k = 1; k <= K + 1; k++){
        ans = min(ans, best[N][k]);
    }
    cout << ans;
}