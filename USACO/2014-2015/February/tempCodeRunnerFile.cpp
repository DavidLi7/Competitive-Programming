for(int i = 1; i <= R; i++){
    //     for(int j = 1; j <= C; j++){
    //         dp[i][j] = pre[i - 1][j - 1];
    //         dp[i][j] -= get(grid[i][j], j);
    //         pre[i][j] = dp[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    //     }
    //     for(int j = 1; j <= C; j++){
    //         cout << i << " " << j << " " << dp[i][j] << "\n";
    //         upd(grid[i][j], j, dp[i][j]);
    //     }
    // }