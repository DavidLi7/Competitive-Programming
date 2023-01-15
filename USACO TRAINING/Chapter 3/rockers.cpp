/*
ID: divadxl1
LANG: C++
TASK: rockers
*/
#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 21;

int dp[MAXN][MAXN][MAXN], nums[MAXN], N, M, T;

int main(){
    setIO("rockers");
    cin >> N >> T >> M;
    for(int i = 1; i <= N; i++){
        cin >> nums[i];
    }
    int mx = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j <= T; j++){
            for(int k = 0; k <= N; k++){
                for(int l = k + 1; l <= N; l++){
                    if(j + nums[l] <= T)
                        dp[i][j + nums[l]][l] = max(dp[i][j + nums[l]][l], dp[i][j][k] + 1);
                    if(nums[l] <= T)
                        dp[i + 1][nums[l]][l] = max(dp[i + 1][nums[l]][l], dp[i][j][k] + 1);
                }
                mx = max(mx, dp[i][j][k]);
            }
        }
    }
    cout << mx << "\n";

}