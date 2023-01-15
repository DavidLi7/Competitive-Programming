/*
ID: divadxl1
LANG: C++
TASK: agrinet
*/

#include <iostream>
#include <queue>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100;

int N, dist[MAXN][MAXN], d[MAXN];

bool vis[MAXN];

int main(){
    setIO("agrinet");
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dist[i][j];
        }
    }
    vis[0] = true;
    d[0] = 0;
    for(int i = 0; i < N; i++){
        d[i] = dist[0][i];
    }
    int ans = 0;
    for(int i = 1; i < N; i++){
        int mnx = -1;
        for(int j = 0; j < N; j++){
            if(!vis[j] && (mnx == -1 || d[j] < d[mnx])){
                mnx = j;
            }
        }
        ans += d[mnx];
        vis[mnx] = true;
        for(int j = 0; j < N; j++){
            d[j] = min(d[j], dist[j][mnx]);
        }
    }
    cout << ans << "\n";
}