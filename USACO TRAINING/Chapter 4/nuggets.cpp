/*
ID: divadxl1
LANG: C++
TASK: nuggets
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int GCD(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return GCD(b, a % b);  
      
} 

const int MAXN = 0;

bool ok[257];

int main(){
    setIO("nuggets");
    int N;
    cin >> N;
    vector<int> nums(N);
    int gcd = 0;
    for(int i = 0; i < N; i++){
        cin >> nums[i];
        ok[nums[i]] = true;
        gcd = GCD(nums[i], gcd);
    }
    sort(nums.begin(), nums.end());
    if(gcd != 1 || nums[0] == 1){
        cout << "0\n";
        return 0;
    }
    int c = 1;
    int len = 0;
    int s = 0;
    while(true){
        if(len > 256)
            break;
        if(ok[c % 256]){
            s = c - len;
            len++;
            ok[c % 256] = false;
            for(int i = 0; i < N; i++){
                ok[(c + nums[i]) % 256] = true;
            }
            
        }
        else{
            len = 0;
        }
        c++;
    }
    cout << s - 1 << "\n";

    
}