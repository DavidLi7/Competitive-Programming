#include <iostream>
#include <cmath>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;

long long N, K, a[MAXN];

int main(){
    setIO("tallbarn");

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    long double lo = 0;
    long double hi = 1e12;
    while(hi - lo > 0.00000001){
        long double mid = (lo + hi) / 2;
        long long tot = 0;
        for(int i = 0; i < N; i++){
            tot += ceil((-1 + sqrt(1 + 4 * a[i] / mid)) / 2);
        }
        if(tot <= K){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }

    //cout << lo << " " <<hi << endl;
    long long t = 0;
    long double ans = 0;
    for(int i = 0; i < N; i++){
        long long c = ceil((-1 + sqrt(1 + 4 * a[i] / hi)) / 2);
        ans += (long double)a[i] / c;
        t += c;
        //cout << c << endl;
    }
    ans -= (K - t) * hi;
    long long as = round(ans);
    //cout << ans << " " << as;
    cout << as;



}

