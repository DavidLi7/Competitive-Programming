/*
ID: divadxl1
LANG: C++
TASK: cowtour
*/
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

#define s second
#define f first

const int MAXN = 155;

int x[MAXN], y[MAXN], N, comp[MAXN];
long double d[MAXN];
bool path[MAXN][MAXN], vis[MAXN];

long double dist(int a, int b){
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}


int main(){
    setIO("cowtour");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char x;
            cin >> x;
            path[i][j] = x == '1';
        }
    }
    int com = 1;
    long double m = 0;
    for(int i = 0; i < N; i++){
        if(comp[i] == 0){
            comp[i] = com++;
        }
        priority_queue<pair<long double, int>, vector<pair<long double, int> >, greater<pair<long double, int> > > PQ;
        for(int j = 0; j < N; j++){
            if(path[i][j])
                PQ.push(make_pair(dist(i, j), j));
            vis[j] = false;
        }
        vis[i] = true;
        while(!PQ.empty()){
            pair<long double, int> temp = PQ.top();
            PQ.pop();
            if(vis[temp.s])
                continue;
            comp[temp.s] = comp[i];
            vis[temp.s] = true;
            d[i] = max(d[i], temp.f);
            m = max(m, temp.f);
            for(int j = 0; j < N; j++){
                if(path[temp.s][j] && !vis[j]){
                    PQ.push(make_pair(temp.f + dist(temp.s, j), j));
                }
            }
        }
    }
    long double ans = 1e9;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(comp[i] != comp[j]){
                ans = min(ans, d[i] + d[j] + dist(i, j));
            }
        }
    }
    cout << setprecision(6) << fixed << max(ans, m) << "\n";
    
    
    

    


}