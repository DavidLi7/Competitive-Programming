#include <iostream>
#include <iomanip>

using namespace std;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    double height, radius;
    cin >> height >> radius;

    cout << fixed;
    cout << setprecision(2);
    cout << radius * radius * height * 3.1415926536;
    cout << " cubic inches";
}