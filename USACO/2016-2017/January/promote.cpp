#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100000;

int N, s[MAXN], pre[MAXN], curr, BIT[MAXN+5], ans[MAXN];
pair<int, int> p[MAXN];
vector<int> adj[MAXN];

void dfs(int i, int par){
    pre[i] = curr++;
    for(int v:adj[i]) if(v != par){
        dfs(v, i);
        s[i] += s[v] + 1;
    }
}

void update(int i){
    i++;
    while(i<MAXN+5){
        BIT[i]++;
        i += i & -i;
    }
}

int get(int i){
    i++;
    int ret = 0;
    while(i > 0){
        ret += BIT[i];
        i -= i & -i;
    }
    return ret;
}

int main(){
    setIO("promote");

    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        p[i] = make_pair(x, i);
    }
    sort(p, p + N);
    for(int i = 1; i < N; i++){
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(0, -1);
    for(int i = N - 1; i >= 0; i--){
        int j = p[i].second;
        ans[j] = get(pre[j] + s[j]) - get(pre[j]);
        update(pre[j]);
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << "\n";
    }


}