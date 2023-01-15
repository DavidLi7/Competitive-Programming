#include <iostream>

using namespace std;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    int t, h, m;
    cin >> t >> h >> m;
    m /= 10;
    if(h == 0 || h > t){
        for(int i = 0; i < t; i++){
            cout << "#\n";
        }
    }
    else{
        for(int i = 1; i < h - 1; i++){
            cout << "#\n";
        }
        cout << "#";
        for(int i = 0; i < m; i++){
            cout << ".";
        }
        for(int i = 0; i < t - h + 1; i++){
            cout << "#";
        }
    }

}