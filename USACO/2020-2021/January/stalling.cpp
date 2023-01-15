#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 25;

int N, a[MAXN], b[MAXN];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    sort(b, b + N);
    long long ans = 1;
    int j = 0;
    for(int i = 0; i < N; i++){
        while(j < N && a[j] <= b[i])
            j++;
        ans *= (1LL * (j - i));
    }
    cout << ans;


}