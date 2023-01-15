#include <iostream>
#include <map>

using namespace std;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    int N;
    string s;
    cin >> N;
    getline(cin, s);
    getline(cin, s);
    // cout << s;
    map<char, char> m;
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string b = "FGHIJKLMNOPQRSTUVWXYZABCDE";
    for(int i = 0; i < 26; i++){
        m[b[i]] = a[i];
    }
    for(int i = 0; i < s.size(); i++){
        if(m.count(s[i])){
            cout << m[s[i]];
        }
        else{
            cout << s[i];
        }
    }

}