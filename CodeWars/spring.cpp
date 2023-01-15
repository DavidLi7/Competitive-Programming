#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    map<string, string> m;
    for(int i = 0; i < 3; i++){
        string a, b;
        cin >> a >> b;
        m[a] = b;
    }
    cout << fixed;
    cout << setprecision(2);
    if(m["F"] == "?"){
        cout << "F" << " " << -1.0 * stod(m["K"]) * stod(m["X"]);
    }
    else if(m["X"] == "?"){
        cout << "X" << " " << -1.0 * stod(m["F"]) / stod(m["K"]); 
    }
    else{
        cout << "K" << " " << -1.0 * stod(m["F"]) / stod(m["X"]); 
    }


}