#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 5;

long long N, a[MAXN], b[MAXN];

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(i != 0)
            a[i] += a[i - 1];
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
        if(i != 0)
            b[i] += b[i - 1];
    }
    for(int i = N - 2; i >= 0; i--){
        if(a[i] == b[i]){
            cout << (N - 1 - i);
            return 0;
        }
    }
    cout << N;
}