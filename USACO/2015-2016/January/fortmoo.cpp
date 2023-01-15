#include <iostream>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 200;

int N, M, pre[MAXN][MAXN];
bool ok[MAXN][MAXN];

bool good(int i1, int i2, int j){
    return pre[i2][j] - pre[i1][j] == i2 - i1;
}

int main(){
    setIO("fortmoo");

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i != 0)
                pre[i][j] = pre[i - 1][j];
            char x;
            cin >> x;
            ok[i][j] = x == '.';
            pre[i][j] += ok[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int ii = i; ii < N; ii++){
            int l = -1;
            for(int j = 0; j < M; j++){
                if(!ok[i][j] || !ok[ii][j]){
                    l = -1;
                    continue;
                }
                if(good(i, ii, j)){
                    if(l == -1){
                        l = j;
                    }
                    ans = max(ans, (j - l + 1) * (ii - i + 1));
                }
            }
        }
    }
    cout << ans;

}