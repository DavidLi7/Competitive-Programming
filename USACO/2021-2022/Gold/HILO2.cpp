#include <iostream>

using namespace std;

const int MAXN = 2e5 + 5;

int N, p[MAXN];

int main(){

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    for(int x = 0; x <= N; x++){
        bool hi = false;
        int ans = 0;
        int minhi = 1e9;
        int minlo = -1;
        for(int i = 0; i < N; i++){
            if(p[i] > x && p[i] > minhi)
                continue;
            if(p[i] <= x && p[i] < minlo)
                continue;
            ans += (hi && p[i] <= x);
            hi = p[i] > x;
            if(hi)
                minhi = p[i];
            else
                minlo = p[i];
            if(hi)
                cout << (-1 * p[i]);
            else
                cout << p[i];
            cout << " ";
        }
        //cout << ans << "\n";
        cout << "\n";
    }
    

}