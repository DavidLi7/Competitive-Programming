#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        set<int> a;
        int s = 0;
        for(int j = i; j < N; j++){
            a.insert(nums[j]);
            s += nums[j];
            if(s % (j - i + 1) == 0 && a.count(s / (j - i + 1))){
                ans++;
            }
        }
    }
    cout << ans;
}