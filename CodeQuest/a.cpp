#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int T, H, W, sx, sy, ex, ey;
vector<string> g;
vector<bool> vis;
int dx[] = {-2, 2, 0, 0};
int dy[] = {0, 0, 3, -3};
int dx2[] = {-1, 1, 0, 0};
int dy2[] = {0, 0, 1, -2};

// void dfs(int x, int y, int c){
//     //cout << x << " " << y << " " << c << "\n";
//     vis[W * x + y] = true;
//     if(x == ex && y == ey){
//         ans = c;
//         return;
//     }
//     int ret = 1e9;
//     for(int i = 0; i < 4; i++){
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         int nx2 = x + dx2[i];
//         int ny2 = y + dy2[i];
//         if(nx < H && nx >= 0 && ny < W && ny >= 0 && !vis[nx * W + ny] && g[nx2][ny2] == ' '){
//             dfs(nx, ny, c + 1);
//         }
//     }
// }

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
    
    cin >> T;
    while(T--){
        cin >> H >> W;
        string s;
        getline(cin, s);
        g.clear();
        vis.clear();
        for(int i = 0; i < H; i++){
            getline(cin, s);
            g.push_back(s);
            for(int j = 0; j < W; j++)
                vis.push_back(false);
        }
        for(int i = 0; i < H; i++){
            if(g[i][0] == '<'){
                ex = i;
                ey = 2;
            }
            if(g[i][0] == '>'){
                sx = i;
                sy = 2;
            }
            if(g[i][W - 1] == '>'){
                ex = i;
                ey = W - 2;
            }
            if(g[i][W - 1] == '<'){
                sx = i;
                sy = W - 2;
            }
        }
        for(int j = 2; j < W; j += 3){
            if(g[0][j] == '^'){
                ex = 1;
                ey = j;
            }
            if(g[0][j] == 'v'){
                sx = 1;
                sy = j;
            }
            if(g[H - 1][j] == 'v'){
                ex = H - 2;
                ey = j;
            }
            if(g[H - 1][j] == '^'){
                sx = H - 2;
                sy = j;
            }
        }
        //cout << sx << " " << sy << " " << ex << " " << ey << "\n";
        //dfs(sx, sy, 1);
        queue<pair<int, int> > q;
        int ans = -1;
        q.push(make_pair(sx * W + sy, 1));
        while(q.size()){
            pair<int, int> temp = q.front();
            q.pop();
            int x = temp.first / W;
            int y = temp.first % W;
            //cout << x << " " << y << "\n";
            vis[W * x + y] = true;
            if(x == ex && y == ey){
                ans = temp.second;
                break;
            }
            int ret = 1e9;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nx2 = x + dx2[i];
                int ny2 = y + dy2[i];
                if(nx < H && nx >= 0 && ny < W && ny >= 0 && !vis[nx * W + ny] && g[nx2][ny2] == ' '){
                    //dfs(nx, ny, c + 1);
                    q.push(make_pair(nx * W + ny, temp.second + 1));
                }
            }
        }
        //cout << dfs(sx, sy, 1) << "\n";
        cout << ans << "\n";
    }
}

