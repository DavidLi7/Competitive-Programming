/*
ID: divadxl1
LANG: C++
TASK: lgame
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <fstream>

using namespace std;

int values[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int mx[26];

struct word{
    string str;
    int val;
    word(string Str) : str(Str){
        val = 0;
        for(int i = 0; i < str.size(); i++){
            val += values[str[i] - 'a'];
        }
    }
    bool operator < (const word &s1) const{
        return val > s1.val;
    }
};


vector<word> s;
int N, an;
vector<string> ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ifstream fin ("lgame.in");
    string curr;
    getline(fin, curr);
    fin.close();
    for(int i = 0; i < curr.size(); i++){
        mx[curr[i] - 'a']++;
    }
    freopen("lgame.dict","r",stdin);
    freopen("lgame.out","w",stdout);
    
    string c;
    cin >> c;
    while(c != "."){
        s.push_back(word(c));
        cin >> c;
        N++;
    }
    sort(s.begin(), s.end());
    an = 0;
    for(int i = 0; i < N; i++){
        vector<int> occ(26);
        for(int k = 0; k < 26; k++){
            occ[k] = 0;
        }
        for(int j = 0; j < s[i].str.size(); j++){
            occ[s[i].str[j]-'a']++;
        }
        bool ok = true;
        for(int k = 0; k < 26; k++){
            if(occ[k] > mx[k]){
                ok = false;
                break;
            }
        }
        if(!ok){
            continue;
        }
        if(s[i].val > an){
            an = s[i].val;
            ans.clear();
        }
        if(s[i].val == an)
            ans.push_back(s[i].str);
        for(int j = i + 1; j < N && s[i].val + s[j].val >= an ; j++){
            vector<int> occ2(26);
            for(int k = 0; k < 26; k++){
                occ2[k] = 0;
            }
            for(int k = 0; k < s[j].str.size(); k++){
                occ2[s[j].str[k]-'a']++;
            }
            ok = true;
            for(int k = 0; k < 26; k++){
                if(occ[k] + occ2[k] > mx[k]){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                continue;
            }
            if(s[i].val + s[j].val > an){
                ans.clear();
                an = s[i].val + s[j].val;
            }
            if(s[i].str < s[j].str)
                ans.push_back(s[i].str + " " + s[j].str);
            else
                ans.push_back(s[j].str + " " + s[i].str);
            
        }
    }
    sort(ans.begin(), ans.end());
    cout << an << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }
}