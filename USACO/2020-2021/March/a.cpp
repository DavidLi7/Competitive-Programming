#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5 + 5;

int N, a[MAXN], c[MAXN];
long long ans;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= N; j++){
            c[j] = 0;
        }
        int ones = 1;
        c[a[i]]++;
        for(int j = i + 1; j < N; j++){
            if(a[j] == a[i])
                break;
            c[a[j]]++;
            if(c[a[j]] == 1)
                ones++;
            else if(c[a[j]] == 2)
                ones--;
            if(c[a[j]] == 1 && j - i >= 2 && ones > 2){
                ans += ones - 2;
                // cout << i + 1 << " " << j + 1 << " " << ones << "\n";
            }
        }
    }
    cout << ans;
    
}