#include <iostream>

using namespace std;

int T;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
    
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans += s[i] - 'a' + 1;
        }
        cout << ans << "\n";
    }
}