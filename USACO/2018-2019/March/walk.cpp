#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 7505;
const long long MOD = 2019201997;

int N, K;
long long d[MAXN];
bool vis[MAXN];

long long getDist(long long a, long long b){
    if(a > b)
        swap(a, b);
    return ((2019201913 * a) % MOD + (2019201949 * b) % MOD) % MOD;
}

void prims(){
    for(int i = 1; i <= N; i++){
        d[i] = 2019201997;
    }
    for(int it = 1; it <= N; it++){
        int mini = 0;
        for(int i = 1; i <= N; i++){
            if(!vis[i]){
                if(mini == 0 || (d[i] < d[mini]))
                    mini = i;
            }
        }
        vis[mini] = true;
        for(int i = 1; i <= N; i++){
            if(!vis[i]){
                d[i] = min(d[i], getDist(i, mini));
            }
        }
        if(it == 1)
            d[mini] = 0;
    }
}

int main(){
    setIO("walk");
    cin >> N >> K;
    prims();
    sort(d + 1, d + N + 1);
    // for(int i = 1; i <= N; i++){
    //     cout << d[i] << "\n";
    // }
    cout << d[N - K + 2];
}