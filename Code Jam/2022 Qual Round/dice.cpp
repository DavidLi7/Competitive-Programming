#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int T, N;
vector<int> a;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cout << "Case #" << t << ": ";
        cin >> N;
        a.resize(N);
        for(int j = 0; j < N; j++){
            cin >> a[j];
        }
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for(int j = 0; j < N; j++){
            while(a.size() != 0 && a.back() < ans + 1){
                a.pop_back();
            }
            if(a.size() == 0)
                continue;
            ans++;
            a.pop_back();
        }
        cout << ans << "\n";
    }
}