/*
ID: divadxl1
LANG: C++
TASK: fence6
*/
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct state{
    int dist, loc, p;
    set<int> vis;
    state(int d, int l, int pre, set<int> t) : dist(d), loc(l), p(pre), vis(t) {}
    bool operator < (const state &s1) const{
        return dist > s1.dist;
    }
};

const int MAXN = 100;

int N, len[MAXN];
set<int> adj1[MAXN], adj2[MAXN];

int main(){
    setIO("fence6");
    cin >> N;
    priority_queue<state> PQ;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        x--;
        cin >> len[x];
        int N1, N2;
        cin >> N1 >> N2;
        for(int j = 0; j < N1; j++){
            int t;
            cin >> t;
            t--;
            if(t > x){
                set<int> temp;
                temp.insert(x);
                PQ.push(state(len[x], t, x, temp));
            }
            adj1[x].insert(t);
        }
        for(int j = 0; j < N2; j++){
            int t;
            cin >> t;
            t--;
            if(t > x){
                set<int> temp;
                temp.insert(x);
                PQ.push(state(len[x], t, x, temp));
            }
            adj2[x].insert(t);
        }
    }
    int ans = -1;
    while(!PQ.empty()){
        state temp = PQ.top();
        PQ.pop();
        if(temp.vis.find(temp.loc) != temp.vis.end()){
            ans = temp.dist;
            break;
        }
        temp.vis.insert(temp.loc);
        if(adj1[temp.loc].find(temp.p) != adj1[temp.loc].end()){
            for(int t: adj2[temp.loc]){
                PQ.push(state(temp.dist + len[temp.loc], t, temp.loc, temp.vis));
            }
        }
        else{
            for(int t: adj1[temp.loc]){
                PQ.push(state(temp.dist + len[temp.loc], t, temp.loc, temp.vis));
            }
        }
    }
    cout << ans << "\n";
    
    

}