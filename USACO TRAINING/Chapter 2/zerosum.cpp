/*
ID: divadxl1
LANG: C++
TASK: zerosum
*/
#include <iostream>
#include <string>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int N;

void solve(int curr, string seq, int carry, int sum, char prev){
    if(curr == N){
        int c = carry;
        if(prev == '-'){
            c *= -1;
        }
        int s = sum + c;
        if(s == 0){
            cout << seq << N<<endl;
        }
        return;
    }
    solve(curr + 1, seq + to_string(curr) + " ", 10 * carry + curr + 1, sum, prev);
    int c = carry;
    if(prev == '-'){
        c *= -1;
    }
    solve(curr + 1, seq + to_string(curr) + "+", curr + 1, sum + c, '+');
    solve(curr + 1, seq + to_string(curr) + "-", curr + 1, sum + c, '-');
}

int main(){
    setIO("zerosum");
    cin >> N;
    solve(1, "", 1, 0, '+');
}