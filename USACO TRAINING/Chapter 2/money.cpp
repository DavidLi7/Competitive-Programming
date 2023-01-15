/*
ID: divadxl1
LANG: C++
TASK: money
*/

#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

long long dp[26][10001];
long long a[10001];

int main(){
    setIO("money");
    int V, N;
    cin >> V >> N;
    for(int i = 1; i <= V; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= V; i++){
        for(int j = 0; j <= N; j++){
            if(!j){
                 dp[i][j] = 1;
            }
            else{
                if(j < a[i]){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - a[i]];
                }
            }
        }
    }
    cout << dp[V][N] << "\n";




}