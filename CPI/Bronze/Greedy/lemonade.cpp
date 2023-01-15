#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;

int N, w[MAXN];

int main(){
    setIO("lemonade");

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> w[i];
    }
    sort(w, w + N);
    int ans = 0;
    for(int i = N - 1; i >= 0; i--){//N - 1 -> waited for 0 cows
                                    //N - 2 -> waited for 1 cow
                                    //N - 3 -> watied for 2 cows
        if(w[i] >= N - 1 - i){
            ans++;
        }
    }
    cout << ans;


}