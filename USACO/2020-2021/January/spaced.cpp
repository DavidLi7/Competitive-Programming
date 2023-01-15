#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 1005;

int N, g[MAXN][MAXN];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> g[i][j];
        }
    }
    int a1 = 0;
    for(int i = 0; i < N; i++){
        int o = 0;
        int e = 0;
        for(int j = 0; j < N; j++){
            if(j % 2 == 0)
                e += g[i][j];
            else
                o += g[i][j];
        }
        a1 += max(o, e);
    }
    int a2 = 0;
    for(int i = 0; i < N; i++){
        int o = 0;
        int e = 0;
        for(int j = 0; j < N; j++){
            if(j % 2 == 0)
                e += g[j][i];
            else
                o += g[j][i];
        }
        a2 += max(o, e);
    }
    cout << max(a1, a2);
}