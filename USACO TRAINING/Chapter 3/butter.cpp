/*
ID: divadxl1
LANG: C++
TASK: butter
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 500;
const int MAXP = 800;

vector<pair<int, int> > adj[MAXP];
int N, P, C, c[MAXP], d[MAXP];


int main(){
    setIO("butter");
    cin >> N >> P >> C;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        c[x - 1]++;
    }
    for(int i = 0; i < C; i++){
        int a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        adj[a].push_back(make_pair(b, d));
        adj[b].push_back(make_pair(a, d));
    }
    int ans = 1e9;
    for(int i = 0; i < P; i++){
        for(int j = 0; j < P; j++){
            d[j] = -1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
        PQ.push(make_pair(0, i));
        while(!PQ.empty()){
            pair<int, int> temp = PQ.top();
            PQ.pop();
            if(d[temp.second] != -1)
                continue;
            d[temp.second] = temp.first;
            for(auto it: adj[temp.second]){
                if(d[it.first] == -1){
                    PQ.push(make_pair(it.second + temp.first, it.first));
                }
            }
        }
        int curr = 0;
        for(int j = 0; j < P; j++){
            curr += c[j] * d[j];
        }
        ans = min(ans, curr);
    }
    cout << ans << "\n";
}