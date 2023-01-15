#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 155;

int N, dp[MAXN][MAXN][2][2][2][2][2];//x, y, anything immediate left, anything immediate below, anything left, anything belowis used
string g[MAXN];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> g[i];
    }
    int temp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(g[i][j] == 'G'){//using it
                //nothing to left or below -> 1
                dp[i][j][0][0][0][0][1]++;

                //nothing to the left, something below
                if(j)
                    for(int k = 0; k < 2; k++){//immediate left
                        for(int l = 0; l < 2; l++){//immediate below
                            for(int m = 0; m < 2; m++){//left
                                for(int n = 0; n < 2; n++){//below
                                    if(!(k == 1 && m == 0) && !(l == 1 && n == 0))
                                        dp[i][j][0][1][m][1][1] += dp[i][j - 1][k][l][m][n][1];
                                }
                            }
                        }
                    }

                //nothing below, something to the left
                if(i)
                    for(int k = 0; k < 2; k++){//immediate left
                        for(int l = 0; l < 2; l++){//immediate below
                            for(int m = 0; m < 2; m++){//left
                                for(int n = 0; n < 2; n++){//below
                                    if(!(k == 1 && m == 0) && !(l == 1 && n == 0))
                                        dp[i][j][1][0][1][n][1] += dp[i - 1][j][k][l][m][n][1];
                                }
                            }
                        }
                    }
                
                //something below and something to the left
                if(i && j)
                    for(int k = 0; k < 2; k++){//immediate left
                        for(int l = 0; l < 2; l++){//immediate below
                            dp[i][j][1][1][1][1][1] += dp[i - 1][j][k][1][k][1][1] * dp[i][j - 1][1][l][1][l][1];
                            dp[i][j][1][1][1][1][1] += dp[i - 1][j][k][0][k][0][1] * dp[i][j - 1][0][l][0][l][1];
                        }
                    }
            }
            //not using it

            for(int k = 0; k < i; k++){
                for(int l = 0; l < j; l++){
                    
                }
            }

        }
    }
    vector<int> ans(2, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    for(int v = 0; v < 2; v++){
                        for(int a = 0; a < 2; a++){
                            
                            for(int b = 0; b < 2; b++){
                                ans[b] += dp[i][j][k][l][v][a][b];
                                if(b)
                                    cout << i << " " << j << " " << k << " " << l << " " << v << " " << a << " " << b << " " << dp[i][j][k][l][v][a][b] << "\n";
                            }
                        }
                    }
                }
            }
        }
    }
    cout << temp << "\n";
    cout << ans[0] << " " << ans[1] << "\n";
}