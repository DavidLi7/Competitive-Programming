#include <iostream>

using namespace std;

const int MAXN = 105;

int N, T, W, g[MAXN][MAXN], curr[MAXN];

void solve(){

    cin >> N >> W;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < W; j++){
            cin >> g[i][j];
        }
    }

    int ans = 0;
    for(int j = 0; j < W; j++){
        int mn = 1e9;
        for(int i = 0; i < N; i++){
            mn = min(mn, g[i][j]);
        }
        ans += 2 * mn;
        for(int i = 0; i < N; i++){
            g[i][j] -= mn;
        }
    }    

    //iniate start
    for(int j = 0; j < W; j++){
        curr[j] = g[0][j];
        ans += curr[j];
    }

    //initiate N
    for(int j = 0; j < W; j++){
        g[N][j] = g[N - 1][j];
    }

    //1. get rid of anything that doesn't overlap between i and i + 1
    //2. complete the overlap between i and i + 1
    //3. add the remaining stuff of i


    for(int i = 1; i < N; i++){
        for(int j = 0; j < W; j++){
            int mn = min(g[i][j], g[i + 1][j]);
            if(curr[j] > mn){   //1
                ans += (curr[j] - mn);
                curr[j] = mn;
            }
            if(mn > curr[j]){   //2
                ans += (mn - curr[j]);
                curr[j] = mn;
            }
            ans += (g[i][j] - curr[j]); //3
            curr[j] = g[i][j];
        }
    }

    for(int j = 0; j < W; j++){
        ans += curr[j];
    }
    cout << ans;
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }

    
    
    
}