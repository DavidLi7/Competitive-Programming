/*
ID: divadxl1
LANG: C++
TASK: fact4
*/
#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 0;

int N;

int main(){
    setIO("fact4");
    cin >> N;
    int d = 1;
    int c = 0;
    for(int i = 2; i <= N; i++){
        int x = i;
        while(x % 2 == 0){
            c++;
            x /= 2;
        }
        while(x % 5 == 0){
            c--;
            x /= 5;
        }
        d *= x;
        d = d % 10;
        
    }
    while(c > 0){
        d *= 2;
        d = d % 10;
        c--;
    }
    cout << d << "\n";
}