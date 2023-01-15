#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 105;

int N, out[MAXN];

int main(){
    setIO("factory");

    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        out[a]++;
    }
    vector<int> ans;
    for(int i = 1; i <= N; i++){
        if(out[i] == 0){
            ans.push_back(i);
        }
    }
    if(ans.size() != 1){
        cout << -1;
    }
    else{
        cout << ans[0];
    }


}