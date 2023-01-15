#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 505;

int N, a[MAXN];
vector<int> ans;

int main(){
    setIO("fcount");
    cin >> N;
    for(int i = 0; i < N + 1; i++)
        cin >> a[i];
    for(int i = 0; i < N + 1; i++){
        vector<int> nums;
        for(int j = 0; j < N + 1; j++){
            if(i != j && a[j] != 0)
                nums.push_back(a[j]);
        }
        bool ok = true;
        sort(nums.begin(), nums.end());
        while(nums.size()){
            int e = nums.back();
            nums.pop_back();
            vector<int> n;
            while(e && nums.size()){
                if(nums.back() != 1)
                    n.push_back(nums.back() - 1);
                nums.pop_back();
                e--;
            }
            if(e){
                ok = false;
                break;
            }
            int j = 0;
            int k = n.size() - 1;
            vector<int> nums2;
            while(j != nums.size() || k != -1){
                if(j == nums.size()){
                    nums2.push_back(n[k]);
                    k--;
                }
                else if(k == -1){
                    nums2.push_back(nums[j]);
                    j++;
                }
                else{
                    if(n[k] < nums[j]){
                        nums2.push_back(n[k]);
                        k--;
                    }
                    else{
                        nums2.push_back(nums[j]);
                        j++;
                    }
                }
            }
            nums = nums2;
        }
        if(ok)
            ans.push_back(i + 1);

    }
    cout << ans.size() << "\n";
    for(int x: ans)
        cout << x << "\n";
}
//2 2 2
//1 1 2
//0 1 1
//0 0 0

//2 2 1 1
//0 1 1 0
//0 0 0 0