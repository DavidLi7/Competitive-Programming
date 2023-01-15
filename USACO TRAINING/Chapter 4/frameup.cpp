/*
ID: divadxl1
LANG: C++
TASK: frameup
*/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 30;

int H, W, grid[MAXN][MAXN], l[MAXN], r[MAXN], b[MAXN], t[MAXN], in[MAXN], c;
vector<int> adj[MAXN];
bool vis[MAXN], exists[MAXN];
vector<char> curr(30);

void dfs(int i, int d){
    vector<string> temp;
    if(d == c){
        for(int i = 0; i < d; i++){
            cout << curr[i];
        }
        cout << "\n";
    }
    for(int v: adj[i]) if(!vis[v]){
        in[v]--;
    }
    for(int v = 0; v < MAXN; v++){
        if(!vis[v] && in[v] == 0){
            vis[v] = true;
            curr[d] = (char)(v + 'A');
            dfs(v, d + 1);
            vis[v] = false;
        }
    }
    for(int v: adj[i]) if(!vis[v]){
        in[v]++;
    }
}

int main(){
    setIO("frameup");
    cin >> H >> W;
    for(int i = 0; i < MAXN; i++){
        l[i] = -1;
        r[i] = -1;
        b[i] = -1;
        t[i] = -1;
    }
    for(int i = 0; i < H; i++){
        string s;
        cin >> s;
        for(int j = 0; j < W; j++){
            if(s[j] == '.')
                grid[i][j] = -1;
            else{
                grid[i][j] = s[j] - 'A';
                if(l[grid[i][j]] == -1){
                    l[grid[i][j]] = i;
                }
                if(t[grid[i][j]] == -1){
                    b[grid[i][j]] = j;
                }
                l[grid[i][j]] = min(l[grid[i][j]], i);
                b[grid[i][j]] = min(b[grid[i][j]], j);
                r[grid[i][j]] = max(r[grid[i][j]], i);
                t[grid[i][j]] = max(t[grid[i][j]], j);
            }
        }
    }
    for(int i = 0; i < MAXN; i++){
        if(l[i] == -1){
            vis[i] = true;
            continue;
        }

        c++;
        set<int> temp;
        for(int j = l[i]; j <= r[i]; j++){
            if(grid[j][t[i]] != i){
                temp.insert(grid[j][t[i]]);
            }
            if(grid[j][b[i]] != i){
                temp.insert(grid[j][b[i]]);
            }
        }
        for(int j = b[i]; j <= t[i]; j++){
            if(grid[l[i]][j] != i){
                temp.insert(grid[l[i]][j]);
            }
            if(grid[r[i]][j] != i){
                temp.insert(grid[r[i]][j]);
            }
        }
        for(set<int>::iterator it = temp.begin(); it != temp.end(); it++){
            adj[i].push_back(*it);
            in[*it]++;
        }
    }
    dfs(29, 0);
   

}