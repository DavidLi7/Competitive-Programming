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

int N, K, s[MAXN], ans[MAXN], s2[MAXN][MAXD], s3[MAXN], loc[MAXN];
long long M;
pair<int, int> a[MAXK];
unordered_set<int> p[MAXN], p2[MAXN];
vector<vector<int> > cycles;
bool added[MAXN];

void setup(){
    for(int d = 0; d < MAXD; d++){
        for(int j = 0; j < N; j++){
            s2[j][d] = loc[j];
        }
        for(int i = 0; i < N; i++){
            loc[s[i]] = s2[i][d];
            s3[loc[s[i]]] = s[i];
        }
        swap(s, s3);
    }
}

void fillwithx(int x){
    for(int i = 0; i < N; i++){
        s[i] = i;
    }
    for(int i = MAXD - 1; i >= 0; i--){
        if(x & (1 << i)){
            for(int j = 0; j < N; j++){
                s3[s2[j][i]] = s[j];
            }
            swap(s, s3);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> K >> M;

    if(N <= 100 && K <= 200){
        for(int i = 0; i < N; i++){
            p[i].insert(i);
            s[i] = i;
        }
        for(int i = 0; i < K; i++){
            cin >> a[i].first >> a[i].second;
            a[i].first--; a[i].second--;
        }
        for(int j = 0; j < N; j++){
            for(int i = 0; i < K; i++){
                if(j * K + i >= M)
                    break;
                swap(s[a[i].first], s[a[i].second]);
                p[s[a[i].second]].insert(a[i].second);
                p[s[a[i].first]].insert(a[i].first);
            }
        }
        for(int i = 0; i < N; i++){
            cout << p[i].size() << "\n";
        }
        return 0;
    }

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
    for(int i = 0; i < N; i++){
        loc[s[i]] = i;
    }
    setup();
    fillwithx(1);
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
        if((long long)(K) * (long long)(temp.size()) <= M){
            unordered_set<int> tot;
            for(int x: temp){
                for(int y: p[x])
                    tot.insert(y);
            }
            for(int x: temp)
                ans[x] = tot.size();
        }
        else{
            unordered_set<int> tot;
            multiset<int> el;
            long long okc = M / (long long)(K);
            int A = 0;
            int b = okc - 1;
            for(int i = 0; i <= b; i++){
                for(int y: p[temp[i]]){
                    tot.insert(y);
                    el.insert(y);
                }
            }
            long long rem = M % (long long)(K);
            fillwithx(okc);
            for(int i = 0; i < rem; i++){
                swap(s[a[i].first], s[a[i].second]);
                p2[s[a[i].second]].insert(a[i].second);
                p2[s[a[i].first]].insert(a[i].first);
            }
            for(int i = 0; i < temp.size(); i++){
                for(int y: p2[temp[b]]){
                    el.insert(y);
                    tot.insert(y);
                }
                ans[temp[b]] = tot.size();
                for(int y: p2[temp[b]]){
                    el.erase(el.find(y));
                    if(!el.count(y))
                        tot.erase(y);
                }
                b = (b + 1) % temp.size();
                for(int y: p[temp[A]]){
                    el.erase(el.find(y));
                    if(!el.count(y))
                        tot.erase(y);
                }
                A = (A + 1) % temp.size();
                for(int y: p[temp[b]]){
                    el.insert(y);
                    tot.insert(y);
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << "\n";
    }
}