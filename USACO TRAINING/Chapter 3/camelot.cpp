/*
ID: divadxl1
LANG: C++
TASK: camelot
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXR = 27;
const int MAXC = 31;

int ans, R, C, pos[1000][2], d[MAXR][MAXC];
bool ok[MAXR][MAXC];
vector<pair<int, int> > p[MAXR][MAXC];
queue<pair<int, int> > q;

void check(int x, int y, int nx, int ny){
    if(nx >= 0 && nx < R && ny < C && ny >= 0){
        if(d[x][y] + 1 == d[nx][ny]){
            p[nx][ny].push_back(make_pair(x, y));
        }
        else if(d[nx][ny] == -1){
            d[nx][ny] = d[x][y] + 1;
            p[nx][ny].push_back(make_pair(x, y));
            q.push(make_pair(nx, ny));
        }
    }
}

void bfs(int i, int j){
    q.push(make_pair(i, j));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        check(x, y, x + 2, y + 1);
        check(x, y, x - 2, y + 1);
        check(x, y, x + 2, y - 1);
        check(x, y, x - 2, y - 1);
        check(x, y, x + 1, y + 2);
        check(x, y, x - 1, y + 2);
        check(x, y, x + 1, y - 2);
        check(x, y, x - 1, y - 2);
        q.pop();
    }
}

int main(){
    setIO("camelot");
    cin >> C >> R;
    int c = 0;
    ans = 1e9;
    /*while(!cin.eof()){
        char t;
        cin >> t;
        pos[c][1] = t - 'A';
        cin >> pos[c][0];
        pos[c][0]--;
        c++;
    }*/
    while(!cin.eof()){
        char t;
        cin >> t;
        pos[c][0] = t - 'A';
        cin >> pos[c][1];
        pos[c][1]--;
        c++;
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            for(int a = 0; a < R; a++){
                for(int b = 0; b < C; b++){
                    d[a][b] = -1;
                    p[a][b].clear();
                    ok[a][b] = false;
                }
            }
            int tot = 0;
            d[i][j] = 0;
            bfs(i, j);
            int mn = max(abs(pos[0][0] - i), abs(pos[0][1] - j));
            bool solvable = true;
            for(int k = 1; k < c; k++){
                if(d[pos[k][0]][pos[k][1]] == -1){
                    solvable = false;
                    break;
                }
                tot += d[pos[k][0]][pos[k][1]];
                queue<pair<int, int> > t;
                t.push(make_pair(pos[k][0], pos[k][1]));
                while(!t.empty()){
                    int x = t.front().first;
                    int y = t.front().second;
                    mn = min(mn, max(abs(pos[0][0] - x), abs(pos[0][1] - y)));
                    t.pop();
                    for(auto it: p[x][y]){
                        if(!ok[it.first][it.second]){
                            ok[it.first][it.second] = true;
                            t.push(it);
                        }
                    }
                }
            }
            if(solvable)
                ans = min(ans, tot + mn);
        }
    }
    cout << ans << "\n";
}