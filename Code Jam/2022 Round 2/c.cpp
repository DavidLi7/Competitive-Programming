#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1005;

int N, M, T;
long long x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
map<long long, vector<int> > dist[MAXN];
bool vis1[MAXN], vis2[MAXN], ok;
vector<pair<int, int> > s;
vector<pair<int, int> > ans;

long long d(int i, int j){
    return (x1[i] - x2[j]) * (x1[i] - x2[j]) + (y1[i] - y2[j]) * (y1[i] - y2[j]);
}

void rec(int t){
    if(t == N){
        ok = true;
        ans.clear();
        for(int i = 0; i < s.size(); i++)
            ans.push_back(s[i]);
        return;
    }
    for(int i = 0; i < N; i++){
        if(vis1[i])
            continue;
        vis1[i] = true;
        for(auto it: dist[i]){
            bool passedit = false;
            for(int x: it.second){
                if(x != 0 && !vis2[x]){
                    vis2[x] = true;
                    s.push_back(make_pair(i, x));
                    rec(t + 1);
                    s.pop_back();
                    vis2[x] = false;
                }
                if(!vis2[x])
                    passedit = true;
            }
            if(passedit)
                break;
        }
        vis1[i] = false;
    }
}

void solve(){  
    ok = false;
    s.clear();
    cin >> N;
    M = N + 1;
    for(int i = 0; i < N; i++){
        vis1[i] = false;
        cin >> x1[i] >> y1[i];
        dist[i].clear();
    }
    for(int i = 0; i < M; i++){
        vis2[i] = false;
        cin >> x2[i] >> y2[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            dist[i][d(i, j)].push_back(j); 
        }
    }
    rec(0);
    if(ok){
        cout << "POSSIBLE\n";
        for(auto it: ans)
            cout << it.first + 1 << " " << it.second + 1 << "\n";
    }
    else
        cout << "IMPOSSIBLE\n";

}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    
    
    
}