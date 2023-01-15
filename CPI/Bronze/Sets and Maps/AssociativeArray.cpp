#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int Q;
    unordered_map<long long, long long> m;
    cin >> Q;
    while(Q--){
        int t;
        cin >> t;
        if(t == 0){
            long long k, v;
            cin >> k >> v;
            m[k] = v;
        }
        else{
            long long k;
            cin >> k;
            cout << m[k] << "\n";
        }
    }
}