#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 755;
const int MOD = 1000000007;

int R, C, K, grid[MAXN][MAXN];
long long dp[MAXN][MAXN], pre[MAXN][MAXN];
unordered_map<int, int> m;
vector<vector<long long> > BIT;
vector<set<int> >ind;
vector<unordered_map<int, int> > m2;

long long get(int c, int i){
    int idx = m2[c][i] - 1;
    long long ret = 0;
    while(idx > 0){
        ret = (ret + BIT[c][idx]) % MOD;
        idx -= idx & -idx;
    }
    return ret;
}

void upd(int c, int i, long long amt){
    int idx = m2[c][i];
    while(idx < BIT[c].size()){
        BIT[c][idx] = (BIT[c][idx] + amt) % MOD;
        idx += idx & -idx;
    }
}

int main(){
    setIO("hopscotch");
    cin >> R >> C >> K;
    int curr = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> grid[i][j];
            if(m.count(grid[i][j]) == 0){
                m[grid[i][j]] = curr++;
                grid[i][j] = m[grid[i][j]];
                set<int> s;
                s.insert(j);
                ind.push_back(s);
            }
            else{
                grid[i][j] = m[grid[i][j]];
                ind[grid[i][j]].insert(j);
            }
        }
    }
    K = m.size();
    m2.resize(K);
    BIT.resize(K);
    for(int i = 0; i < K; i++){
        int temp = 1;
        for(int x: ind[i]){
            m2[i][x] = temp++;
        }
        BIT[i].resize(temp);
    }
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(i == j && i == 1){
                dp[i][j] = 1;
                pre[i][j] = 1;
                continue;
            }
            dp[i][j] = (pre[i - 1][j - 1] - get(grid[i][j], j)) % MOD;
            pre[i][j] = (dp[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]) % MOD;
        }
        for(int j = 1; j <= C; j++){
            // cout << i << " " << j << " " << dp[i][j] << "\n";
            upd(grid[i][j], j, dp[i][j]);
        }
    }
    cout << ((dp[R][C]) % MOD + MOD) % MOD<< "\n";
}