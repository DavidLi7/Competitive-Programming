/*
ID: divadxl1
LANG: C++
TASK: ratios
*/
#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 101;

int goal[3], s[3][3];

int main(){
    setIO("ratios");
    cin >> goal[0] >> goal[1] >> goal[2];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> s[i][j];
        }
    }
    double min = 1e9;
    int aa = -1;
    int ba = -1;
    int ca = -1;
    double r = -1;
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            for(int k = 0; k < MAXN; k++) if(i + j + k < min && i + j + k != 0){
                int a = i * s[0][0] + j * s[1][0] + k * s[2][0];
                int b = i * s[0][1] + j * s[1][1] + k * s[2][1];
                int c = i * s[0][2] + j * s[1][2] + k * s[2][2];
                if(a % goal[0] != 0)
                    continue;
                double R = a / (double)goal[0];
                if(R * (double)goal[1] == b  && R * (double)goal[2] == c){
                    aa = i; ba = j; ca = k; r = R;
                    min = i + j + k;
                }
            }
        }
    }
    if(aa == -1){
        cout << "NONE\n";
    }
    else
        cout << aa << " " << ba << " " << ca << " " << r << "\n";
}