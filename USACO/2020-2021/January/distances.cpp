#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXK = 5e4 + 5;
const int MOD = 1e9 + 7;

struct seg{
    long long t[4 * MAXN];

    void upd(int v, int tl, int tr, int x){
        if(tl == tr){
            t[v]++;
        }
        else{
            int tm = (tl + tr) / 2;
            if(x <= tm)
                upd(2 * v, tl, tm, x);
            else
                upd(2 * v + 1, tm + 1, tr, x);
            t[v] = (t[2 * v] * t[2 * v + 1]) % MOD;
        }
    }

    long long get(int v, int tl, int tr, int l, int r){
        if(l > r)
            return 1LL;
        if(tl == l && tr == r){
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return (get(2 * v, tl, tm, l, min(r, tm)) * 
        get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)) % MOD;
    }
};

struct state{
    int loc, sign, ind;
    long long val;
    state(long long v, int l, int s, int i) : val(v), loc(l), sign(s), ind(i){}
};

bool cmp(const state& x, const state& y) {return x.val < y.val;}

int K, N[MAXK], M[MAXK], s[MAXN];
vector<int> adj[MAXN];
long long ans, dp[MAXN][2];
seg odd, even, both;
bool vis[MAXN][2];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> K;
    vector<state> PQ;//val, loc, even = 0, odd = 1
    for(int i = 0; i < K; i++){
        cin >> N[i] >> M[i];
        for(int j = 0; j < N[i]; j++){
            dp[j + s[i]][0] = -1;
            dp[j + s[i]][1] = -1;
        }
        for(int j = 0; j < M[i]; j++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[s[i] + a].push_back(s[i] + b);
            adj[s[i] + b].push_back(s[i] + a);
        }
        queue<pair<int, int> > bfs;
        bfs.push(make_pair(s[i], 0));
        dp[s[i]][0] = 0;
        while(bfs.size()){
            pair<int, int> temp = bfs.front();
            bfs.pop();
            for(int v: adj[temp.first]){
                if(dp[v][(temp.second + 1) % 2] == -1){
                    dp[v][(temp.second + 1) % 2] = temp.second + 1;
                    bfs.push(make_pair(v, temp.second + 1));
                }
            }
        }
        for(int j = 0; j < N[i]; j++){
            PQ.push_back(state(dp[s[i] + j][0], i, 0, s[i] + j));
            PQ.push_back(state(dp[s[i] + j][1], i, 1, s[i] + j));
            if(dp[s[i] + j][0] != -1 && dp[s[i] + j][1] != -1)
                PQ.push_back(state(max(dp[s[i] + j][0], dp[s[i] + j][1]), i, 2, s[i] + j));
        }
        s[i + 1] = s[i] + N[i];
    }
    sort(PQ.begin(), PQ.end(), cmp);
    for(state t: PQ){
        if(t.val != -1){
            if(t.sign == 0){
                long long temp = even.get(1, 0, K - 1, 0, t.loc - 1) * even.get(1, 0, K - 1, t.loc + 1, K - 1);
                temp %= MOD;
                temp *= t.val;
                temp %= MOD;
                temp += ans;
                temp %= MOD;
                ans = temp;
                even.upd(1, 0, K - 1, t.loc);
            } 
            else if(t.sign == 1){
                long long temp = odd.get(1, 0, K - 1, 0, t.loc - 1) * odd.get(1, 0, K - 1, t.loc + 1, K - 1);
                temp %= MOD;
                temp *= t.val;
                temp %= MOD;
                temp += ans;
                temp %= MOD;
                ans = temp;
                odd.upd(1, 0, K - 1, t.loc);
            }
            else{
                long long temp = both.get(1, 0, K - 1, 0, t.loc - 1) * both.get(1, 0, K - 1, t.loc + 1, K - 1);
                temp %= MOD;
                temp *= t.val;
                temp %= MOD;
                temp = ans - temp;
                temp += MOD;
                temp %= MOD;
                ans = temp;
                both.upd(1, 0, K - 1, t.loc);
            }
        }
    }
    cout << ans << "\n";
}