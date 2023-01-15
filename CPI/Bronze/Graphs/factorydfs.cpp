#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 105;

int N;
vector<int> radj[MAXN];

int dfs(int i, int p){// time complexity of O(N)
    int ret = 1;
    for(int v: radj[i]) if(v != p){
        ret += dfs(v, i);
    }
    return ret;
}

int main(){
    setIO("factory");
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        radj[b].push_back(a);//Reverse ADJacency list
    }
    for(int i = 0; i < N; i++){
        if(dfs(i, -1) == N){
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
}