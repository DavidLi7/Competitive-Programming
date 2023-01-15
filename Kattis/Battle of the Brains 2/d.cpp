#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

const int MAXN = 10005;

struct sprinkler{
    long double l, r;
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
        int ans = 0;
        long double curr = 0;
        while(curr < L){
            long double mx = curr;
            for(int i = 0; i < N; i++){
                if(s[i].l <= curr && s[i].r > curr){
                    mx = max(mx, s[i].r);
                }
            }
            if(mx == curr){
                ans = -1;
                break;
            }
            ans++;
            curr = mx;
        }
        cout << ans << "\n";
    }
    

        
    
    
}