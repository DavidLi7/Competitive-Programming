#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    string name;
    long double x, a, w;
    cin >> name >> x >> a >> w;
    double t = sqrt(2.0 * x / a);
    double s = t * a;
    double d = s * s / 9.805;
    cout << fixed;
    cout << setprecision(2);
    cout << name << " will reach a speed of " << s;
    cout << fixed;
    cout << setprecision(0);
    cout << " m/s on a " << x;
    cout << fixed;
    cout << setprecision(1);
    cout << " meter ramp, crossing " << d << " of " << w << " meters, ";
    if(d < w - 5){
        cout << "SPLASH!";
    }
    else if(d >= w - 5 && d <= w){
        cout << "BARELY MADE IT!";
    }
    else if(d > w){
        cout << "LIKE A BOSS!";
    }
}