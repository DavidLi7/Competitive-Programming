/*
ID: divadxl1
LANG: C++
TASK: comehome
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

const int MAXN = 10000;

int N;
vector<pair<int, int> > adj[52];
bool vis[MAXN];

int index(char a){
    if(a - 'a' >= 0 && a - 'a' < 26)
        return a - 'a';
    else
        return 26 + a - 'A';
    
}

int main(){
    setIO("comehome");
    cin >> N;
    for(int i = 0; i < N; i++){
        char a, b;
        int c;
        cin >> a >> b >> c;
        int A = index(a);
        int B = index(b);
        adj[A].push_back(make_pair(B, c));
        adj[B].push_back(make_pair(A, c));
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    for(auto it: adj[51]){
        PQ.push(make_pair(it.second, it.first));
    }
    vis[51] = true;
    while(!PQ.empty()){
        pair<int, int> temp = PQ.top();
        PQ.pop();
        if(vis[temp.second])
            continue;
        vis[temp.second] = true;
        if(temp.second >= 26){
            cout << char(temp.second - 26 + 'A') << " " << temp.first<<endl;
            return 0;
        }
        for(auto it: adj[temp.second]){
            if(!vis[it.first]){
                PQ.push(make_pair(temp.first + it.second, it.first));
            }
        }
    }


}