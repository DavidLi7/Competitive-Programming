#include <iostream>
#include <set>
#include <queue>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 20;

int N, L, dp[(1 << 20) + 1], D[MAXN];
set<int> st[MAXN];
bool pushed[(1 << 20) + 1];

int main(){
    setIO("movie");
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        int c;
        cin >> D[i] >> c;
        for(int j = 0; j < c; j++){
            int x;
            cin >> x;
            st[i].insert(x);
        }
    }
    queue<int> bfs;
    for(int i = 0; i < N; i++){
        if(*st[i].begin() == 0){
            bfs.push((1 << i));
            pushed[1 << i] = true;
            dp[(1 << i)] = D[i];
        }
    }
    while(bfs.size()){
        int t = bfs.front();
        bfs.pop();
        // for(int i = 0; i < N; i++){
        //     if(t & (1 << i))
        //         cout << 1;
        //     else
        //         cout << 0;
        // }
        // cout << " " << dp[t] << "\n";
        if(dp[t] >= L){
            int ans = 0;
            for(int i = 0; i < N; i++){
                if(t & (1 << i))
                    ans++;
            }
            cout << ans;
            return 0;
        }
        for(int i = 0; i < N; i++){
            int temp = (1 << i);
            if((t & temp) == 0){
                temp += t;
                //start time <= dp
                set<int>::iterator it = st[i].upper_bound(dp[t]);
                if(it == st[i].begin())
                    continue;
                it = prev(it);
                dp[temp] = max(dp[temp], *it + D[i]);
                if(!pushed[temp]){   
                    bfs.push(temp);
                    pushed[temp] = true;
                }
            }
        }
        // cout << t << " " << dp[t] << "\n";
        
    }
    cout << -1;
}