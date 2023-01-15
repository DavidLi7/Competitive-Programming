#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;

int N;
vector<int> adj[MAXN];
bool bad;

bool good(int i, int l, vector<int> vals){
    int lo = 0;
    int hi = vals.size() - 1;
    if(lo == i){
        lo++;
    }
    if(hi == i){
        hi--;
    }
    while(lo < hi){
        if(vals[lo] + vals[hi] >= l){
            lo++;
            hi--;
            if(lo == i){
                lo++;
            }
            if(hi == i){
                hi--;
            }
        }
        else{
            return false;
        }
    }
    return true;
}

int dfs(int v, int p, int l){
    vector<int> vals;
    for(int u: adj[v]) if(u != p){
        vals.push_back(dfs(u, v, l));
        if(bad)
            return -1;
    }
    if(vals.size() % 2 == 0){
        vals.push_back(0);
    }
    sort(vals.begin(), vals.end());
    
    int lo = 0;
    int hi = vals.size();
    if(!good(0, l, vals)){
        bad = true;
        return -1;
    }
    while(lo < hi - 1){
        int mid = (lo + hi) / 2;
        if(good(mid, l, vals)){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    //cout << v + 1 << " " << vals[lo] + 1 << "\n";
    return vals[lo] + 1;
}

bool ok(int l){
    bad = false;
    int v = 0;
    vector<int> vals;
    for(int u: adj[v]){
        vals.push_back(dfs(u, v, l));
    }
    if(bad)
        return false;
    if(vals.size() % 2 == 0){
        return good(-1, l, vals);
    }
    sort(vals.begin(), vals.end());
    int lo = 0;
    int hi = vals.size();

    while(lo < hi - 1){
        int mid = (lo + hi) / 2;
        if(good(mid, l, vals)){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    //cout << v + 1 << " " << vals[lo] + 1 << "\n";
    return vals[lo] >= l;
}

int main(){
    setIO("deleg");
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int lo = 1;
    int hi = N;
    while(lo < hi - 1){
        int mid = (lo + hi) / 2;
        if(ok(mid)){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    //for(int i = 0; i <= N; i++){
    //    cout << i << " " << ok(i) << "\n";
    //}
    cout << lo;




}