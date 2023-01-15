#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double m, rc, rb, hb, l, w, h;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> m >> rc >> rb >> hb >> l >> w >> h;
    double cockpit = 4.0 / 3.0 * 3.1415926536 * rc * rc * rc - 2.2 - 4.1;
    double body = 3.1415926536 * rb * rb * hb - 12.1;
    double pods = 2.0 / 3.0 * l * w * h;
    double minions = 1.2 * m;
    cockpit = round(cockpit * 100.0) / 100.0;
    body = round(body * 100.0) / 100.0;
    pods = round(pods * 100.0) / 100.0;
    minions = round(minions * 100.0) / 100.0;
    cout << fixed;
    cout << setprecision(2);
    cout << "Cockpit " << cockpit << "\n";
    cout << "Body " << body << "\n";
    cout << "Pods " << pods << '\n';
    cout << "Minions Need " << minions << "\n";
    // cout << cockpit + body + pods << "\n";
    if(minions <= cockpit + body + pods){
        cout << "PLAN ACCEPTED";
    }
    else{
        cout << "PLAN REJECTED";
    }
}