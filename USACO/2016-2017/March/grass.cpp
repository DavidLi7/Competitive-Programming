#include <iostream>
#include <vector>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 200005;

int N, M, K, Q, c[MAXN];
vector<pair<int, int> > adj[MAXN];

int main(){
    setIO("grass");
    cin >> N >> M >> K >> Q;
    for(int i = 0; i < M; i++){
        int a, b, l;
        cin >> a >> b >> l;
        a--;b--;
        adj[a].push_back(make_pair(b, l));
        adj[b].push_back(make_pair(a, l));
    }
    for(int i = 0; i < N; i++)
        cin >> c[i];
    multiset<int> cand;
    for(int i = 0; i < N; i++){
        for(auto it: adj[i]){
            if(it.first < i && c[i] != c[it.first])
                cand.insert(it.second);
        }
    }
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        a--;
        if(c[a] != b)
            for(auto it: adj[a]){
                if(c[it.first] == b){
                    cand.erase(cand.find(it.second));
                }
                else if(c[it.first] == c[a]){
                    cand.insert(it.second);
                }
            }
        c[a] = b;
        cout << *cand.rbegin() << "\n";
    }

}