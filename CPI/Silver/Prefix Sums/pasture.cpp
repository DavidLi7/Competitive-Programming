#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2505;

int N, pre[MAXN][MAXN];
pair<int, int> p[MAXN];

int rsum(int x1, int y1, int x2, int y2){
    return pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> p[i].first >> p[i].second;

    //compresses data
    for(int t = 0; t < 2; t++){
        sort(p, p + N); // (2, 1) (4, 2) (3, 3) (0, 4)
        for(int i = 0; i < N; i++){
            p[i].first = i + 1;
            swap(p[i].first, p[i].second);
        }
    }

    for(int i = 0; i < N; i++)
        pre[p[i].first][p[i].second]++;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

    long long ans = 1;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            int x1 = min(p[i].first, p[j].first);
            int x2 = max(p[i].first, p[j].first);
            ans += rsum(1, i + 1, x1, j + 1) * rsum(x2, i + 1, N, j + 1);
        }
    }
    cout << ans << "\n";
}