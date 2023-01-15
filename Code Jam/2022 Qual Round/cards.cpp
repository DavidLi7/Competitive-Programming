#include <iostream>

using namespace std;

const int MAXN = 11;

int T, R, C;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cout << "Case #" << t << ":\n";
        cin >> R >> C;
        for(int i = 0; i < 2 * R + 1; i++){
            for(int j = 0; j < 2 * C + 1; j++){
                if(max(i, j) < 2)
                    cout << ".";
                else if(i % 2 == 0 && j % 2 == 0)
                    cout << "+";
                else if(i % 2 == 0)
                    cout << "-";
                else if(j % 2 == 0)
                    cout << "|";
                else
                    cout << ".";
            }
            cout << "\n";
        }
    }

}