#include <iostream>
#include <map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int N;
map<string, long long> m;
long long ans;

int main(){
    setIO("citystate");
    cin >> N;
    for(int i = 0; i < N; i++){
        string city, state;
        cin >> city >> state;
        if(city.substr(0, 2) != state)
            m[city.substr(0, 2) + state]++;
    }
    for(auto it: m){
        string other = it.first.substr(2, 2) + it.first.substr(0, 2);
        ans += it.second * m[other];
    }
    cout << ans / 2LL << "\n";
}