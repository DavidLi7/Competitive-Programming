#include <iostream>
#include <vector>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;

int N, Q, sz[MAXN], pre[MAXN], curr, BIT1[MAXN + 5], BIT2[MAXN + 5];
vector<int> adj[MAXN];
set<int> C[MAXN];

void update1(int i, int a){
    i++;
    while(i < MAXN + 5){
        BIT1[i] += a;
        i += i & -i;
    }
}

int get1(int i){
    i++;
    int ret = 0;
    while(i > 0){
        ret += BIT1[i];
        i -= i & -i;
    }
    return ret;
}

void update2(int i, int a){
    i++;
    while(i < MAXN + 5){
        BIT2[i] += a;
        i += i & -i;
    }
}

int get2(int i){
    i++;
    int ret = 0;
    while(i > 0){
        ret += BIT2[i];
        i -= i & -i;
    }
    return ret;
}

void dfs(int i, int p){
    pre[i] = curr++;
    for(int v: adj[i]) if(v != p){
        dfs(v, i);
        sz[i] += sz[v] + 1;
    }
}

int main(){
    setIO("snowcow");

    cin >> N >> Q;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    dfs(0, -1);

    for(int i = 0; i < Q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int x, c;
            cin >> x >> c;
            x--; c--;
            bool useless = false;
            vector<int>cover;
            for(int it: C[c]){
                
                if(pre[it] <= pre[x] && pre[it] + sz[it] >= pre[x]){
                    useless = true;
                    break;
                }
                if(pre[x] <= pre[it] && pre[x] + sz[x] >= pre[it]){
                    cover.push_back(it);
                }
            }
            if(useless)
                continue;
            update1(pre[x], 1);
            update1(pre[x] + sz[x] + 1, -1);
            update2(pre[x], sz[x] + 1);
            for(int it: cover){
                C[c].erase(it);
                update1(pre[it], -1);
                update1(pre[it] + sz[it] + 1, 1);
                update2(pre[it], -sz[it] - 1);
            }
            C[c].insert(x);
        }
        else{
            int x;
            cin >> x;
            x--;
            int ret = get1(pre[x]) * (sz[x] + 1);
            ret += (get2(pre[x] + sz[x]) - get2(pre[x]));
            cout << ret << "\n";
        }
    }





}