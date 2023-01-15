#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    double p;
    while(true){
        cin >> p;
        if(p == 0)
            break;
        double rcubed = p * p;
        double r = cbrt(rcubed);
        cout << fixed << setprecision(4) << r << "\n";
    }
}