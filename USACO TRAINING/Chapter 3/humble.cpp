/*
ID: divadxl1
LANG: C++
TASK: humble
*/
#include <iostream>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100;

int K, N;
long long a[MAXN];

int main(){
    setIO("humble");
    set<long long>nums;
    cin >> K >> N;
    for(int i = 0; i != K; ++i){
        cin >> a[i];
        nums.insert(a[i]);
    }
    long long x = *nums.begin();
    long long mn = x;
    for(int i = 0; i != N; ++i){
        int mx = *prev(nums.end());
        if(nums.size() == N && x * mn > mx)
            break;
        for(int j = 0; j != K; ++j){
            if(x * a[j] > mx && nums.size() == N)
                continue;
            nums.insert(x * a[j]);
            if(nums.size() == N + 1){
                nums.erase(prev(nums.end()));
            }
        }
        x = *nums.upper_bound(x);
    }
    cout << *prev(nums.end()) << "\n";
}