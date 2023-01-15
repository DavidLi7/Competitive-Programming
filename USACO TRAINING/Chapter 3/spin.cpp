/*
ID: divadxl1
LANG: C++
TASK: spin
*/
#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int v[5], s[5][5], l[5][5], c[5], co[360];

int main(){
    setIO("spin");
    for(int i = 0; i < 5; i++){
        cin >> v[i] >> c[i];
        for(int j = 0; j < c[i]; j++){
            cin >> s[i][j] >> l[i][j];
        }
    }
    int ans = 0;
    for(;ans < 360; ans++){
        bool done = false;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 360; j++){
                co[j] *= 2;
            }
            for(int j = 0; j < c[i]; j++){
                int e = (ans * v[i] + s[i][j] + l[i][j]) % 360;
                int st = (ans * v[i] + s[i][j]) % 360;
                if(e < st){
                    for(int k = st; k <= 359; k++){
                        if(co[k] % 2 == 0)
                            co[k]++;
                    }
                    for(int k = 0; k <= e; k++){
                        if(co[k] % 2 == 0)
                            co[k]++;
                    }
                }
                else{
                    for(int k = st; k <= e; k++){
                        if(co[k] % 2 == 0)
                            co[k]++;
                    }
                }
            }
        }
        for(int i = 0; i < 360; i++){
            if(co[i] == 31){
                done = true;
                break;
            }
            co[i] = 0;
        }
        if(done)
            break;
    }
    if(ans == 360){
        cout << "none\n";
    }
    else
        cout << ans << "\n";
}