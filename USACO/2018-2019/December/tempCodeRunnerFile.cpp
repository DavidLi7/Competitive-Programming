#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 50005;

int N;
map<vector<int>, int> m;

void gen(int a = -1, int b = -1, int c = -1, int d = -1, int e = -1){
    vector<int> t;
    if(a != -1){
        t.push_back(a);
        if(b != -1){
            t.push_back(b);
            if(c != -1){
                t.push_back(c);
                if(d != -1){
                    t.push_back(d);
                    if(e != -1)
                        t.push_back(e);
                }
            }
        }
    }
    m[t]++;
}

int main(){
    setIO("cowpatibility");
    cin >> N;
    for(int i = 0; i < N; i++){
        vector<int> t(5);
        for(int j = 0; j < 5; j++)
            cin >> t[j];
        sort(t.begin(), t.end());
        for(int j = 0; j < 5; j++){
            gen(t[j]);
            for(int k = j + 1; k < 5; k++){
                gen(t[j], t[k]);
                for(int l = k + 1; l < 5; l++){
                    gen(t[j], t[k], t[l]);
                    for(int m = l + 1; m < 5; m++){
                        gen(t[j], t[k], t[l], t[m]);
                        for(int n = m + 1; n < 5; n++){
                            gen(t[j], t[k], t[l], t[m], t[n]);
                        }
                    }
                }
            }
        }
    }
    int ans = N * (N - 1) / 2;
    for(auto it: m){
        if(it.second >= 2){
            // for(int x: it.first){
            //     cout << x << " ";
            // }
            // cout << ": ";
            // cout << it.second << "\n";
            if(it.first.size() % 2 == 1)
                ans -= it.second * (it.second - 1) / 2;
            else
                ans += it.second * (it.second - 1) / 2;
        }
        
    }
    cout << ans;
}

/*
4
1 2 3 4 5
1 2 3 4 5
6 7 8 9 10
1 2 3 4 10
*/
//5 * 4 / 2 = 10
//6 + 6 - 3 = 9