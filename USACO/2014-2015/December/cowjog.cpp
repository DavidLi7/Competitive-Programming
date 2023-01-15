#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

int N;
long long T;
multiset<long long> e;
pair<long long, long long> cows[MAXN];

int main(){
    setIO("cowjog");
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    for(int i = 0; i < N; i++){
        multiset<long long>::iterator it = e.lower_bound(cows[i].first + cows[i].second * T);
        if(it != e.begin())
            e.erase(e.find(*prev(it)));
        e.insert(cows[i].first + cows[i].second * T);
        // cout << e.size() << "\n";
    }
    cout << e.size();
}