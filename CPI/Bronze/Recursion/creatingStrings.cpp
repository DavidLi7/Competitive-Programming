#include <iostream>
#include <set>

using namespace std;

const int MAXN = 10;

string s;
int N;
set<string> ans;
bool vis[MAXN];

void generate(string curr){
    if(curr.size() == N){
        ans.insert(curr);
        return;
    }
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            vis[i] = true;
            generate(curr + s[i]);
            vis[i] = false;
        }
    }
}

int main(){
    cin >> s;
    N = s.size();
    generate("");
    cout << ans.size() << "\n";
    for(string x: ans){
        cout << x << "\n";
    }
}