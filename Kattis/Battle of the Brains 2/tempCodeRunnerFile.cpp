#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

const int MAXN = 10005;

struct sprinkler{
    double l, r;
};

bool operator < (const sprinkler& x, const sprinkler& y){
    if(x.l == y.l)
        return x.r < y.r;
    return x.l < y.l;
}

int N, dp[MAXN];
long double L, W;
sprinkler s[MAXN];

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
    while(cin >> N){
        cin >> L >> W;
        for(int i = 0; i < N; i++){
            long double x, r;
            cin >> x >> r;
            long double dist = sqrt(r * r - (W / 2.0) * (W / 2.0));
            s[i].r = min(x + dist, L);
            s[i].l = max(x - dist, (long double)0.0);
        }
        sort(s, s + N);
        map<long double, int> m;//dist, sprinklers
        m[0] = 0;
        for(int i = 0; i < N; i++){
            map<long double, int>::iterator temp = m.lower_bound(s[i].l);
            if(temp == m.end())
                continue;
            dp[i] = (*m.lower_bound(s[i].l)).second + 1;
            // cout << i << " " << s[i].l << " " << s[i].r << " " << dp[i] << "\n";
            map<long double, int>::iterator it = m.lower_bound(s[i].r);
            if(it != m.end() && (*it).second <= dp[i])
                continue;
            it = prev(it);
            while(dp[i] <= (*it).second){
                long double curr = (*it).first;
                m.erase(it);
                it = prev(m.upper_bound(curr));
            }
            m[s[i].r] = dp[i];

        }
        if(m.find(L) == m.end())
            cout << -1 << "\n";
        else
            cout << m[L] << "\n";
    }
    

        
    
    
}