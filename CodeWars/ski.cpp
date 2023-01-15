#include <iostream>
#include <map>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    string x, y;
    cin >> x >> y;
    map<string, int> m1;
    m1["CONCRETE"] = 0;
    m1["WOOD"] = 1;
    m1["STEEL"] = 2;
    m1["RUBBER"] = 3;
    m1["ICE"] = 4;
    map<string, int> m2;
    m2["RUBBER"] = 0;
    m2["WOOD"] = 1;
    m2["STEEL"] = 2;
    double a[5][3];
    a[0][0] = 0.90;
    a[0][1] = 0.62;
    a[0][2] = 0.57;
    a[1][0] = 0.80;
    a[1][1] = 0.42;
    a[1][2] = 0.30;
    a[2][0] = 0.70;
    a[2][1] = 0.30;
    a[2][2] = 0.74;
    a[3][0] = 1.15;
    a[3][1] = 0.80;
    a[3][2] = 0.70;
    a[4][0] = 0.15;
    a[4][1] = 0.05;
    a[4][2] = 0.03;
    double ans = a[m1[y]][m2[x]];
    double ans2 = (atan(ans) * 180.0) / 3.14159265;
    // cout << ans2 << "\n";
    cout << fixed;
    cout << setprecision(2);
    cout << ans;
    cout << " ";
    cout << fixed;
    cout << setprecision(1);
    cout << ans2;
}