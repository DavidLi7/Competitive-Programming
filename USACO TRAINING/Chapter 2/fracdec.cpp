/*
ID: divadxl1
LANG: C++
TASK: fracdec
*/
#include <iostream>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

int N, D, seen[MAXN];
char dig[MAXN];
string ans;


int main(){
    setIO("fracdec");
    cin >> N >> D;
    int rem = N % D;
    ans = "";
    ans += to_string((N / D));
    ans += ".";
    //cout << N/D;
    //cout << ".";
    if(rem == 0){
        cout << ans;
        cout << 0 << "\n";
        return 0;
    }
    for(int i = 0; i < D; i++){
        seen[i] = -1;
    }
    
    int i = 0;
    while(true){
        if(rem == 0){
            ans += dig;
            //cout << dig;
            break;
        }
        if(seen[rem] != -1){
            for(int j = 0; j < seen[rem]; j++){
                //cout << dig[j];
                ans += dig[j];
            }
            //cout << "(";
            ans += "(";
            for(int j = seen[rem]; j < i; j++){
                //cout << dig[j];
                ans+=dig[j];
            }
            ans += ")";
            //cout << ")";
            break;
        }
        seen[rem] = i;
        N = rem * 10;
        rem = N % D;
        dig[i] = N/D + '0';
        i++;
    }
    for(int i = 0; i < ans.size(); i+=76){
        cout << ans.substr(i, min(76, (int)ans.size() - i))<<"\n";
    }

}