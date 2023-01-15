#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MOD = 1e9 + 7;

int N, ans;
vector<int> check;

void solve(int x){
    if(x == N){
        for(int i = 0; i < N; i++){
            int c = 0;
            for(int j = 0; j < N; j++){
                int ind = (i - j + N) % N;
                if(check[ind] > j){
                    c++;
                }
            }
            if(c != check[i])
                return;
        }
        ans++;
        ans %= MOD;
        for(int x: check){
            cout << x << " ";
        }
        cout << "\n";
    }
    else{
        for(int i = 1; i <= N; i++){
            check.push_back(i);
            solve(x + 1);
            check.pop_back();
        }
    }
}

int main(){
   // setIO("gymnasts");
    cin >> N;
    solve(0);
    /*check.push_back(1);
    check.push_back(1);
    check.push_back(1);
    check.push_back(1);
    for(int i = 0; i < N; i++){
        int c = 1;
        for(int j = 1; j < N; j++){
            int ind = (i - j + N) % N;
            if(check[ind] > j){
                c++;
            }
        }
        if(c != check[i])
            break;
    }*/
    cout << ans;
}