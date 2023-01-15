#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2;
const int MAXQ = 41;

int T, N, Q, s[MAXN];
long long dp[MAXQ][MAXQ][MAXQ][2 * MAXQ];//dist, score 1, score 2 bit activated
string a[MAXN];

int getGCD(int a, int b){
    if(b == 0)
        return a;
    return getGCD(b, a % b);
}

void solve(){
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> a[i] >> s[i];
        a[i] = " " + a[i];
    }
    if(N == 1){
        N = 2;
        a[1] = a[0];
        s[1] = s[0];
    }
    if(a[0][1] == 'T' && a[1][1] == 'T'){
        dp[1][1][1][1] = 1;
        dp[1][0][0][2] = 1;
    }
    if(a[0][1] == 'T' && a[1][1] == 'F'){
        dp[1][1][0][1] = 1;
        dp[1][0][1][2] = 1;
    }
    if(a[0][1] == 'F' && a[1][1] == 'T'){
        dp[1][0][1][1] = 1;
        dp[1][1][0][2] = 1;
    }
    if(a[0][1] == 'F' && a[1][1] == 'F'){
        dp[1][0][0][1] = 1;
        dp[1][1][1][2] = 1;
    }
    for(int i = 2; i <= Q; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= i; k++){
                for(int l = 1; l <= 2 * i - 2; l++){
                    if(a[0][i] == a[1][i]){
                        dp[i][j][k][l] += dp[i - 1][j][k][l];//add the other
                        dp[i][j][k][l] += dp[i - 1][j - 1][k - 1][l];//add the one
                        if(a[0][i] == 'T'){
                            // if(i % 2 == 1)
                                dp[i][j][k][2 * i - 1] += dp[i - 1][j - 1][k - 1][l];
                            // else
                                dp[i][j][k][2 * i] += dp[i - 1][j][k][l];
                        }
                        if(a[0][i] == 'F'){
                            // if(i % 2 == 1)
                                dp[i][j][k][2 * i - 1] += dp[i - 1][j][k][l];
                            // else
                                dp[i][j][k][2 * i] += dp[i - 1][j - 1][k - 1][l];
                        }
                    }
                    else{
                        dp[i][j][k][l] += dp[i - 1][j - 1][k][l];//add the first
                        dp[i][j][k][l] += dp[i - 1][j][k - 1][l];//add the second
                        if(a[0][i] == 'T' && a[1][i] == 'F'){
                            // if(i % 1 == 1)
                                dp[i][j][k][2 * i - 1] += dp[i - 1][j - 1][k][l];
                            // else
                                dp[i][j][k][2 * i] += dp[i - 1][j][k - 1][l];
                        }
                        else{
                            // if(i % 1 == 1)
                                dp[i][j][k][2 * i - 1] += dp[i - 1][j][k - 1][l];
                            // else
                                dp[i][j][k][2 * i] += dp[i - 1][j - 1][k][l];
                        }
                    }
                }
            }
        }
    }
    string ans = "";
    long long count = 0;
    long long tot = 0;
    for(int i = 1; i <= Q; i++){
        if(dp[Q][s[0]][s[1]][2 * i - 1] > dp[Q][s[0]][s[1]][2 * i]){
            ans += 'T';
            count += dp[Q][s[0]][s[1]][2 * i - 1];
        }
        else{
            ans += 'F';
            count += dp[Q][s[0]][s[1]][2 * i];
        }
        tot += dp[Q][s[0]][s[1]][2 * i - 1];
        tot += dp[Q][s[0]][s[1]][2 * i];
    }
    cout << tot << " " << count << "\n";
    tot /= (2 * Q);
    cout << tot << " " << count << "\n";
    int gcd = getGCD(tot, count);
    cout << ans << " " << count/gcd << "/" << tot/gcd << "\n";
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    
    
    
}