#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 5;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    int N;
    cin >> N;
    long long ans = 0;
    priority_queue<int> PQ;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        ans += a;
        PQ.push(-a);
        if(i % 2 == 1){
            int mn = PQ.top();
            PQ.pop();
            ans += (long long)mn;
        }
    }
    cout << ans << "\n";

}
