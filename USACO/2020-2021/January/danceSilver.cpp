#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXK = 2e5 + 5;
const int MAXD = 20;

int N, K, s[MAXN], ans[MAXN];
pair<int, int> a[MAXK];
unordered_set<int> p[MAXN];
vector<vector<int> > cycles;
bool added[MAXN];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        p[i].insert(i);
        s[i] = i;
    }
    for(int i = 0; i < K; i++){
        cin >> a[i].first >> a[i].second;
        a[i].first--; a[i].second--;
    }
    for(int i = 0; i < K; i++){
        swap(s[a[i].first], s[a[i].second]);
        p[s[a[i].second]].insert(a[i].second);
        p[s[a[i].first]].insert(a[i].first);
    }
    for(int i = 0; i < N; i++) if(!added[i]){
        vector<int> temp;
        int curr = i;
        while(!added[curr]){
            temp.push_back(curr);
            added[curr] = true;
            curr = s[curr];
        }
        cycles.push_back(temp);
    }
    for(vector<int> temp: cycles){
        unordered_set<int> tot;
        for(int x: temp){
            for(int y: p[x])
                tot.insert(y);
        }
        for(int x: temp)
            ans[x] = tot.size();
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << "\n";
    }
}