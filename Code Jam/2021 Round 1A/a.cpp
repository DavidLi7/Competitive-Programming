#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int N, T;
string a[MAXN];

void solve(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int ans = 0;
    
    for(int i = 1; i < N; i++){
        if(a[i].size() > a[i - 1].size())
            continue;
        bool done = false;
        bool allequal = true;
        for(int j = 0; j < a[i].size() && !done; j++){
            if(a[i][j] > a[i - 1][j] && allequal){
                while(a[i].size() != a[i - 1].size()){
                    a[i] += "0";
                    ans++;
                }
                done = true;
            }
            if(a[i][j] != a[i - 1][j])
                allequal = false;
        }
        if(done)
            continue;
        if(allequal){
            string s = "";
            bool added = false;
            for(int j = a[i - 1].size() - 1; j >= a[i].size(); j--){
                if(!added && a[i - 1][j] != '9'){
                    s += (a[i - 1][j] + 1);
                    added = true;
                }
                else if(!added){
                    s += "0";
                }
                else{
                    s += a[i - 1][j];
                }
            }
            if(added){
                reverse(s.begin(), s.end());
                a[i] += s;
                ans += s.size();
            }
            else{
                while(a[i].size() <= a[i - 1].size()){
                    a[i] += "0";
                    ans++;
                }
            }
        }
        else{
            while(a[i].size() <= a[i - 1].size()){
                a[i] += "0";
                ans++;
            }
        }
        
    }
    // for(int i = 0; i < N; i++){
    //     cout << a[i] << "\n";
    // }
    cout << ans;
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }

    
    
    
}