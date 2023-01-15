#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1005;

int N, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool a[MAXN][MAXN], vis[MAXN][MAXN];
pair<int, int> curr, ans;

void dfs(int i, int j){
    curr.first++;
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int newx = i + dx[k];
        int newy = j + dy[k];
        if(vis[newx][newy])
            continue;
        if(a[newx][newy])
            dfs(newx, newy);
        else
            curr.second--;
    }
}

int main(){
    //setIO("perimeter");
    cin >> N;
    for(int i = 1; i <= N; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= N; j++){
            a[i][j] = (s[j - 1] == '#');
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) if(a[i][j] && !vis[i][j]){
            curr.first = curr.second = 0;
            dfs(i, j);
            ans = max(ans, curr);
        }
    }
    cout << ans.first << " " << -ans.second;
}