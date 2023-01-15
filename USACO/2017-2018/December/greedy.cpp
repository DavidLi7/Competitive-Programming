#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;

int cows[MAXN], N, c[MAXN];

bool works(int x){
    for(int i = 0; i < N; i++){
        c[i] = 0;
    }
    for(int i = 0; i < x; i++){
        c[N - cows[i] - 1]++;
    }
    for(int i = 0; i < x; i++){
        if(i != 0){
            c[i] += c[i - 1];
        }
        if(c[i] > i){
            return false;
        }
    }
    return true;
}

int main(){
    setIO("greedy");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cows[i];
    }
    int lo = 0;
    int hi = N;
    while(lo < hi - 1){
        int mid = (lo + hi) / 2;
        if(works(mid)){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    cout << N - hi;
    
}
