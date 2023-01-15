#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 105;

int N, x[MAXN], passto[MAXN];

int target(int i){
    int l = -1, ld = 1000;
    int r = -1, rd = 1000;
    for(int j = 0; j < N; j++){
        if(x[j] < x[i] && x[i] - x[j] < ld){
            l = j;
            ld = x[i] - x[j];
        }
        if(x[j] > x[i] && x[j] - x[i] < rd){
            r = j;
            rd = x[j] - x[i];
        }
    }
    if(ld <= rd)
        return l;
    return r;
}

int main(){
    setIO("hoofball");

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    for(int i = 0; i < N; i++){
        passto[target(i)]++;
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(passto[i] == 0)
            ans++;
        if(i < target(i) && target(target(i)) == i && passto[i] == 1 && passto[target(i)] == 1)
            ans++;
    }

    cout << ans << "\n";
}