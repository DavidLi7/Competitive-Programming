#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 21;

//high strength, high weight, big height
struct cow{
    long long h, w, s;
};
bool operator<(const cow& x, const cow& y){
    if(x.s != y.s)
        return  x.s > y.s;
    if(x.w != y.w)
        return x.w > y.w;
    return x.h > y.h;
}

long long N, H;
cow cows[MAXN];

int main(){
    // setIO("guard");
    cin >> N >> H;
    for(int i = 0; i < N; i++){
        cin >> cows[i].h >> cows[i].w >> cows[i].s;
    }
    sort(cows, cows + N);
    // for(int i = 0; i < N; i++){
    //     cout << cows[i].w << " " << cows[i].s << " " << cows[i].h << "\n";
    // }
    long long ans = -1;
    for(int i = 0; i < (1 << N); i++){
        long long minleft = 2e18;
        long long totH = 0;
        for(int j = 0; j < N; j++){
            if((1 << j) & i){
                // cout << i << " " << j << "\n";
                minleft -= cows[j].w;
                if(minleft < 0)
                    break;
                totH += cows[j].h;
                minleft = min(minleft, cows[j].s);
                if(totH >= H)
                    break;
            }
        }
        if(minleft >= 0 && totH >= H){
            // cout << i << " " << minleft << " " << totH << "\n";
            ans = max(ans, minleft);
        }
    }
    if(ans == -1)
        cout << "Mark is too tall";
    else
        cout << ans;
}