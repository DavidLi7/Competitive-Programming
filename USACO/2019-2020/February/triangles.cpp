#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 305;

int N, ans, pre[MAXN][MAXN];
bool ok[MAXN][MAXN], ok2[MAXN][MAXN];

void rot(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ok2[N - 1 - j][i] = ok[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ok[i][j] = ok2[i][j];
        }
    }
}

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            pre[i][j] = ok[i][j];
            if(i != 0 && j != N - 1)
                pre[i][j] += pre[i - 1][j + 1];
            //cout << pre[i][j] << " ";
        }
        //cout << "\n";
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 1; i + k < N && j + k < N; k++){
                if(ok[i + k][j] && ok[i][j + k]){
                    int li = i;
                    int lj = j - k;
                    if(lj < 0){
                        li += lj;
                        lj = 0;
                    }
                    if(li < 0)
                        continue;
                    //cout << li << " " << lj << "\n";
                    ans += pre[li][lj];
                    int ri = i - k;
                    int rj = j;
                    if(ri >= 0){
                        ans -= pre[ri][rj];
                    }
                    
                    //cout << ri << " " << rj << "\n";
                }
            }
        }
    }
}

int main(){
    setIO("triangles");
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            ok[i][j] = (s[j] == '*');
        }
    }
    for(int i = 0; i < 4; i++){
        solve();
        //cout << ans << "\n";
        rot();
    }
    cout << ans;
}