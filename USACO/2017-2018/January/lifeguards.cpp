#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;
const int MAXK = 105;

int N, K, dp[MAXN][MAXK];
pair<int, int> A[MAXN];
vector<pair<int, int> > a;

int main(){
    setIO("lifeguards");
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i].first >> A[i].second;
        
    }
    sort(A, A + N);
    int mx = -1e9;
    for(int i = 0; i < N; i++){
        if(A[i].second > mx){
            mx = A[i].second;
            a.push_back(A[i]);
        }
        else{
            K--;
        }
    }
    N = a.size();
    int loc = 0;
    int ans = 0;
    //dp[i][j] = ans using ith element and skipped j so far
    for(int i = 0; i < N; i++){
        while(a[loc].second < a[i].first)
            loc++;
        for(int j = 0; j <= K; j++){
            if(j > i){
                dp[i][j] = -1e9;
                break;
            }
            //we use loc
            if(loc != i){
                int x = loc;
                int y = j - (i - loc - 1);
                dp[i][j] = max(dp[i][j], dp[x][max(0, y)] + a[i].second - a[loc].second);
            }
            //we do not use loc
            if(loc == 0){
                dp[i][j] = max(dp[i][j], a[i].second - a[i].first);
            }
            else{
                int x = loc - 1;
                int y = j - (i - (loc - 1) - 1);
                dp[i][j] = max(dp[i][j], dp[x][max(0, y)] + a[i].second - a[i].first);
            }
            if(i != 0 && j != 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            //cout << dp[i][j] << " " << i << " " << j << "\n";
        }
        ans = max(ans, dp[i][max(0, K - (N - i - 1))]);
    }
    cout << ans;
}
/*
5 2
1 10
2 9
3 11
4 12
5 13*/