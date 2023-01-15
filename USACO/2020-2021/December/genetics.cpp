#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N, a[MAXN];
long long dp[MAXN][4][4][4];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> s;
    N = s.size();
    for(int i = 0; i < N; i++){
        if(s[i] == 'A')
            a[i] = 0;
        else if(s[i] == 'G')
            a[i] = 1;
        else if(s[i] == 'C')
            a[i] = 2;
        else if(s[i] == 'T')
            a[i] = 3;
        else if(s[i] == '?')
            a[i] = 4;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(a[0] == 4 || a[0] == j){
                dp[0][i][j][j]++;
            }
        }
    }
    for(int i = 1; i < N; i++){
        for(int c = 0; c < 4; c++) if(a[i] == c || a[i] == 4){
            for(int f = 0; f < 4; f++){
                for(int f2 = 0; f2 < 4; f2++){
                    for(int l = 0; l < 4; l++){
                        if(c != l){
                            dp[i][f][f2][c] = (dp[i][f][f2][c] + dp[i - 1][f][f2][l]) % MOD;
                        }
                        if(l == f){
                            dp[i][f2][c][c] = (dp[i][f2][c][c] + dp[i - 1][f][f2][l]) % MOD;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ans = (ans + dp[N - 1][i][j][i]) % MOD;
        }
    }
    cout << ans << "\n";

    
    


}