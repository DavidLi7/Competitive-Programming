#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXM = 100;
const int MAXP = 500;
const int MAXS = 50000;

int T, M, p[MAXM], n[MAXM], occ[MAXP]; 
vector<int> nums, primes;
bool possibleSum[MAXS], isComposite[MAXP];

bool ok(int x){
    for(int z: primes){
        for(int i = 0; i < occ[z]; i++){
            if(x % z == 0){
                x /= z;
            }
        }
    }
    return (x == 1);
}

void solve(){
    cin >> M;
    for(int i = 0; i < MAXP; i++){
        occ[i] = 0;
    }
    for(int i = 0; i < M; i++){
        cin >> p[i] >> n[i];
        for(int j = 0; j < n[i]; j++){
            nums.push_back(p[i]);
        }
        occ[p[i]] = n[i];
    }
    possibleSum[0] = true;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        occ[nums[i]]--;
        set<int> candidates;
        for(int j = 0; j < MAXS; j++){
            if(possibleSum[j] && j + nums[i] < MAXS && !possibleSum[j + nums[i]]){
                candidates.insert(j + nums[i]);
            }
        }
        for(int x: candidates){
            if(ok(x)){
                ans = max(ans, x);
            }
        }
        for(int x: candidates){
            possibleSum[x] = true;
        }
        cout << "curr: " << nums[i] << "\n";
        for(int j = 0; j < 100; j++){
            if(possibleSum[j])
                cout << j << " ";
        }
        cout << "\n";
    }
    cout << ans;
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