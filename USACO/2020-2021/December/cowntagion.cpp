#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int N;
vector<int> adj[MAXN];
long long ans = 0;

void dfs(int i, int p){
    int temp = 1;
    while(temp <= (adj[i].size() - (i != 0))){
        temp *= 2;
        ans++;
    }
    for(int v: adj[i]) if(v != p){
        dfs(v, i);
        ans++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    int N;
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << ans;






}
