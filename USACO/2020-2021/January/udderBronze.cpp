#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXA = 21;

int N;
string s, t;
map<char, int> m;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        m[s[i]] = i;
    }
    int ans = 1;
    int curr = -1;
    for(int i = 0; i < t.size(); i++){
        if(m[t[i]] <= curr)
            ans++;
        curr = m[t[i]];
    }
    cout << ans;
}