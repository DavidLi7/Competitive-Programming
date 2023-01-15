#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 5e4 + 5;
const int MAXK = 55;

int N, K, b[MAXN], s[MAXK][MAXK], dist[MAXN];
set<int> cows[MAXK];
vector<int> adj[MAXN];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> b[i];
        b[i]--;
        cows[b[i]].insert(i);
    }
    for(int i = 0; i < K; i++){
        string t;
        cin >> t;
        for(int j = 0; j < K; j++){
            s[i][j] = t[j] - '0';
        }
    }
    for(int i = 0; i < N; i++){
        dist[i] = -1;
        for(int j = 0; j < K; j++){
            if(s[b[i]][j]){
                set<int>::iterator mr = cows[j].upper_bound(i);
                if(mr != cows[j].end())
                    adj[i].push_back(*mr);
                set<int>::iterator ml = cows[j].lower_bound(i);
                if(ml != cows[j].begin())
                    adj[i].push_back(*prev(ml));
                if(j == b[N - 1])
                    adj[i].push_back(N - 1);
            }
        }
    }
    priority_queue<pair<int, int> >PQ;
    PQ.push(make_pair(0, 0));
    while(PQ.size()){
        pair<int, int> temp = PQ.top();
        PQ.pop();
        if(dist[temp.second] != -1)
            continue;
        dist[temp.second] = -temp.first;
        for(int v: adj[temp.second]) if(dist[v] == -1){
            PQ.push(make_pair(temp.first - (abs(v - temp.second)), v));
        }
    }
    cout << dist[N - 1];
    


}