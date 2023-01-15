#include <iostream>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 3e5 + 1;

int N, K, pre[MAXN], dp[MAXN];
multiset<int> el;
multiset<int> cand[MAXN];

int main(){
    setIO("redistricting");
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        pre[i] = pre[i - 1];
        char x;
        cin >> x;
        if(x == 'H')
            pre[i]++;
        else
            pre[i]--;
    }
    el.insert(0);
    cand[0].insert(0);
    for(int i = 1; i <= N; i++){
        int c = *el.begin();
        if(*cand[c].begin() >= pre[i])
            dp[i] = c + 1;
        else
            dp[i] = c; 
        el.insert(dp[i]);
        cand[dp[i]].insert(pre[i]);
        if(i >= K){
            cand[dp[i - K]].erase(cand[dp[i - K]].find(pre[i - K]));
            el.erase(el.find(dp[i - K]));
        }
    }
    cout << dp[N];



}