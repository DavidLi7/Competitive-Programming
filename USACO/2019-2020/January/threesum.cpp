#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 5005;
const int MAXD = 3e6 + 5;

int N, Q, ans[MAXN], a[MAXN];
long long dp[MAXN][MAXN], occ[MAXD];

int main(){
    setIO("threesum");
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        a[i] += 1e6;
    }
    for(int i = N - 1; i >= 0; i--){
        //unordered_map<int, int> occ;
        long long curr = 0;
        long long target = 3e6 - a[i];
        for(int j = i + 1; j < N; j++){
            if(target - a[j] < MAXD && target - a[j] >= 0)
                curr += occ[target - a[j]];
            if(a[j] >= 0 && a[j] < MAXD)
                occ[a[j]]++;
            dp[i][j] = curr + dp[i + 1][j];
        }
        for(int j = i + 1; j < N; j++){
            if(a[j] >= 0 && a[j] < MAXD)
                occ[a[j]]--;
        }
    }
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        cout << dp[a - 1][b - 1] << "\n";
    }
}