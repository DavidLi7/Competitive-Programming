#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int N, o, e;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x % 2 == 0)
            e++;
        else
            o++;
    }
    int ans = 0;
    while(true){
        if(ans % 2 == 0){
            if(e){
                e--;
                ans++;
            }
            else if(o >= 2){
                o -= 2;
                ans++;
            }
            else{
                break;
            }
        }
        else{
            if(o){
                o--;
                ans++;
            }
            else{
                break;
            }
        }
    }
    ans -= o;
    cout << ans;

}