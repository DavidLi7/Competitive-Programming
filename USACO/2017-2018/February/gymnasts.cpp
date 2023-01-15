#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MOD = 1e9 + 7;

ll N, ans;
vector<ll> fact;
vector<int> ct;

void getFact(ll x){
    if(x % 2 == 0){
        fact.push_back(2);
        int c = 0;
        while(x % 2 == 0){
            x /= 2;
            c++;
        }
        ct.push_back(c);
    }
    for(ll i = 3; i * i <= x; i += 2){
        if(x % i == 0){
            fact.push_back(i);
            int c = 0;
            while(x % i == 0){
                x /= i;
                c++;
            }
            ct.push_back(c);
        }
    }
    if(x > 2){
        fact.push_back(x);
        ct.push_back(1);
    }
}

ll power(ll a, ll b){
    long long ans = 1;
    while(b > 0){
        if(b & 1)
            ans = (ans * a) % MOD;
        b = b >> 1;
        a = (a * a) % MOD;
    }
    return ans;
}

ll euler(ll n){
    long long ret = n;
    for(ll p = 2; p * p <= n; p++){
        if(n % p == 0){
            while(n % p == 0)
                n /= p;
            ret /= p;
            ret *= (p - 1);
        }
    }
    if(n > 1){
        ret /= n;
        ret *= (n - 1);
    }
    return ret;
}

void dfs(int dist, ll curr){
    if(dist == fact.size()){
        if(curr == N)
            return;
        ll contribution = (power(2, curr) - 1 + MOD) % MOD;
        ll tot = contribution * (euler(N / curr)) % MOD;
        ans = (tot + ans) % MOD;
        //cout << curr << " " << tot << "\n";
        return;
    }
    ll prod = 1;
    for(int i = 0; i <= ct[dist]; i++){
        dfs(dist + 1, curr * prod);
        prod *= fact[dist];
    }
}

int main(){
    setIO("gymnasts");
    cin >> N;
    getFact(N);
    dfs(0, 1);
    cout << (ans + 1) % MOD;
}