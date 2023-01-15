#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1005;

int N;
int grid[MAXN][MAXN], ans1, ans2;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        vector<int> sums(2, 0);
        for(int j = 0; j < N; j++){
            sums[j % 2] += grid[i][j];
        }
        ans1 += max(sums[0], sums[1]);
    }

    for(int i = 0; i < N; i++){
        vector<int> sums(2, 0);
        for(int j = 0; j < N; j++){
            sums[j % 2] += grid[j][i];
        }
        ans2 += max(sums[0], sums[1]);
    }

    cout << max(ans1, ans2);

}