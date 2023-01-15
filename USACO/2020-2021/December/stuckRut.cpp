#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 2005;

int N, x[MAXN], y[MAXN], sz[MAXN], stoppedby[MAXN], when[MAXN];
char d[MAXN];
vector<int> adj[MAXN];

void dfs(int i){
    sz[i]++;
    for(int v: adj[i]){
        dfs(v);
        sz[i] += sz[v];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> d[i] >> x[i] >> y[i];
        stoppedby[i] = -1;
    }
    priority_queue<pair<pair<int, int>, pair<int, int> > >PQ;
    //time, timeneededforcow2, cow stopped, cow going
    for(int i = 0; i < N; i++) if(d[i] == 'N'){
        for(int j = 0; j < N; j++) if(d[j] == 'E'){
            if(x[j] <= x[i] && y[i] <= y[j]){
                int ti = y[j] - y[i];
                int tj = x[i] - x[j];
                if(tj < ti){
                    PQ.push(make_pair(make_pair(-ti, -tj), make_pair(i, j)));
                }
                else if(tj > ti){
                    PQ.push(make_pair(make_pair(-tj, -ti), make_pair(j, i)));
                }
            }
        }
    }
    while(!PQ.empty()){
        pair<pair<int, int>, pair<int, int> > temp = PQ.top();
        temp.first.first = -temp.first.first;
        temp.first.second = -temp.first.second;
        PQ.pop();
        if(stoppedby[temp.second.first] == -1 && (stoppedby[temp.second.second] == -1 || when[temp.second.second] >= temp.first.second)){
            stoppedby[temp.second.first] = temp.second.second;
            when[temp.second.first] = temp.first.first;
            adj[temp.second.second].push_back(temp.second.first);
        }
    }
    for(int i = 0; i < N; i++){
        if(stoppedby[i] == -1){
            dfs(i);
        }
        // cout << i + 1 << " " << stoppedby[i] + 1 << "\n";
    }
    for(int i = 0; i < N; i++){
        cout << sz[i] - 1 << "\n";
    }




}
