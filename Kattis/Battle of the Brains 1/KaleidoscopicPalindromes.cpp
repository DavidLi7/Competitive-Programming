#include <iostream>
#include <vector>

using namespace std;

int a, b, k;

bool ok(int num, int b){
    vector<int> a;
    while(num != 0){
        a.push_back(num % b);
        num /= b;
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] != a[a.size() - 1 - i])
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b >> k;
    int ans = 0;
    for(int i = a; i <= b; i++){
        bool good = true;
        for(int j = 2; j <= k; j++){
            if(!ok(i, j)){
                good = false;
                break;
            }
        }
        ans += good;
    }
    cout << ans;
}