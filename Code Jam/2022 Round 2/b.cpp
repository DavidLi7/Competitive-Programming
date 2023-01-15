#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int MAXN = 205;

int R, T;
bool grid1[MAXN][MAXN], grid2[MAXN][MAXN];

void empty1(int i, int j){
    grid1[i + 101][j + 101] = false;
}
void empty2(int i, int j){
    grid2[i + 101][j + 101] = false;
}
void fill1(int i, int j){
    grid1[i + 101][j + 101] = true;
}
void fill2(int i, int j){
    grid2[i + 101][j + 101] = true;
}
bool get1(int i, int j){
    return grid1[i + 101][j + 101];
}
bool get2(int i, int j){
    return grid2[i + 101][j + 101];
}

void solve(){
   cin >> R;
   for(int i = -R; i <= R; i++){
       for(int j = -R; j <= R; j++){
           empty1(i, j);
           empty2(i, j);
       }
   }
    for(int r = R; r >= 0; r--){
        for(int i = -r; i <= r; i++){
            int j = round(sqrt(r * r - i * i));
            fill1(i, j);
            fill1(i, -j);
            fill1(j, i);1 
            fill1(-j, i);
        }
    }
    for(int i = -R; i <= R; i++){
        for(int j = -R; j <= R; j++){
            if(round(sqrt(i * i + j * j)) <= R)
                fill2(i, j);
        }
    }
    int ans = 0;
    for(int i = -R; i <= R; i++){
        for(int j = -R; j <= R; j++){
            //cout << get1(i, j) << " ";
            if(get1(i, j) != get2(i, j))
                ans++;
        }
        //cout << "\n";
    }
    // for(int i = -R; i <= R; i++){
    //     for(int j = -R; j <= R; j++){
    //         cout << get2(i, j) << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans;
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }

    
    
    
}