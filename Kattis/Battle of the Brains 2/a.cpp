#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1e5 + 5;

string s;
map<char, vector<int> > m;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> s;
    for(int i = 0; i < s.size(); i++){
        m[s[i]].push_back(i);
    }
    for(int i = 0; i < 26; i++){
        m['a' + i].push_back(s.size());
    }
    long long ans = 0;
    for(auto it: m){
        for(int i = 0; i < it.second.size() - 1; i++){
            int st = it.second[i];
            int e = it.second[i + 1];
            set<char> x;
            x.insert(s[st]);
            while(st < e){
                if(x.find(s[st]) == x.end()){
                    ans++;
                }
                x.insert(s[st]);
                st++;
            }
        }
    }
    cout << ans << "\n";
    
    

        
    
    
}