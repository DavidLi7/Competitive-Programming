#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int N, M;

int main(){
    //setIO("");
    cin >> N >> M;
    int ans = N * (N + 1) / 2;
    
}