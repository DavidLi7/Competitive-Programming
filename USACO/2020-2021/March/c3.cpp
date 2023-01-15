#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 155;

int N, dp[MAXN][MAXN][MAXN][MAXN][2][2];//x, y, anything immediate left, anything immediate below, anything left, anything belowis used
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
                dp[i][j][0][0][0][0]++;

                //nothing to the left, something below
                if(j)
                    for(int k = 1; k <= j; k++){//how far below one goes
                        if(g[i][j - k] == '.')
                            break;
                        for(int l = 0; l <= i; l++){//direct left of under
                            for(int m = min(l, 1); m < 2; m++){//left at all
                                dp[i][j][0][k][m][1] += dp[i][j - 1][l][k - 1][m][min(1, k - 1)];
                            }
                        }
                    }
                    // dp[i][j][0][?][?][1][1] += dp[i][j]
                    // for(int k = 0; k < 2; k++){//immediate left
                    //     for(int l = 0; l < 2; l++){//immediate below
                    //         for(int m = 0; m < 2; m++){//left
                    //             for(int n = 0; n < 2; n++){//below
                    //                 if(!(k == 1 && m == 0) && !(l == 1 && n == 0))
                    //                     dp[i][j][0][1][m][1][1] += dp[i][j - 1][k][l][m][n][1];
                    //             }
                    //         }
                    //     }
                    // }

                //nothing below, something to the left
                if(i)
                    for(int k = 1; k <= i; k++){
                        if(g[i - k][j] == '.')
                            break;
                        for(int l = 0; l <= j; l++){
                            for(int m = min(1, l); m < 2; m++){
                                dp[i][j][k][0][1][m] += dp[i - 1][j][k - 1][l][min(1, k - 1)][m];
                            }
                        }
                    }
                    // for(int k = 0; k < 2; k++){//immediate left
                    //     for(int l = 0; l < 2; l++){//immediate below
                    //         for(int m = 0; m < 2; m++){//left
                    //             for(int n = 0; n < 2; n++){//below
                    //                 if(!(k == 1 && m == 0) && !(l == 1 && n == 0))
                    //                     dp[i][j][1][0][1][n][1] += dp[i - 1][j][k][l][m][n][1];
                    //             }
                    //         }
                    //     }
                    // }
                
                //something below and something to the left
                if(i && j)
                    for(int m = 1; m <= i; m++){
                        for(int n = 1; n <= j; n++){
                            for(int k = 1; k <= j; k++){
                                for(int l = 1; l <= i; l++){
                                    dp[i][j][m][n][1][1] += dp[i - 1][j][m - 1][k][min(1, m - 1)][1] * dp[i][j - 1][l][n - 1][1][min(1, n - 1)];
                                }
                            }
                            dp[i][j][m][n][1][1] += dp[i - 1][j][m - 1][0][min(1, m - 1)][0] * dp[i][j - 1][0][n - 1][0][min(1, n - 1)];
                        }
                    }
                    // for(int k = 0; k < 2; k++){//immediate left
                    //     for(int l = 0; l < 2; l++){//immediate below
                    //         dp[i][j][1][1][1][1][1] += dp[i - 1][j][k][1][k][1][1] * dp[i][j - 1][1][l][1][l][1];
                    //         dp[i][j][1][1][1][1][1] += dp[i - 1][j][k][0][k][0][1] * dp[i][j - 1][0][l][0][l][1];
                    //     }
                    // }
                    // for(int k = 0; k < 2; k++){//immediate left
                    //     for(int l = 0; l < 2; l++){//immediate below
                    //         dp[i][j][1][1][1][1][1] += dp[i - 1][j][k][1][k][1][1] * dp[i][j - 1][1][l][1][l][1];
                    //         dp[i][j][1][1][1][1][1] += dp[i - 1][j][k][0][k][0][1] * dp[i][j - 1][0][l][0][l][1];
                    //     }
                    // }
            }
            //not using it

            for(int k = 0; k < i; k++){
                for(int l = 0; l < j; l++){
                    for(int m = 0; m <= k; m++){
                        for(int n = 0; n <= l; n++){
                            for(int a = j - l; a <= j; a++){
                                for(int b = i - k; b <= i; b++){
                                    temp += dp[k][j][m][a][min(1, m)][1] * dp[i][l][b][n][1][min(1, m)];
                                }
                            }
                            // temp += dp[k][j][m][j - l][min(1, m)][1] * dp[i][l][i - k][n][1][min(1, m)];
                        }
                    }
                }
            }

        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k <= N; k++){
                for(int l = 0; l <= N; l++){
                    for(int v = 0; v < 2; v++){
                        for(int a = 0; a < 2; a++){
                            ans += dp[i][j][k][l][v][a];
                            cout << i << " " << j << " " << k << " " << l << " " << v << " " << a << " " << dp[i][j][k][l][v][a] << "\n";
                            
                        }
                    }
                }
            }
        }
    }
    cout << temp << "\n";
    cout << ans << "\n";
}