#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int N, T;

void solve(){

    cin >> N;
    long sum = 0;
    vector<long> nums;
    for(int i = 0; i < 30; i++){    //30
        cout << (1 << i) << " ";
        sum += (1 << i);
    }
    for(int i = 0; i < 70; i++){    //70
        cout << (int)(1e9 - i) << " ";
        sum += (1e9 - i);
        nums.push_back((long)(1e9 - i));
    }
    cout << endl;
    for(int i = 0; i < 100; i++){
        long x;
        cin >> x;
        sum += x;
        nums.push_back(x);
    }
    sum /= 2LL;
    sort(nums.begin(), nums.end());
    for(int i = nums.size() - 1; i >= 0; i--){
        if(sum - nums[i] >= 0LL){
            cout << nums[i] << " ";
            sum -= nums[i];
        }
    }
    for(int i = 0; i < 30; i++){
        if(sum & (1 << i)){
            cout << (1 << i) << " ";
            sum -= (1 << i);
        }
    }
    cout << endl;
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    
    for(int i = 1; i <= T; i++){
        solve();
    }

    
    
    
}