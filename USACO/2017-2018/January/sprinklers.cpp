#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N;
ll y[MAXN];
vector<pair<ll, ll> > mx;
ll ans;

ll Nc2(ll n){
    n = n % MOD;
    return (n * (n - 1) / 2) % MOD;
}


ll solve(ll w, ll h){
    //cout << "s " << w << " " << h << "\n";
    return (w * Nc2(h + 1)) % MOD;
}

int main(){
    setIO("sprinklers");
    cin >> N;
    for(int i = 0; i < N; i++){
        int X, Y;
        cin >> X >> Y;
        y[X] = Y;
    }
    for(int i = N - 1; i >= 0; i--){
        if(mx.size() == 0 || y[i] > mx.back().second){
            mx.push_back(make_pair(i, y[i]));
        }
    }
    ll mny = 1e9;
    for(int i = 0; i < N - 1; i++){
        if(mx.back().first == i)
            mx.pop_back();
        mny = min(mny, y[i]);
        if(mny > mx.back().second)
            continue;
        ll prevx = i;
        for(int k = mx.size() - 1; k >= 0; k--){
            if(mny >= mx[k].second)
                break;
            ans += solve(mx[k].first - prevx, mx[k].second - mny);
            ans %= MOD;
            prevx = mx[k].first;
        }
        //cout << i << " " << ans << "\n";
    }
    if(ans < 0)
        ans += MOD;
    cout << ans;
}