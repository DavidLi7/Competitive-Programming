#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int MAXN = 205;

int R, T;

void solve(){
   cin >> R;
   int ans = 0;
   for(int r = 0; r <= R; r++){
       int j = 0;
       for(;j <= r + 1; j++){
           if(sqrt(r * r + j * j) > r){
               j--;
               break;
           }
       }
   }
   for(int i = 0; i <= R; i++){
       int j = 0;
       for(; j <= R + 1; j++){
           if(sqrt(i * i + j * j) > R){
               j--;
               break;
           }
       }
       //cout << i << " " << j << "\n";
       cout << j << " " << round(sqrt(R * R - i * i)) << "\n";
       //ans += round(sqrt(R * R - i * i)) - j;
   }
   cout << 4 * ans;
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