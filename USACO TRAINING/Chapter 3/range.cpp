/*
ID: divadxl1
LANG: C++
TASK: range
*/
#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 251;

int N, grid[MAXN][MAXN], pre[MAXN][MAXN], c[MAXN];

int main(){
    setIO("range");
    cin >> N;
    for(int i = 1; i <= N; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= N; j++){
            grid[i][j] = (s[j - 1] == '1');
            pre[i][j] = pre[i - 1][j] + grid[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int ii = i + 1; ii <= N; ii++){
            int s = 0;
            for(int j = 1; j <= N; j++){
                if(pre[ii][j] - pre[i - 1][j] != ii - i + 1){
                    s = 0;
                }
                else{
                    if(s == 0){
                        s = j;
                    }
                    else if(j - s + 1 == ii - i + 1){
                        c[ii - i + 1]++;
                        s++;
                    }
                }
            }
        }
    }
    for(int i = 2; i <= N; i++){
        if(c[i] != 0){
            cout << i << " " << c[i] << "\n";
        }
    }

    


}