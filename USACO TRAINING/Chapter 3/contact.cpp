/*
ID: divadxl1
LANG: C++
TASK: contact
*/
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

const int MAXN = 50;

int A, B, N;

string s;
//vector<pair<long long, pair<long long, int> > > ans;
vector<pair<long long, pair<int, long long> > > ans;

string makeBi(long long x, int len){
    string ret = "";
    for(int j = len - 1; j >= 0; j--){
        if(x & (1 << j)){
            ret += "1";
        }
        else{
            ret += "0";
        }
    }
    return ret;
}

int main(){
    setIO("contact");
    cin >> A >> B >> N;
    string curr;
    cin >> curr;
    while(!cin.eof()){
        s += curr;
        cin >> curr;
    }
    //s += curr;
    for(int i = A; i <= B; i++){
        if(i > s.size())
            break;
        map<long long, long long> mp;
        long long curr = 0;
        for(int j = 0; j < i; j++){
            curr *= 2;
            curr += s[j] == '1';
        }
        for(int j = i; j < s.size(); j++){
            mp[curr]++;
            if(s[j - i] == '1'){
                curr -= (1 << (i - 1));
            }
            curr *= 2;
            curr += s[j] == '1';
        }
        mp[curr]++;
        for(const auto& it: mp){
            //ans.push_back(make_pair(it.second, make_pair(it.first, i)));
            ans.push_back(make_pair(it.second, make_pair(i, it.first)));
        }
    }
    sort(ans.begin(), ans.end());
    int j = ans.size() - 1;
    while(N > 0 && j >= 0){
        int i = j;
        cout << ans[i].first;
        //vector<pair<long long, int> > el;
        vector<pair<int, long long> > el;
        while(i >= 0 && ans[i].first == ans[j].first){
            el.push_back(ans[i].second);
            i--;
        }
        sort(el.begin(), el.end());
        int c = 0;
        for(auto it: el){
            if(c % 6 == 0)
                cout << "\n";
            else
                cout << " "; 
            //cout << makeBi(it.first, it.second);
            cout << makeBi(it.second, it.first);
            c++;
        }
        cout << "\n";
        j = i;
        N--;
    }
    //cout << s;
}