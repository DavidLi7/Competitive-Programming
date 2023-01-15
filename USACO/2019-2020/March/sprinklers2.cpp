#include <iostream>

using namespace std;

#define ll long long

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 2005;
const int MOD = 1e9 + 7;
const ll H = 5e8 + 4;

int N;
ll dp1[MAXN][MAXN], dp2[MAXN][MAXN], ans;
char grid[MAXN][MAXN];

int main(){
    setIO("sprinklers2");
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    dp1[0][0] = 1;
    dp2[0][0] = 1;
    for(int i = 1; i <= N; i++){//j is zero
        if(i != N)
            dp1[i][0] = 1;
        if(grid[i - 1][0] == '.')
            dp2[i][0] = H;
    }
    for(int j = 1; j <= N; j++){//i is zero
        if(j != N)
            dp2[0][j] = 1;
        if(grid[0][j - 1] == '.')
            dp1[0][j] = H;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i != N){
                dp1[i][j] = dp1[i - 1][j];
                if(grid[i][j - 1] == '.')
                    dp1[i][j] += (dp2[i][j - 1] * H) % MOD;
                dp1[i][j] %= MOD;
            }
            if(j != N){
                dp2[i][j] = dp2[i][j - 1];
                if(grid[i - 1][j] == '.')
                    dp2[i][j] += (dp1[i - 1][j] * H) % MOD;
                dp2[i][j] %= MOD;
            }
        }
    }
    ll ans = (dp1[N - 1][N] + dp2[N][N - 1]) % MOD;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == '.')
                ans = (ans * 2LL) % MOD;
        }
    }
    cout << ans << "\n";

}