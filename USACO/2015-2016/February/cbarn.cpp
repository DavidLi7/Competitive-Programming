#include <iostream>
#include <vector>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1005;
const int MAXK = 10;

int N, K;
long long ans, cows[MAXN], wpre[MAXN], pre[MAXN], dp[MAXN][MAXK];

long long getDist(int a, int b){
    if(b < a)
        return 0LL;
    if(a == 0)
        return wpre[b];
    return wpre[b] - wpre[a - 1] - (long long)(a - 1) * (pre[b] - pre[a - 1]);
}

void solve2(int k, int dl, int dr, int l, int r){
    int ansi = dl;
    int m = (l + r) / 2;
    dp[m][k] = 1e18;
    for(int i = dl; i <= min(dr, m); i++){
        long long temp = dp[i - 1][k - 1] + getDist(i + 1, m);
        if(temp < dp[m][k]){
            dp[m][k] = temp;
            ansi = i;
        }
    }
    if(l != r){
        solve2(k, dl, ansi, l, m);
        solve2(k, ansi, dr, m + 1, r);
    }
}

void solve1(){
    pre[0] = cows[0];
    dp[0][1] = 0;
    for(long long i = 1; i < N; i++){
        wpre[i] = wpre[i - 1] + cows[i] * i;
        pre[i] = pre[i - 1] + cows[i];
        dp[i][1] = wpre[i];
    }
    for(int k = 2; k <= K; k++){
        solve2(k, 0, N - 1, 0, N - 1);
    }
    ans = min(ans, dp[N - 1][K]);
}

int main(){
    setIO("cbarn");
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> cows[i];
    }
    ans = 1e18;
    for(int i = 0; i < N; i++){
        solve1();
        int temp = cows[0];
        for(int i = 0; i < N - 1; i++){
            cows[i] = cows[i + 1];
        }
        cows[N - 1] = temp;
    }
    cout << ans;
}