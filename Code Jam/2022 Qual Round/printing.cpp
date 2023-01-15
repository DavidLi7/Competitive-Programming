#include <iostream>

using namespace std;

const int MAXN = 11;

int T, a, b, c, d, temp;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cout << "Case #" << t << ": ";
        a = 1e9;
        b = 1e9;
        c = 1e9;
        d = 1e9;
        for(int j = 0; j < 3; j++){
            cin >> temp;
            a = min(a, temp);
            cin >> temp;
            b = min(b, temp);
            cin >> temp;
            c = min(c, temp);
            cin >> temp;
            d = min(d, temp);
        }
        if(a + b + c + d < 1e6){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        int rem = 1e6;
        cout << min(a, rem) << " ";
        rem -= min(a, rem);
        cout << min(b, rem) << " ";
        rem -= min(b, rem);
        cout << min(c, rem) << " ";
        rem -= min(c, rem);
        cout << min(d, rem) << "\n";
        rem -= min(d, rem);
    }

}