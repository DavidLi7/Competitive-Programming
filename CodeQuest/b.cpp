#include <iostream>
#include <math.h>

using namespace std;

int T;
double a, b, c;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
    
    cin >> T;
    while(T--){
        cin >> a >> b >> c;
        int ans = round(a * c / (b - c));
        cout << ans << "\n";
    }
    
}