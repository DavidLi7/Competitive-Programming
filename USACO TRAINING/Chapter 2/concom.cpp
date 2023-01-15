/*
ID: divadxl1
LANG: C++
TASK: concom
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int control[101][101];
bool owns[101][101];

void make(int i, int j){
    if(owns[i][j])
        return;
    owns[i][j] = true;
    for(int k = 0; k < 101; k++){
        control[i][k] += control[j][k];
    }
    for(int k = 0; k < 101; k++){
        if(control[k][i] > 50){
            make(k, j);
        }
    }
    for(int k = 0; k < 101; k++){
        if(control[i][k] > 50){
            make(i, k);
        }
    }
}

void add(int i, int j, int p){

    control[i][j] += p;
    for(int k = 0; k < 101; k++){
        if(owns[k][i]){
            control[k][j] += p;
        }
    }

    for(int k = 0; k < 101; k++){
        if(control[k][j] > 50){
            make(k, j);
        }
    }

}

int main(){
    setIO("concom");
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b, p;
        cin >> a >> b >> p;
        a--; b--;
        add(a, b, p);
    }
    for(int i = 0; i < 101; i++){
        for(int j =0; j < 101; j++){
            if(owns[i][j] && i != j){
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }

    

}