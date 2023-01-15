#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 5005;

int N, tot[MAXN], curr[MAXN], pre[MAXN];
vector<int> adj[MAXN];
long long ans;

int dfs1(int i, int p = -1, int d = 0){
    tot[d]++;
    int ret = d;
    for(int v: adj[i]) if(v != p)
        ret = max(ret, dfs1(v, i, d + 1));
    return ret;
}

int dfs2(int i, int p, int d = 1){
    curr[d]++;
    int ret = d;
    for(int v: adj[i]) if(v != p)
        ret = max(ret, dfs2(v, i, d + 1));
    return ret;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
 
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;//0-indexes
        adj[a].push_back(b);//a->b
        adj[b].push_back(a);//b->a
    }

    if(N < 4){
        cout << 0;
        return 0;
    }

    for(int i = 0; i < N; i++){//picking a central node
        int d1 = dfs1(i);
        for(int v: adj[i]){
            int d2 = dfs2(v, i);
            for(int d = 1; d <= d2; d++){
                ans += pre[d] * curr[d] * (tot[d] - pre[d] - curr[d]);
                pre[d] += curr[d];
                curr[d] = 0;
            }
        }
        for(int d = 0; d <= d1; d++){
            tot[d] = 0;
            pre[d] = 0;
            curr[d] = 0;
        }
    }

    cout << ans;

}