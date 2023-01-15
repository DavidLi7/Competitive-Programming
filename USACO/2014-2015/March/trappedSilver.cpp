#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen((s+".in").c_str(),"r",stdin);
    // freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

int N, B;
pair<int, int> a[MAXN];//position, size
set<pair<int, int> > p;

int main(){
    setIO("trapped");
    cin >> N >> B;
    
    for(int i = 0; i < N; i++){
        cin >> a[i].second >> a[i].first;
    }
    sort(a, a + N);
    int before = -1;
    int after = -1;
    for(int i = 0; i < N; i++){
        if(a[i].first > B){
            after = i;
            before = i - 1;
            break;
        }
    }
    if(after == -1 || before == -1){
        cout << -1;
        return 0;
    }
    // cout << before << " " << after << "ba\n";
    int st = before;
    int en = after;
    while(true){
        if(en == -1 || st == N)
            break;
        if(a[en].first - a[st].first > a[en].second){
            en++;
        }
        else if(a[en].first - a[st].first > a[st].second){
            st--;
        }
        else{
            break;
        }
    }
    vector<pair<int, int> > s;
    int ans = 2e9;
    for(int i = N - 1; i >= 0; i--){
        while(s.size()){
            if(s.back().first - a[i].first > s.back().second){
                s.pop_back();
            }
            else{
                break;
            }
        }
        // if(s.size() && s.back().first < a[after].first)
        //     break;
        if(s.size() && i >= st && s.back().first >= a[after].first && i <= before){
            ans = min(ans, max(0, s.back().first - a[i].first - a[i].second));
            // cout << i << " " << max(0, s.back().first - a[i].first - a[i].second) << "\n";
        }
        s.push_back(a[i]);
    }
    s.clear();
    for(int i = 0; i < N; i++){
        while(s.size()){
            if(a[i].first - s.back().first > s.back().second){
                s.pop_back();
            }
            else{
                break;
            }
        }
        // if(s.size() && s.back().first > a[before].first)
        //     break;
        if(s.size() && i <= en && s.back().first <= a[before].first && i >= after){
            ans = min(ans, max(0, a[i].first - s.back().first - a[i].second));
            // cout << i << " " << max(0, a[i].first - s.back().first - a[i].second) << "\n";
        }
        s.push_back(a[i]);
    }
    if(ans == 2e9){
        ans = -1;
    }
    cout << ans;
    
}