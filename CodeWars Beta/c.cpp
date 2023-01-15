#include <iostream>
#include <math.h>  

using namespace std;

int main(){

    string s;
    double A, N, T;
    cin >> s >> A >> N >> T;
    cout << s << " " << round(((N + 1) * T) / (A / 10.0)) << "%\n";
    cin >> s >> A >> N >> T;
    cout << s << " " << round(((N + 1) * T) / (A / 10.0)) << "%";
}