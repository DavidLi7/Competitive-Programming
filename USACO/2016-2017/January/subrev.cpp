#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 51;

int N, a[MAXN], dp[MAXN][MAXN][MAXN][MAXN], mx;

int solve(int s, int e, int l, int h){
    if(s < 0 || s > N - 1 || e < 0 || e > N - 1 || l < 0 || l > 49 || h < 0 || h > 49)
        return 0;
    if(dp[s][e][l][h] != -1)
        return dp[s][e][l][h];
    if(s > e){
        dp[s][e][l][h] = 0;
        return 0;
    }
    if(l > h){
        dp[s][e][l][h] = -1e9;
        return -1e9;
    }
    if(s == e){
        if(a[s] >= l && a[s] <= h)
            dp[s][e][l][h] = 1;
        else{
            dp[s][e][l][h] = 0;
        }
        return dp[s][e][l][h];
    }
    //swap
    if(a[s] >= l && a[s] <= h && a[e] >= l && a[e] <= h){
        dp[s][e][l][h] = max(dp[s][e][l][h], solve(s + 1, e - 1, max(a[e], l), min(a[s], h)) + 2);
    }
    if(a[s] >= l && a[s] <= h){
        dp[s][e][l][h] = max(dp[s][e][l][h], solve(s + 1, e - 1, l, min(a[s], h)) + 1);
    }
    if(a[e] >= l && a[e] <= h){
        dp[s][e][l][h] = max(dp[s][e][l][h], solve(s + 1, e - 1, max(a[e], l), h) + 1);
    }
    //only add s
    if(a[s] >= l && a[s] <= h)
        dp[s][e][l][h] = max(dp[s][e][l][h], solve(s + 1, e, max(a[s], l), h) + 1);
    //only add e
    if(a[e] >= l && a[e] <= h)
        dp[s][e][l][h] = max(dp[s][e][l][h], solve(s, e - 1, l, min(a[e], h)) + 1);
    //add none
    dp[s][e][l][h] = max(dp[s][e][l][h], solve(s + 1, e, l, h));
    dp[s][e][l][h] = max(dp[s][e][l][h], solve(s, e - 1, l, h));
    dp[s][e][l][h] = max(dp[s][e][l][h], solve(s, e, l + 1, h));
    dp[s][e][l][h] = max(dp[s][e][l][h], solve(s, e, l, h - 1));
    return dp[s][e][l][h];
}

int main(){
    setIO("subrev");
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 50; k++){
                for(int l = 0; l < 50; l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
        a[i]--;
    }
    cout << solve(0, N - 1, 0, 49);
}