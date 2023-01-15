#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 2505;

int N;
long long pre[MAXN][MAXN];
pair<int, int> a[MAXN];

long long get(int x1, int y1, int x2, int y2){
    return pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + N);
    for(int i = 0; i < N; i++){
        a[i].first = i + 2;
        swap(a[i].first, a[i].second);
    }
    sort(a, a + N);
    for(int i = 0; i < N; i++){
        a[i].first = i + 2;
        swap(a[i].first, a[i].second);
        pre[a[i].first][a[i].second]++;
        // cout << a[i].first << " " << a[i].second << "\n";
    }
    for(int i = 1; i <= N + 1; i++){
        for(int j = 1; j <= N + 1; j++){
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    long long ans = 1;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            int x1 = min(a[i].first, a[j].first);
            int x2 = max(a[i].first, a[j].first);
            int y1 = min(a[i].second, a[j].second);
            int y2 = max(a[i].second, a[j].second);
            ans += get(1, y1, x1, y2) * get(x2, y1, N + 1, y2);
            // cout << get(1, y1, x1, y2) << " " << get(y1, x2, y2, N) << " " << ans << "\n";
        }
    }
    cout << ans;


}
