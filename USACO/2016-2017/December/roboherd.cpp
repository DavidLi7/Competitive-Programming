#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct loc{
    int M;
    vector<long long> P;
    long long delta;
    bool operator<(const loc& y) const {
        return y.delta < delta;
    }
};

const int MAXN = 100005;
const int MAXM = 10;
const int MAXP = 100000001;

int N, K, c;
loc L[MAXN];
long long ans, lo, hi, mn;

void count(long long price, int i = 0){
    if(c >= K)
        return;
    //find first position such that L[i].P[1] <= price
    if(i != N && L[i].P[1] > price){
        int lo2 = i;
        int hi2 = N;
        while(lo2 < hi2 - 1){
            int mid = (lo2 + hi2) / 2;
            if(L[mid].P[1] <= price){
                hi2 = mid;
            }
            else{
                lo2 = mid;
            }
        }
        i = hi2;
    }
    if(i == N){
        c++;
        return;
    }
    for(int j = 0; j < L[i].M && L[i].P[j] <= price && c < K; j++){
        count(price - L[i].P[j], i + 1);
    }
}

void solve(long long price, int i = 0){
    if(c >= K)
        return;
    //find first position such that L[i].P[1] <= price
    if(i != N && L[i].P[1] > price){
        int lo2 = i;
        int hi2 = N;
        while(lo2 < hi2 - 1){
            int mid = (lo2 + hi2) / 2;
            if(L[mid].P[1] <= price){
                hi2 = mid;
            }
            else{
                lo2 = mid;
            }
        }
        i = hi2;
    }
    if(i == N){
        c++;
        ans += (lo - price);
        return;
    }
    for(int j = 0; j < L[i].M && L[i].P[j] <= price && c < K; j++){
        solve(price - L[i].P[j], i + 1);
    }
}

int main(){
    setIO("roboherd");
    cin >> N >> K;
    int k = 0;
    for(int i = 0; i < N; i++){
        cin >> L[k].M;
        L[k].P.resize(L[k].M);
        for(int j = 0; j < L[k].M; j++){
            cin >> L[k].P[j];
        }
        sort(L[k].P.begin(), L[k].P.end());
        mn += L[k].P[0];
        if(L[k].M == 1)
            continue;
        for(int j = L[k].M - 1; j >= 0; j--){
            L[k].P[j] -= L[k].P[0];
        }
        L[k].delta = (L[k].M == 1) ? 0: (L[k].P[1]);
        hi += L[k].P[L[k].M - 1];
        k++;
    }
    N = k;
    sort(L, L + N);
    while(lo < hi - 1){
        long long mid = (lo + hi) / 2;
        c = 0;
        count(mid);
        if(c >= K){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    c = 0;
    ans = K * mn;
    solve(lo);
    ans += hi * (K - c);
    cout << ans;

}