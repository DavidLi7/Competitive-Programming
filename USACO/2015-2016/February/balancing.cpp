#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct BIT{
    int bit[10000005];
    void upd(int i, int c){
        i++;
        while(i < 1000005){
            bit[i] += c;
            i += i & -i;
        }
    }
    int get(int i){
        i++;
        int ret = 0;
        while(i > 0){
            ret += bit[i];
            i -= i & -i;
        }
        return ret;
    }
};

const int MAXN = 100000;

pair<int, int>points[MAXN];
int N;
BIT L, R;


int main(){
    setIO("balancing");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> points[i].first >> points[i].second;
        R.upd(points[i].second, 1);
    }
    sort(points, points + N);
    int ans = N;
    int i = 0;
    while(i < N){
        int j = i;
        while(j < N && points[i].first == points[j].first){
            L.upd(points[j].second, 1);
            R.upd(points[j].second, -1);
            j++;
        }
        int lo = 0;
        int hi = 1000000;
        while(lo < hi - 1){
            int mid = (lo + hi) / 2;
            int mx = 0;
            int l = L.get(mid);
            mx = max(l, j - l);
            int r = R.get(mid);
            mx = max(mx, max(r, N - j - r));
            if(l <= j / 2){
                lo = mid;
            }
            else{
                hi = mid;
            }
            ans = min(ans, mx);
        }
        lo = 0;
        hi = 1000000;
        while(lo < hi - 1){
            int mid = (lo + hi) / 2;
            int mx = 0;
            int l = L.get(mid);
            mx = max(l, j - l);
            int r = R.get(mid);
            mx = max(mx, max(r, N - j - r));
            if(r <= (N - j) / 2){
                lo = mid;
            }
            else{
                hi = mid;
            }
            ans = min(ans, mx);
        }
        lo = 0;
        hi = 1000000;
        while(lo < hi - 1){
            int mid = (lo + hi) / 2;
            int mx = 0;
            int l = L.get(mid);
            mx = max(l, j - l);
            int r = R.get(mid);
            mx = max(mx, max(r, N - j - r));
            if(l < j / 2){
                lo = mid;
            }
            else{
                hi = mid;
            }
            ans = min(ans, mx);
        }
        lo = 0;
        hi = 1000000;
        while(lo < hi - 1){
            int mid = (lo + hi) / 2;
            int mx = 0;
            int l = L.get(mid);
            mx = max(l, j - l);
            int r = R.get(mid);
            mx = max(mx, max(r, N - j - r));
            if(r < (N - j) / 2){
                lo = mid;
            }
            else{
                hi = mid;
            }
            ans = min(ans, mx);
        }
        i = j;
    }
    cout << ans;

    
}