#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

const int MAXN = 105;

int N, T;
string s;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    
    cout << "1\n5 3\n";
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++)
            cout << rand() % 3 << " ";
        cout << "\n";
    }
    
    
    
}