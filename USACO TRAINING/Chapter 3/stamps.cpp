/*
ID: divadxl1
LANG: C++
TASK: stamps
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 50;
const int MX = 200 * 10000 + 1;

int N, K;
int ok[MX];

int main(){
    setIO("stamps");
    cin >> K >> N;
    vector<int> s(N);
    for(int i = 0; i < N; i++){
        cin >> s[i];
        ok[s[i]] = 1;
    }
    for(int i = 1; i < MX; i++){
        if(!ok[i]){
            cout << i - 1 << "\n";
            break;
        }
        if(ok[i] != K){
            for(int j = 0; j < N; j++){
                if(ok[i + s[j]] == 0 || ok[i] + 1 < ok[i + s[j]])
                    ok[i + s[j]] = ok[i] + 1;
            }
        }
    }
}