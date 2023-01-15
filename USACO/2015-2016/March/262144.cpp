#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 262145;
const int MAXA = 100;

int N, dp[MAXN][MAXA], nums[MAXN], ans;

int main(){
    setIO("262144");
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> nums[i];
        dp[i][nums[i]] = i;
        ans = max(ans, nums[i]);
    }
    for(int i = 1; i < MAXA; i++){
        for(int j = 1; j <= N; j++){
            if(dp[j][i] == 0 && dp[j][i - 1] != 0 && dp[j][i - 1] != N)
                dp[j][i] = dp[dp[j][i - 1] + 1][i - 1];
            if(dp[j][i] != 0){
                ans = max(ans, i);
            }
        }
    }
    cout << ans;
}