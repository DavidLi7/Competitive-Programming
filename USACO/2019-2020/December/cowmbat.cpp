#include <iostream>
#include <queue>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5 + 5;
const int MAXM = 26;

long long N, M, K, a[MAXM][MAXM], c[MAXN][MAXM], dp[MAXN][MAXM], mn[MAXN];
string s;

void setup(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < M; k++){
                a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
            }
        }
    }
}

int main(){
    setIO("cowmbat");
    cin >> N >> M >> K >> s;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    s = " " + s;
    
    setup();
    // for(int i = 0; i < M; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < M; j++){
            c[i][j] = c[i - 1][j] + a[s[i] - 'a'][j];
        }
    }
    for(int i = K; i <= N; i++){
        mn[i] = 1e9;
        for(int j = 0; j < M; j++){
            if(i < 2 * K){
                dp[i][j] = c[i][j];
            }
            else{
                dp[i][j] = min(dp[i - 1][j] + a[s[i] - 'a'][j], mn[i - K] + c[i][j] - c[i - K][j]);
            }
            mn[i] = min(mn[i], dp[i][j]);
            // cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    cout << mn[N];
}