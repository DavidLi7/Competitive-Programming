#include <iostream>

using namespace std;

const int MAXN = 1e9 + 5;
const int MAXM = 2e5 + 5;

int N, M, Q;
long long c[MAXM];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> c[i];
    }
    if(N * M <= 1e8){
        long long dp[N + 1][M + 1];
        dp[1][1] = 0;
        for(int i = 2; i <= N; i++){
            dp[i][1] = dp[i - 1][1] + c[1];
        }
        for(int j = 2; j <= M; j++){
            dp[1][j] = dp[1][j - 1] + 1;
        }
        for(int i = 2; i <= N; i++){
            for(int j = 2; j <= M; j++){
                dp[i][j] = min(dp[i - 1][j] + c[j], dp[i][j - 1] + (long long)(i * i));
            }
        }
        cin >> Q;
        while(Q--){
            int x, y;
            cin >> x >> y;
            cout << dp[x][y] << "\n";
        }
        return 0;
    }
    cin >> Q;
    while(Q--){
        long long x, y;
        cin >> x >> y;
        long long lo = 1LL;
        long long hi = x;
        while(lo < hi){
            long long z = (lo + hi) / 2LL;
            long long v = z * z * (y - 1LL) + (z - 1LL) * c[1] + (x - z) * c[y];
            long long z2 = z + 1LL;
            long long v2 = z2 * z2 * (y - 1LL) + (z2 - 1LL) * c[1] + (x - z2) * c[y];
            if(v < v2){
                hi = z;
            }
            else{
                lo = z2;
            }
        }
        cout << min(c[y] * (x - 1LL) + (y - 1LL), lo * lo * (y - 1LL) + (lo - 1LL) * c[1] + (x - lo) * c[y])<< "\n";
    }   
}

/*
10 10
19 100 50 40 30 20 12 11 10 1

0 1 2 3 4 5 6 7 8 9 
19 23 27 31 34 25 18 18 18 10 
38 47 56 65 64 45 30 29 28 11 
57 73 89 105 94 65 42 40 38 12 
76 101 126 145 124 85 54 51 48 13 
95 131 167 185 154 105 66 62 58 14 
114 163 212 225 184 125 78 73 68 15 
133 197 261 265 214 145 90 84 78 16 
152 233 311 305 244 165 102 95 88 17 
171 271 361 345 274 185 114 106 98 18 
*/