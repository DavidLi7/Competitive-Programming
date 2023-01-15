/*
ID: divadxl1
LANG: C++
TASK: fence9
*/
#include <iostream>
#include <cmath>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 32001;

int N, M, P;

int main(){
    setIO("fence9");
    cin >> N >> M >> P;
    int ans = 0;
    for(int x = 1; x <= N; x++){
        if(x == N && x == P)
            continue;
        int under = (M * x) / N;
        if((M * x)% N == 0){
            under--;
        }
        ans += under;
        //cout << x << " " << under << "\n";
    }
    if(P > N){
        for(int x = N + 1; x < P; x++){
            int under = (M * (x - P))/(N - P);
            if((M * (x - P)) % (P - N) == 0)
                under--;
            ans += under;
            //cout << x << " " << under << "\n";
        }
        
    }
    else if (P != N){
        for(int x = P; x <= N; x++){
            int under = (M * (x - P))/(N - P);
            if(x == N && (M * x)% N == 0){
                under--;
            }
            ans -= under;
           // cout << x << " " << under << "\n";
        }
    }
    cout << ans << "\n";
}