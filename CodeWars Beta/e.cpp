#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    double a, b;
    cin >> a >> b;
    double initial = a * b;
    cin >> a >> b;
    double spec = a * b;
    cin >> a >> b;
    double curr = a * b;
    double net = curr - initial;
    cout << "Initial: " << fixed << setprecision(2) << initial << "\n";
    cout << "Speculated: " << spec << "\n";
    cout << "Current: " << curr << "\n";
    cout << "Net: " << net << "\n";
    
}