/*
ID: divadxl1
LANG: C++
TASK: maze1
*/
#include <iostream>
#include <string>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

char grid[205][205];
int dist[205][205];
bool vis[205][205];
int W, H;

void dfs(int i, int j, int d){
    if(i <= 0 || i >= 2 * H || j <= 0 || j >= 2 * W || d >= dist[i][j])
        return;
    vis[i][j] = true;
    dist[i][j] = d;
    if(grid[i + 1][j] != '-')
        dfs(i + 2, j, d + 1);
    if(grid[i - 1][j] != '-')
        dfs(i - 2, j, d + 1);
    if(grid[i][j + 1] != '|')
        dfs(i, j + 2, d + 1);
    if(grid[i][j - 1] != '|')
        dfs(i, j - 2, d + 1);
}


int main(){
    setIO("maze1");
    cin >> W >> H;
    for(int i = 0; i < 2 * H + 1; i++){
        for(int j = 0; j < 2 * W + 1; j++){
            grid[i][j] = cin.get();
            dist[i][j] = 1e9;
            if(grid[i][j] == '\n')
                grid[i][j] = cin.get();
        };
    }
    for(int i = 0; i < 2 * H + 1; i++){
        for(int j = 0; j < 2 * W + 1; j++){
            if(grid[i][j] == ' '){
                if(i == 0)
                    dfs(1, j, 1);
                else if(j == 0)
                    dfs(i, 1, 1);
                else if(i == 2 * H)
                    dfs(2 * H - 1, j, 1);
                else if(j == 2 * W)
                    dfs(i, 2 * W - 1, 1);
            }
        }
    }
    int mx = 0;
    for(int i = 1; i < 2 * H + 1; i+=2){
        for(int j = 1; j < 2 * W + 1; j+=2){
            mx = max(mx, dist[i][j]);
        }
    }
    cout << mx << "\n";

}