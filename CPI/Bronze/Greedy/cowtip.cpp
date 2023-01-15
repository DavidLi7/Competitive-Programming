#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 10;

int N, t[MAXN][MAXN];

int main(){
    setIO("cowtip");
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            t[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    for(int i = N - 1; i >= 0; i--){//N - > 0
        for(int j = N - 1; j >= 0; j--){// N -> 0
            if(t[i][j] == 1){
                //flip
                for(int k = 0; k <= i; k++){ //0->N
                    for(int l = 0; l <= j; l++){//0->N
                        t[k][l] = 1 - t[k][l];
                    }
                }
                ans++;
            }
        }
    }
    //N^4
    cout << ans;
}