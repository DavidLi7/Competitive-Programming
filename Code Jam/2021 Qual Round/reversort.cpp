#include <iostream>

using namespace std;

const int MAXN = 105;

int T, N, a[MAXN];

int main() {

     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0; i < N - 1; i++){
            int mini = i;
            for(int j = i + 1; j < N; j++){
                if(a[j] < a[mini]){
                    mini = j;
                }
            }
            ans += mini - i + 1;
            for(int j = 0; j < (mini - i + 1) / 2; j++){
                swap(a[i + j], a[mini - j]);
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    
}

/*
Case #1: 1 3 4 2 
Case #2: 1 2 
Case #3: 1 2 3 5 7 6 4 
Case #4: IMPOSSIBLE
Case #5: IMPOSSIBLE
*/