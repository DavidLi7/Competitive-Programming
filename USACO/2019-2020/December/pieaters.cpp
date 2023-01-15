#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 301;
const int MAXM = 50000;

int N, M;
long long dp[MAXN][MAXN], mx[MAXN][MAXN][MAXN];


int main(){
    setIO("pieaters");
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        long long w, l, r;
        cin >> w >> l >> r;
        l--; r--;
        for(int j = l; j <= r; j++)
            mx[j][l][r] = max(mx[j][l][r], w);
    }
    for(int i = 0; i < N; i++){
        for(int j = i; j >= 0; j--){
            for(int k = i; k < N; k++){
                if(k != i)
                    mx[i][j][k] = max(mx[i][j][k], mx[i][j][k - 1]);
                if(j != i)
                    mx[i][j][k] = max(mx[i][j][k], mx[i][j + 1][k]);
            }
        }
    }
    for(int i = N - 1; i >= 0; i--){
        for(int j = i; j < N; j++){
            for(int k = i; k < j; k++){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            for(int k = i; k <= j; k++){
                long long comp = mx[k][i][j];
                if(k != i)
                    comp += dp[i][k - 1];
                if(k != j)
                    comp += dp[k + 1][j];
                dp[i][j] = max(dp[i][j], comp);
            }
        }
    }
    cout << dp[0][N - 1];
}