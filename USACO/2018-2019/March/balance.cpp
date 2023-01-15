#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5 + 5;

ll N, l[MAXN], r[MAXN], linv, rinv, lz, rz, lo, ro, ans;

void solve1(){
    vector<ll> right;
    for(int i = N - 1; i >= 0; i--){
        if(r[i])
            right.push_back(i);
    }
    ll ps = 0;
    for(int i = N - 1; i >= 0 && l[i] == 1; i--)
        ps++;
    ll currm = 0;
    ll tr = rinv;
    ll tl = linv;
    ll j = N - 1LL - ps;
    for(ll i = lo + 1LL; i <= lo + ro && i <= N; i++){
        ll dist = right.back() + 1LL;
        right.pop_back();
        currm += ps;
        currm += dist;
        tl -= ((i - 1LL - ps));
        ps++;
        j--;
        for(; j >= 0LL && l[j]; j--)
            ps++;
        tr -= (N - dist - right.size());
        // tl += N - i - 1;
        // tl -= (ps - 1);
        ans = min(ans, currm + abs(tr - tl));
        //  cout << i << " " << tl << " " << tr << " " << currm << " " << ps << " " << currm + abs(tr - tl) << "\n";
    }
    // cout << "\n";
}

void solve2(){
    vector<ll> left;
    for(int i = 0; i < N; i++){
        if(l[i])
            left.push_back(i);
    }
    ll ps = 0;
    ll j = 0;
    for(; j < N && r[j] == 1; j++)
        ps++;
    ll currm = 0;
    ll tr = rinv;
    ll tl = linv;
    for(ll i = lo - 1LL; i >= 0LL && i >= lo + ro - N; i--){
        ll dist = N - left.back();
        left.pop_back();
        currm += ps;
        currm += dist;
        
        j++;
        tl -= (dist - 1LL);
        tl += left.size();
        tr += N - (lo + ro - i);
        tr -= (ps);
        ps++;
        for(; j < N && r[j]; j++)
            ps++;
        ans = min(ans, currm + abs(tr - tl));
        // cout << i << " " << tl << " " << tr << " " << currm << " " << ps << " " << currm + abs(tr - tl) << "\n";
    }
}

int main(){
    setIO("balance");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> l[i];
        if(l[i] == 0){
            lz++;
            linv += lo;
        }
        else{
            lo++;
        }
    }
    for(int i = 0; i < N; i++){
        cin >> r[i];
        if(r[i] == 0){
            rz++;
            rinv += ro;
        }
        else{
            ro++;
        }
    }
    ans = abs(rinv - linv);
    // cout << ans << "\n";
    solve1();
    solve2();
    cout << ans << "\n";
}