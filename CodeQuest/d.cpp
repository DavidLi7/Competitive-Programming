#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int T, n;
long double x, y, h;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
    
    cin >> T;
    while(T--){
        cin >> x >> y >> h >> n;
        for(int i = 0; i < n; i++){
            long double newy = y + h * sin (x) / x;
            long double newx = h + x;
            x = newx;
            y = newy;
        }
        int ans = round(y * 1000.0);
        cout << ans / 1000;
        ans = ans % 1000;
        string a = to_string(ans);
        while(a.size() < 3)
            a = "0" + a;
        if(a[2] == '0'){
            if(a[1] == '0'){
                if(a[0] == '0'){

                }
                else{
                    cout << "." << a.substr(0, 1);
                }
            }
            else{
                cout << "." << a.substr(0, 2);
            }
        }
        else{
            cout << "." << a.substr(0, 3);
        }
        cout << "\n";
    }
    
}