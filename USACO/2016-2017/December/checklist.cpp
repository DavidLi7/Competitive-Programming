#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1005;

long long dp[MAXN][MAXN][2];

int H, G, x[2][MAXN], y[2][MAXN];

long long dist(int c1, int c2, int i, int j){
    return (x[c1][i] - x[c2][j]) * (x[c1][i] - x[c2][j]) + (y[c1][i] - y[c2][j]) * (y[c1][i] - y[c2][j]);
}

int main(){
    setIO("checklist");
    cin >> H >> G;
    for(int i = 1; i <= H; i++){
        cin >> x[0][i] >> y[0][i];
    }
    for(int i = 1; i <= G; i++){
        cin >> x[1][i] >> y[1][i];
    }
    for(int i = 0; i <= H; i++){
        for(int j = 0; j <= G; j++){
            dp[i][j][0] = 1e18;
            dp[i][j][1] = 1e18;
        }
    }
    dp[1][0][0] = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 0; j <= G; j++){
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0] + dist(0, 0, i, i + 1));
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][1] + dist(1, 0, j, i + 1));
            dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][0] + dist(0, 1, i, j + 1));
            dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + dist(1, 1, j, j + 1));
            // cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
        }
    }
    cout << dp[H][G][0];

}