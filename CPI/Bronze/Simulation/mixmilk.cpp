#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int c[3], m[3];

void pour(int a, int b){
    int amt = min(m[a], c[b] - m[b]);
    m[a] -= amt;
    m[b] += amt;
}

int main(){
    setIO("mixmilk");
 
    cin >> c[0] >> m[0] >> c[1] >> m[1] >> c[2] >> m[2];

    //N = 100

    for(int i = 0; i < 33; i++){//33 * 3 = 99
        pour(0, 1);
        pour(1, 2);
        pour(2, 0);
    }
    pour(0, 1);

    cout << m[0] << "\n" << m[1] << "\n" << m[2] << "\n";
}