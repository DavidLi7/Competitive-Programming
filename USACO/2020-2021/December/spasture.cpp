#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 205;

int N;
long long ans, dupe;
pair<int, int> a[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i].first >> a[i].second;
    }
    ans = N + 1;
    sort(a, a + N);
    for(int i = 0; i < N; i++){
        set<int> ys;
        for(int j = i + 1; j < N; j++){
            if(i < j - 1)
                ys.insert(a[j - 1].second);
            int len = a[j].first - a[i].first;
            int ylo = max(a[i].second, a[j].second) - len;
            int yhi = min(a[i].second, a[j].second);
            if(ylo > yhi)
                continue;
            vector<int> y(ys.begin(), ys.end());
            int l = 0;
            while(l < y.size() && y[l] < ylo)
                l++;
            int r = -1;
            while(r + 1 < y.size() && ylo + len >= y[r + 1])
                r++;
            while(true){
                ans++;
                int yl = min(a[i].second, a[j].second);
                int yr = max(a[i].second, a[j].second);
                if(l <= r) {
                    yl = min(yl, y[l]);
                    yr = max(yr, y[r]);
                }
                if(yr - yl == len)
                    dupe++;
                int leavebottom = 2e9;
                if(l < y.size())
                    leavebottom = y[l] + 1;
                int gotonext = 2e9;
                if(r + 1 < y.size()){
                    gotonext = y[r + 1] - len;
                }
                int newy = min(gotonext, leavebottom);
                if(newy > yhi)
                    break;
                l += (newy == leavebottom);
                r += (newy == gotonext);
            }
        }
    }
    for(int i = 0; i < N; i++){
        swap(a[i].first, a[i].second);
    }
    sort(a, a + N);
    for(int i = 0; i < N; i++){
        set<int> ys;
        for(int j = i + 1; j < N; j++){
            if(i < j - 1)
                ys.insert(a[j - 1].second);
            int len = a[j].first - a[i].first;
            int ylo = max(a[i].second, a[j].second) - len;
            int yhi = min(a[i].second, a[j].second);
            if(ylo > yhi)
                continue;
            vector<int> y(ys.begin(), ys.end());
            int l = 0;
            while(l < y.size() && y[l] < ylo)
                l++;
            int r = -1;
            while(r + 1 < y.size() && ylo + len >= y[r + 1])
                r++;
            while(true){
                ans++;
                int yl = min(a[i].second, a[j].second);
                int yr = max(a[i].second, a[j].second);
                if(l <= r) {
                    yl = min(yl, y[l]);
                    yr = max(yr, y[r]);
                }
                if(yr - yl == len)
                    dupe++;
                int leavebottom = 2e9;
                if(l < y.size())
                    leavebottom = y[l] + 1;
                int gotonext = 2e9;
                if(r + 1 < y.size()){
                    gotonext = y[r + 1] - len;
                }
                int newy = min(gotonext, leavebottom);
                if(newy > yhi)
                    break;
                l += (newy == leavebottom);
                r += (newy == gotonext);
            }
        }
    }
    cout << ans - dupe / 2;
}