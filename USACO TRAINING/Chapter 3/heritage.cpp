/*
ID: divadxl1
LANG: C++
TASK: heritage
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 26;

char pre[MAXN];
map<char, int> loc;
int N;

void dfs(int s, int e){
    int i = s + 1;
    for(; i <= e; i++){
        if(loc[pre[i]] > loc[pre[s]]){
            break;
        }
    }
    if(i != s + 1)
        dfs(s + 1,  i - 1);
    if(i != e + 1)
        dfs(i, e);
    cout << pre[s];
}

int main(){
    setIO("heritage");
    
    string a, b;
    cin >> a >> b;
    N = (int)a.size();
    for(int i = 0; i < N; i++){
        loc[a[i]] = i;
    }
    for(int i = 0; i < N; i++){
        pre[i] = b[i];
    }
    dfs(0, N - 1);
    cout << "\n";
}