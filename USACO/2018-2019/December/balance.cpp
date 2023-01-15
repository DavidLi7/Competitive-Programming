#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;

int N;
vector<pair<ll, ll> > hull;

ll cross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    return (b.f - a.f) * (c.s - a.s) - (b.s - a.s) * (c.f - a.f);
}

int main(){
    setIO("balance");
    cin >> N;
    hull.push_back(make_pair(0, 0));
    int k = 1;
    for(int i = 1; i <= N; i++){
        ll y;
        cin >> y;
        pair<ll, ll> temp = make_pair(1LL * i, y);
        while(k >= 2 && cross(hull[k - 2], hull[k - 1], temp) >= 0){
            k--;
            hull.pop_back();
        }
        hull.push_back(temp);
        k++;
    }
    pair<ll, ll> temp = make_pair(1LL * (N + 1), 0);
    while(k >= 2 && cross(hull[k - 2], hull[k - 1], temp) >= 0){
        k--;
        hull.pop_back();
    }
    hull.push_back(temp);
    k++;
    for(int i = 0; i < k - 1; i++){
        for(ll j = hull[i].f + 1; j <= hull[i + 1].f && j <= N; j++){
            cout << (ll)((ll)100000 * ((ll)(1LL * j - hull[i].f) * (ld)(hull[i + 1].s - hull[i].s)) / (ll)(hull[i + 1].f - hull[i].f) + (ll)100000 * hull[i].s) << "\n";
        }
    }

}