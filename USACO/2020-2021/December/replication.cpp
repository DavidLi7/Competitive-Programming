#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1005;

int N, D, mx[MAXN][MAXN];
bool ok[MAXN][MAXN], ans[MAXN][MAXN];
vector<pair<int, int> > starts;
string grid[MAXN];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> D;
    for(int i = 0; i < N; i++){
        cin >> grid[i];
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 'S'){
                starts.push_back(make_pair(i, j));
            }
        }
    }
    queue<pair<int, pair<int, int> > > Q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == '#'){
                mx[i][j] = 0;
                Q.push(make_pair(0, make_pair(i, j)));
            }
            else{
                mx[i][j] = -1;
            }
        }
    }
    while(!Q.empty()){
        pair<int, pair<int, int> > temp = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int newx = temp.second.first + dx[i];
            int newy = temp.second.second + dy[i];
            if(newx != -1 && newx != N && newy != -1 && newy != N && mx[newx][newy] == -1){
                mx[newx][newy] = temp.first + 1;
                Q.push(make_pair(temp.first + 1, make_pair(newx, newy)));
            }
        }
    }
    priority_queue<pair<int, pair<int, int> > > PQ;
    for(pair<int, int> it: starts){
        Q.push(make_pair(D, it));
        ans[it.first][it.second] = true;
        PQ.push(make_pair(mx[it.first][it.second], make_pair(it.first, it.second)));
    }
    while(!Q.empty()){
        pair<int, pair<int, int> > temp = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int newx = temp.second.first + dx[i];
            int newy = temp.second.second + dy[i];
            if(newx != -1 && newx != N && newy != -1 && newy != N && !ok[newx][newy]){
                int newsz = (temp.first + 1) / D;
                int currsz = (temp.first) / D;
                if(currsz <= mx[newx][newy]){
                    ok[newx][newy] = true;
                    if(newsz <= mx[newx][newy]){
                        Q.push(make_pair(temp.first + 1, make_pair(newx, newy)));
                    }
                    ans[newx][newy] = true;
                    PQ.push(make_pair(mx[newx][newy], make_pair(newx, newy)));
                }
            }
        }
    }
    while(!PQ.empty()){
        pair<int, pair<int, int> > temp = PQ.top();
        PQ.pop();
        if(temp.first == 1)
            continue;
        for(int i = 0; i < 4; i++){
            int newx = temp.second.first + dx[i];
            int newy = temp.second.second + dy[i];
            if(newx != -1 && newx != N && newy != -1 && newy != N && !ans[newx][newy]){
                ans[newx][newy] = true;
                PQ.push(make_pair(temp.first - 1, make_pair(newx, newy)));
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ret += ans[i][j];
        }
    }
    cout << ret;
}