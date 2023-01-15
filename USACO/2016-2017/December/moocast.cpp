#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1005;

int N;
long long d[MAXN], x[MAXN], y[MAXN];
bool vis[MAXN];

long long dist2(int a, int b){
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

void prims(){
    for(int i = 0; i <= N; i++)
        d[i] = 1e18;
    for(int it = 0; it < N; it++){
        int mini = 0;
        for(int i = 1; i <= N; i++){
            if(!vis[i] && (mini == 0 || d[i] < d[mini]))
                mini = i;
        }
        vis[mini] = true;
        for(int j = 1; j <= N; j++){
            if(!vis[j]){
                d[j] = min(d[j], dist2(mini, j));
            }
        }
    }
}

int main(){
    setIO("moocast");
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> y[i];
    }
    prims();
    sort(d + 1, d + N + 1);
    cout << d[N - 1];
}