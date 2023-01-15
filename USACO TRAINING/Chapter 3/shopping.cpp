/*
ID: divadxl1
LANG: C++
TASK: shopping
*/
#include <iostream>
#include <map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int dp[6][6][6][6][6], goal[5], offer[105][6], S, B, curr, nums[5], cont[5];
bool ok[6][6][6][6][6];
map<int, int> m;

int main(){
    setIO("shopping");
    cin >> S;
    for(int i = 0; i < S; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int c, k;
            cin >> c >> k;
            if(m.find(c) == m.end()){
                m[c] = curr++;
            }
            offer[i][m[c]] = k;
        }
        cin >> offer[i][5];
    }
    cin >> B;
    for(int i = 0; i < B; i++){
        int c, k, p;
        cin >> c >> k >> p;
        if(m.find(c) == m.end()){
            m[c] = curr++;
        }
        offer[100 + i][m[c]] = 1;
        offer[100 + i][5] = p;
        goal[m[c]] = k;
    }
    ok[0][0][0][0][0] = true;
    for(nums[0] = 0; nums[0] <= goal[0]; nums[0]++){
        for(nums[1] = 0; nums[1] <= goal[1]; nums[1]++){
            for(nums[2] = 0; nums[2] <= goal[2]; nums[2]++){
                for(nums[3] = 0; nums[3] <= goal[3]; nums[3]++){
                    for(nums[4] = 0; nums[4] <= goal[4]; nums[4]++){
                        for(int i = 0; i < 105; i++){
                            bool okop = true;
                            for(int j = 0; j < 5; j++){
                                cont[j] = nums[j] - offer[i][j];
                                if(cont[j] < 0){
                                    okop = false;
                                    break;
                                }
                            }
                            if(!okop)
                                continue;
                            if(ok[cont[0]][cont[1]][cont[2]][cont[3]][cont[4]]){
                                if(!ok[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]]){
                                    dp[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]] = dp[cont[0]][cont[1]][cont[2]][cont[3]][cont[4]] + offer[i][5];
                                    ok[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]] = true;
                                }
                                else{
                                    dp[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]] = min(dp[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]],dp[cont[0]][cont[1]][cont[2]][cont[3]][cont[4]] + offer[i][5]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[goal[0]][goal[1]][goal[2]][goal[3]][goal[4]] << "\n";
    
    
}