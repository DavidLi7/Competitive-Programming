/*
ID: divadxl1
LANG: C++
TASK: prefix
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int main(){
    setIO("prefix");
    vector<string>p;
    string curr;
    cin >> curr;
    while(curr != "."){
        p.push_back(curr);
        cin >> curr;
    }
    string s = "";
    cin >> curr;
    while(!cin.eof()){
        s += curr;
        cin >> curr;
    }
    int N = (int)s.size();
    vector<bool>ok(N + 1);
    for(int i = 0; i < N; i++){
        ok[i] = false;
    }
    ok[0] = true;
    for(int i = 0; i < N; i++) if(ok[i]){
        for(string j: p){
            if(i + j.size() <= N)
                if(s.substr(i, (int)j.size()) == j){
                    ok[i + j.size()] = true;
                }
        }
    }
    int ans = 0;
    for(int i = N; i >=0; i--){
        if(ok[i]){
            ans = i;
            break;
        }
    }
    //cout << s << "\n";
    cout << ans << "\n";

}