#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;
const int MAXD = 18;

int Q, LCA[MAXN][MAXD], depth[MAXN], comp[MAXN], curr;
pair<int, int> dia[MAXN];

int getLCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = MAXD - 1; i >= 0; i--){
        if(depth[a] - (1 << i) >= depth[b])
            a = LCA[a][i];
    }
    for(int i = MAXD - 1; i >= 0; i--){
        if(LCA[a][i] != LCA[b][i]){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    if(a != b)
        a = LCA[a][0];
    return a;
}

int dist(int a, int b){
    return depth[a] + depth[b] - 2 * depth[getLCA(a, b)];
}

int main(){
    setIO("newbarn");
    cin >> Q;
    for(int i = 0; i < Q; i++){
        char c;
        int x;
        cin >> c >> x;
        if(c == 'B'){
            curr++;
            if(x == -1){
                comp[curr] = curr;
                dia[curr] = make_pair(curr, curr);
            }
            else{
                comp[curr] = comp[x];
                depth[curr] = depth[x] + 1;
                LCA[curr][0] = x;
                for(int i = 1; i < MAXD; i++){
                    LCA[curr][i] = LCA[LCA[curr][i - 1]][i - 1];
                }
                int d = dist(dia[comp[curr]].first, dia[comp[curr]].second);
                if(dist(curr, dia[comp[curr]].first) > d)
                    dia[comp[curr]].second = curr;
                else if(dist(curr, dia[comp[curr]].second) > d)
                    dia[comp[curr]].first = curr;
            }
        }
        else{
            cout << max(dist(x, dia[comp[x]].first), dist(x, dia[comp[x]].second)) << "\n";
        }
    }
}