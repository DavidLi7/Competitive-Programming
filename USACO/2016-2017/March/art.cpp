#include <iostream>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1001;

int N, grid[MAXN][MAXN], pre[MAXN][MAXN], c[MAXN*MAXN][4];
set<int>cs;

int main(){
    setIO("art");

    cin >> N;
    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 0){
                continue;
            }
            if(cs.find(grid[i][j]) == cs.end()){
                cs.insert(grid[i][j]);
                c[grid[i][j]][0] = i;
                c[grid[i][j]][1] = i;
                c[grid[i][j]][2] = j;
                c[grid[i][j]][3] = j;
            }
            c[grid[i][j]][0] = min(i, c[grid[i][j]][0]);
            c[grid[i][j]][1] = max(i, c[grid[i][j]][1]);
            c[grid[i][j]][2] = min(j, c[grid[i][j]][2]);
            c[grid[i][j]][3] = max(j, c[grid[i][j]][3]);
        }
    }

    for(int x:cs){
        int x1 = c[x][0];
        int x2 = c[x][1];
        int y1 = c[x][2];
        int y2 = c[x][3];
        pre[x1][y1]++;
        pre[x1][y2 + 1]--;
        pre[x2 + 1][y1]--;
        pre[x2 + 1][y2 + 1]++;
    }
    set<int>a;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != 0)
                pre[i][j] += pre[i - 1][j];
            if(j != 0)
                pre[i][j] += pre[i][j - 1];
            if(i != 0 && j != 0)
                pre[i][j] -= pre[i - 1][j - 1];
            if(pre[i][j]>1)
                a.insert(grid[i][j]);
        }
    }
    if(cs.size() == 1){
        cout << N * N - 1;
    }
    else
        cout << N * N - a.size();

}