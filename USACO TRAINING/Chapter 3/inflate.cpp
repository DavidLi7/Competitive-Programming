/*
ID: divadxl1
LANG: C++
TASK: inflate
*/
#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 10000;

int M, N, dp[MAXN + 1];

int main(){
    setIO("inflate");
    cin >> M >> N;

    for(int i = 0; i < N; i++){
        int p, t;
        cin >> p >> t;
        for(int j = t; j <= M; j++){
            dp[j] = max(dp[j], dp[j - t] + p);
        }
    }
    cout << dp[M] << "\n";

}