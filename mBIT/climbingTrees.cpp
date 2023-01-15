#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

long long N, K, A[MAXN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A + N);
    long long ans = 0;
    long long t = 0;
    int j = 0;
    for(int i = 0; i < N; i++){
        while(j < N && (i == j || A[j - 1] + K >= A[j])){
            t += A[j];
            j++;
        }
        ans = max(ans, t);
        t -= A[i];
    }
    cout << ans;
}