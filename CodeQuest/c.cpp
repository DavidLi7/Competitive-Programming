#include <iostream>
#include <vector>

using namespace std;

int T;
string s;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
    
    cin >> T;
    getline(cin, s);
    while(T--){
        getline(cin, s);
        for(int i = 0; i < s.length(); i++){
            if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57) || (s[i] == ' ')){
                cout << s[i];
            }
        }
        cout << "\n";
    }
}