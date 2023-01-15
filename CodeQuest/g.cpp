#include <iostream>
#include <math.h>

using namespace std;

int T;
long double c[3][3], f[3], c2[3][3], e[3];

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
    
    cin >> T;
    while(T--){
        cin >> c[1][1] >> c[2][1] >> c[1][2] >> c[2][2] >> f[1] >> f[2];
        long double d = c[1][1] * c[2][2] - c[1][2] * c[2][1];
        c2[1][1] = c[2][2] / d;
        c2[2][2] = c[1][1] / d;
        c2[1][2] = -c[1][2] / d;
        c2[2][1] = -c[2][1] / d;
        // cout << c2[1][1] << " " << c2[2][1] << " " << c2[1][2] << " " << c2[2][2] << "\n";
        e[1] = c2[1][1] * f[1] + c2[1][2] * f[2];
        e[2] = c2[2][1] * f[1] + c2[2][2] * f[2];
        cout << round(e[1]) << " " << round(e[2]) << "\n";
    }
}