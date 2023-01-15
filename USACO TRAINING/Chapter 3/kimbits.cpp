/*
ID: divadxl1
LANG: C++
TASK: kimbits
*/
#include <iostream>
#include <string>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}  

long long c[32][32];

void setup(){
    for(int i = 1; i <= 31; i++){
        c[i][0] = 1;
        for(int j = 1; j <= i; j++){
            c[i][j] = c[i][j - 1] * (i - j + 1);
            c[i][j] /= j;
            //cout << i << " " << j << " " << c[i][j] << "\n"; 
        }
    }
}

string solve(int N, int L, long long I){
    //cout << N << " " << L << " " << I << "\n";
    if(N == 0)
        return "";
    int newN = 0;
    int newI = 0;
    long long prev = 0;
    for(int i = 1; i <= N; i++){
        long long s = 0;
        for(int j = 0; j <= L && j <= i; j++){
            s += c[i][j];
        }
        //cout << i <<" " << s << "\n";
        if(s >= I){
            newN = i - 1;
            newI = I - prev;
            break;
        }
        prev = s;
    }
    string ret = "";
    for(int i = N - 1; i > newN; i--){
        ret += "0";
    }
    if(newN == 0 && newI == 1)
        ret += "0";
    else
        ret += "1";
    ret += solve(newN, L - 1, newI);
    return ret;
}



int main(){
    setIO("kimbits");
    int N, L;
    long long I;
    cin >> N >> L >> I;
    setup();
    cout << solve(N, L, I) << "\n";
}