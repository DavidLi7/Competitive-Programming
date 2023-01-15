#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 105;

int N, T;
string s;

void solve(){
    cin >> s;
    vector<pair<char, int> > v;
    for(int i = 0; i < s.size(); i++){
        int j = i;
        while(j < s.size() && s[j] == s[i]){
            j++;
        }
        v.push_back(make_pair(s[i], j - i));
        i = j - 1;
    }
    vector<pair<char, int> > ans;
    for(int i = 0; i < v.size(); i++){
        if(i + 1 < v.size() && v[i].first < v[i + 1].first){
            ans.push_back(make_pair(v[i].first, v[i].second * 2));
        }
        else{
            ans.push_back(make_pair(v[i].first, v[i].second));
        }
    }
    for(auto it: ans){
        for(int j = 0; j < it.second; j++)
            cout << it.first;
    }
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