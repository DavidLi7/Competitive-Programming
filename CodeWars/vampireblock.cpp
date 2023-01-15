#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    map<string, int> m;
    string s;
    getline(cin, s);
    vector<string> ans;
    vector<pair<string, int> > d;
    while(s != "END"){
        string code = s.substr(9, 2);
        int time = stoi(s.substr(12, 2)) * 60 + stoi(s.substr(15, 2)) + 10 * stoi(s.substr(18));
        if(time < 17 * 60){
            ans.push_back(code);
        }
        getline(cin, s);
        d.push_back(make_pair(code, time));
    }
    // for(auto it: d){
    //     cout << it.first << " " << it.second << "\n";
    // }
    if(ans.size()){
        cout << "Villagers (";
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i != ans.size() - 1){
                cout << ", ";
            }
        }
        cout << ") look tasty";
    }
    else{
        cout << "Blah, blah, blah, time to order delivery";
    }
}