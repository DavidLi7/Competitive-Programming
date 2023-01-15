#include <iostream>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;

int N;
string s[MAXN];


int main(){
    //setIO("standingout");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
}