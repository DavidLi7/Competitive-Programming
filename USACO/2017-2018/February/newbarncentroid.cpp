#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5 + 5;

int Q, sz[MAXN], par[MAXN];
vector<int> adj[MAXN], roots;
pair<char, int> queries[MAXN];
pair<int, int> big1[MAXN], big2[MAXN];
 
void getSize(int i, int p){
    sz[i] = 1;
    for(int v: adj[i]) if(v != p && !vis[v]){
        getSize(v, i);
        sz[i] += sz[v];
    }
}
 
int getCentroid(int i, int s, int p){
    for(int v: adj[i]) if(v != p && !vis[v]){
        if(sz[v] * 2 > s)
            return getCentroid(v, s, i);
    }
    return i;
}
 
void decomp(int i, int p){
    getSize(i, -1);
    int c = getCentroid(i, sz[i], -1);
    vis[c] = true;
    par[c] = p;
    for(int v: adj[c]){
        if(!vis[v]){
            decomp(v, c);
        }
    }
}

int main(){
    setIO("newbarn");
    cin >> Q;
    int curr = 0;
    for(int i = 0; i < Q; i++){
        char c;
        int x;
        cin >> c >> x;
        queries[i] = make_pair(c, i);
        if(c == 'B'){
            if(x != -1){
                adj[curr].push_back(x - 1);
                adj[x - 1].push_back(curr);
            }
            else{
                roots.push_back(curr);
            }
            curr++;
        }
    }
    for(int r: roots){
        decomp(r, -1);
    }
    for(auto it: queries){
        if(it.first == 'B'){

        }
        else{

        }
    }


}