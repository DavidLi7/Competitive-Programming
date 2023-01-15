#include <iostream>

using namespace std;

const int MAXN = 105;

int T, N, C, a[MAXN], amt[MAXN];

void reverse(int s, int e){
    for(int j = 0; j < (e - s + 1) / 2; j++){
        swap(a[s + j], a[e - j]);
    }
}

int main() {

     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N >> C;
        for(int i = 1; i <= N; i++){
            a[i] = i;
        }
        C -= (N - 1);
        for(int i = N - 1; i >= 1; i--){
            int len = min(N - i, C);
            if(len < 0)
                continue;
            C -= len;
            reverse(i, i + len);
        }
        if(C != 0){
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << "\n";
        } else{
            cout << "Case #" << t << ": ";
            for(int i = 1; i <= N; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
    
}