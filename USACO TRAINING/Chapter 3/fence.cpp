/*
ID: divadxl1
LANG: C++
TASK: fence
*/
#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 501;

int F;
multiset<int> adj[MAXN];
set<int> el;
stack<int> s;
stack<int> ans;

void dfs(int pos){
    //cout << pos << " ";
    //s.push(pos)
    int x = 0;
    for(multiset<int>::iterator it = adj[pos].upper_bound(x); it != adj[pos].end(); it = adj[pos].upper_bound(x)){
        x = *it;
        adj[pos].erase(adj[pos].find(x));
        adj[x].erase(adj[x].find(pos));
        //cout << x << " ";
        dfs(x);
    }
   // s.pop();
    ans.push(pos);
}

int main(){
    setIO("fence");
    cin >> F;
    int mn = 1e9;
    for(int i = 0; i < F; i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        el.insert(a);
        el.insert(b);
    }
    for(set<int>::iterator it = el.upper_bound(0); it != el.end(); it = el.upper_bound(*it)){
        if(adj[*it].size() % 2 == 1){
            dfs(*it);
            break;
        }
    }
    if(ans.size() == 0){
        dfs(*el.begin());
    }
    while(!ans.empty()){
        cout << ans.top() << "\n";
        ans.pop();
    }

}