#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAXN = 1e5 + 5;

int N, M, K;
vector<vector<int> > grid, ED, b1, b2;
vector<vector<bool> > vis;
vector<pair<int, int> > R;
vector<int> mn;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void findED(){
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > PQ;
    for(int i = 0; i < N; i++){
        PQ.push(make_pair(grid[i][0], make_pair(i, 0)));
        PQ.push(make_pair(grid[i][M - 1], make_pair(i, M - 1)));
    }
    for(int j = 1; j < M - 1; j++){
        PQ.push(make_pair(grid[0][j], make_pair(0, j)));
        PQ.push(make_pair(grid[N - 1][j], make_pair(N - 1, j)));
    }
    while(!PQ.empty()){
        pair<int, pair<int, int> > temp = PQ.top();
        PQ.pop();
        if(ED[temp.second.first][temp.second.second] != -1)
            continue;
        ED[temp.second.first][temp.second.second] = temp.first;
        for(int i = 0; i < 4; i++){
            int newx = temp.second.first + dx[i];
            int newy = temp.second.second + dy[i];
            if(newx != -1 && newx != N && newy != -1 && newy != M && ED[newx][newy] == -1){
                PQ.push(make_pair(temp.first + grid[newx][newy], make_pair(newx, newy)));
            }
        }
    }
}

int findB(int a, int b){
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > PQ;
    PQ.push(make_pair(0, make_pair(a, b)));
    int ret = -1;
    while(!PQ.empty()){
        pair<int, pair<int, int> > temp = PQ.top();
        PQ.pop();
        if(vis[temp.second.first][temp.second.second])
            continue;
        vis[temp.second.first][temp.second.second] = true;
        if(temp.first < b2[temp.second.first][temp.second.second]){
            b2[temp.second.first][temp.second.second] = temp.first;
            if(b2[temp.second.first][temp.second.second] < b1[temp.second.first][temp.second.second]){
                swap(b2[temp.second.first][temp.second.second], b1[temp.second.first][temp.second.second]);
            }
        }
        else if(ret != -1)
            continue;
        if((temp.second.second == 0 || temp.second.first == 0 || temp.second.first == N - 1 || temp.second.second == M - 1) && ret == -1){
            ret = temp.first;
        }
        for(int i = 0; i < 4; i++){
            int newx = temp.second.first + dx[i];
            int newy = temp.second.second + dy[i];
            if(newx != -1 && newx != N && newy != -1 && newy != M && !vis[newx][newy]){
                PQ.push(make_pair(temp.first + grid[newx][newy], make_pair(newx, newy)));
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;
    grid.resize(N);
    ED.resize(N);
    b1.resize(N);
    b2.resize(N);
    vis.resize(N);
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        b1[i].resize(M);
        b2[i].resize(M);
        ED[i].resize(M);
        grid[i].resize(M);
        vis[i].resize(M);
        for(int j = 0; j < M; j++){
            ED[i][j] = -1;
            b1[i][j] = 1e9;
            b2[i][j] = 1e9;
            grid[i][j] = (s[j] == '#');
        }
    }
    findED();
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        mn.push_back(findB(a, b));
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                vis[j][k] = false;
            }
        }
        R.push_back(make_pair(a, b));
    }
    int ans = 1e9;
    for(int i = 0; i < K; i++){
        for(int j = i + 1; j < K; j++){
            ans = min(ans, mn[i] + mn[j]);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j]){
                ans = min(ans, ED[i][j] + b1[i][j] + b2[i][j] - 2);
                //cout << i << " " << j << " " << b1[i][j] << " " << b2[i][j] << "\n";
            }
        }
    }
    cout << ans;
}
/*
11 7 3
#######
#######
#.####.
######.
#######
#####.#
#####.#
##..##.
##.#.##
####.##
..#####
3 2
8 3
9 5
*/