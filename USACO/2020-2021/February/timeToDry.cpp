#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

int N, Q, a[MAXN], BIT[MAXN], ans[MAXN];
vector<pair<int, int> > queries[MAXN];

void upd(int s, int d){
    s++;
    while(s < MAXN){
        BIT[s] += d;
        s += s & -s;
    }
}

int get(int s){
    s++;
    int ret = 0;
    while(s > 0){
        ret += BIT[s];
        s -= s & -s;
    }
    return ret;
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        queries[l].push_back(make_pair(r, i));
    }
    vector<pair<int, int> > s;//num, index
    s.push_back(make_pair(-1, 0));
    for(int i = N; i >= 1; i--){
        while(s.back().first > a[i]){
            s.pop_back();
        }
        if(s.back().first == a[i]){
            // upd(i, s.back().second - 1);
            upd(i, 1);
            upd(s.back().second, -1);
            s.back().second = i;
        }
        else{
            // upd(i, N);
            upd(i, 1);
            upd(N + 1, -1);
            s.push_back(make_pair(a[i], i));
        }
        for(auto it: queries[i]){
            // ans[it.second] = dp[it.first];
            ans[it.second] = get(it.first);
        }
    }
    for(int i = 0; i < Q; i++){
        cout << ans[i] << "\n";
    }

}