#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXM = 100;
const long long MAXA = 5e17;

int T, M;
long long p[MAXM], n[MAXM], ans; 

void gen(long long sum, long long prod, int i){
    if(i == M){
        if(sum == prod){
            ans = max(ans, sum);
        }
        return;
    }
    gen(sum, prod, i + 1);
    for(int j = 0; j < n[i]; j++){
        prod *= p[i];
        sum -= p[i];
        if(prod > MAXA)
            break;
        gen(sum, prod, i + 1);
    }
}

void solve(){
    cin >> M;
    long long sum = 0;
    for(int i = 0; i < M; i++){
        cin >> p[i] >> n[i];
        sum += p[i] * n[i];
    }
    ans = 0;
    gen(sum, 1, 0);
    cout << ans << "\n";
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;

    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    
    
    
}