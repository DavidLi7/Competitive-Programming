#include <iostream>

using namespace std;

const int MAXN = 1005;

int T, x, y, N, dp[MAXN][2];
string s;

int main() {

     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> x >> y >> s;
        N = s.size();
        for(int i = 1; i <= N; i++){
            if(s[i - 1] == '?' || s[i - 1] == 'J'){//0
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + x);
                if(s[i - 1] == 'J')
                    dp[i][1] = 1e9;
            }
            if(s[i - 1] == '?' || s[i - 1] == 'C'){//1
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + y);
                if(s[i - 1] == 'C')
                    dp[i][0] = 1e9;
            }
        }
        cout << "Case #" << t << ": " << min(dp[N][0], dp[N][1]) << "\n";
    }
    
}