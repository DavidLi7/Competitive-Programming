/*
ID: divadxl1
LANG: C++
TASK: game1
*/
#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 101;

int N, nums[MAXN], dp[MAXN][MAXN][2];

int main(){
    setIO("game1");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    for(int len = 1; len <= N; len++){
        int h = 1;
        if((N - len) % 2 == 0){
            h = 0;
        }
        for(int i = 0; i + len <= N; i++){
            if(len == 1){
                dp[i][i + len - 1][h] = nums[i];
            }
            else{
                int o = (h + 1) % 2;
                if(dp[i][i + len - 2][h] + nums[i + len - 1] > dp[i + 1][i + len - 1][h] + nums[i]){
                    dp[i][i + len - 1][h] = dp[i][i + len - 2][h] + nums[i + len - 1];
                    dp[i][i + len - 1][o] = dp[i][i + len - 2][o];
                }
                else{
                    dp[i][i + len - 1][h] = dp[i + 1][i + len - 1][h] + nums[i];
                    dp[i][i + len - 1][o] = dp[i + 1][i + len - 1][o];
                }
            }
            //cout << i << " " << i + len - 1 << " " << dp[i][i + len - 1][0] << " " << dp[i][i + len - 1][1] << "\n";
        }
    }
    cout << dp[0][N - 1][0] << " " << dp[0][N - 1][1] << "\n";

}