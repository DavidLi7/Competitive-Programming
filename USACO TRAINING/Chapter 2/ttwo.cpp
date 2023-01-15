/*
ID: divadxl1
LANG: C++
TASK: ttwo
*/
#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

char grid[10][10];
bool vis[10][10][10][10][4][4];
int dx[4] = {-1, 0, 1 , 0};
int dy[4] = {0, 1 , 0, -1};

int main(){
    setIO("ttwo");
    int cx, cy, jy, jx;
    int cd = 0;
    int jd = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'F'){
                jx = i;
                jy = j;
            }
            else if(grid[i][j] == 'C'){
                cx = i;
                cy = j;
            }
        }
    }
    int ans = 0;
    while(true){
        if(vis[cx][cy][jx][jy][cd][jd]){
            ans = 0;
            break;
        }
        if(cx == jx && cy == jy){
            break;
        }
        vis[cx][cy][jx][jy][cd][jd] = true;
        cx += dx[cd];
        cy += dy[cd];
        if(cx == -1 || cx == 10 || cy == -1 || cy == 10 || grid[cx][cy] == '*'){
            cx -= dx[cd];
            cy -= dy[cd];
            cd++;
            cd %= 4;
        }
        jx += dx[jd];
        jy += dy[jd];
        if(jx == -1 || jx == 10 || jy == -1 || jy == 10 || grid[jx][jy] == '*'){
            jx -= dx[jd];
            jy -= dy[jd];
            jd++;
            jd %= 4;
        }
        ans++;
    }
    cout << ans << "\n";
    

}