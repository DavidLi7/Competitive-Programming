#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int T, N, f[MAXN], p[MAXN], in[MAXN];
bool alive[MAXN];

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cout << "Case #" << t << ": ";
        cin >> N;
        for(int i = 1; i <= N; i++)
            cin >> f[i];
        for(int i = 1; i <= N; i++){
            cin >> p[i];
            in[p[i]]++;
        }
        for(int i = 1; i <= N; i++)
            alive[i] = true;
        vector<pair<int, int> > x;
        for(int i = 1; i <= N; i++) if(alive[i] && in[i] == 0){
            while(p[i] != 0 && in[p[i]] == 1){
                alive[p[i]] = false;
                f[i] = max(f[i], f[p[i]]);
                p[i] = p[p[i]];
            }
            x.push_back(make_pair(f[i], i));
        }
        sort(x.begin(), x.end());
        int ans = 0;
        for(pair<int, int> it: x){
            cout << it.first << " " << it.second << "potato\n";
            int temp = 0;
            while(alive[it.second]){
                temp = max(temp, f[it.second]);
                alive[it.second] = false;
                it.second = p[it.second];
            }
            ans += temp;
        }
        cout << ans << '\n';
    }
}