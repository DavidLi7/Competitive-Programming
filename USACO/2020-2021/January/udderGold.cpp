#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXA = 21;

int N, a[MAXN], dp[1 << 20], tot, c[MAXA][MAXA];
map<char, int> m;
string s;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> s;
    N = s.size();
    for(int i = 0; i < N; i++){
        if(!m.count(s[i]))
            m[s[i]] = tot++;
        a[i] = m[s[i]];
    }
    for(int i = 0; i < N - 1; i++){
        c[a[i]][a[i + 1]]++;
    }
    for(int i = 0; i < (1 << tot); i++){
        dp[i] = N;
    }
    dp[0] = 1;
    for(int i = 0; i < (1 << tot); i++){
        for(int j = 0; j < tot; j++){
            if(i & (1 << j)){
                int s = dp[i ^ (1 << j)];
                for(int k = 0; k < tot; k++){
                    if(i & (1 << k)){
                        s += c[j][k];
                    }
                }
                dp[i] = min(dp[i], s);
            }
        }
    }
    cout << dp[(1 << tot) - 1];
}