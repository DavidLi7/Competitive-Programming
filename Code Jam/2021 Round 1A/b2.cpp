#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXM = 100;
const int MAXP = 500;
const int MAXS = 100000;

int T, M, p[MAXM], n[MAXM], occ[MAXP]; 
vector<int> nums, primes;
bool possibleSum[MAXS], isComposite[MAXP];

int ok(int x){
    int ret = 0;
    for(int z: primes){
        for(int i = 0; i < occ[z]; i++){
            if(x % z == 0){
                x /= z;
                ret += z;
            }
        }
    }
    if(x == 1)
        return ret;
    else
        return 0;
}

void solve(){
    cin >> M;
    for(int i = 0; i < MAXP; i++){
        occ[i] = 0;
    }
    nums.clear();
    for(int i = 0; i < M; i++){
        cin >> p[i] >> n[i];
        for(int j = 0; j < n[i]; j++){
            nums.push_back(p[i]);
        }
        occ[p[i]] = n[i];
    }
    for(int i = 0; i < MAXS; i++){
        possibleSum[i] = false;
    }
    possibleSum[0] = true;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        set<int> candidates;
        for(int j = 0; j < MAXS; j++){
            if(possibleSum[j] && j + nums[i] < MAXS && !possibleSum[j + nums[i]]){
                candidates.insert(j + nums[i]);
            }
        }
        for(int x: candidates){
            possibleSum[x] = true;
        }
    }
    for(int i = 1; i < MAXS; i++){
        if(possibleSum[i] && i < 49900){
            int ret = ok(i);
            if(ret != 0 && possibleSum[ret + i])
                ans = i;
        }
    }
    cout << ans << "\n";
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;

    isComposite[1] = true;
    for(int i = 2; i < MAXP; i++){
        if(!isComposite[i]){
            primes.push_back(i);
            for(int j = i + i; j < MAXP; j += i){
                isComposite[j] = true;
            }
        }
    }
    
    for(int i = 1; i <= T; i++){
        // cout << "Case #" << i << ": ";
        solve();
        // cout << "\n";
    }

    
    
    
}
/*
1
5
2 2
3 1
5 2
7 1
11 1
*/