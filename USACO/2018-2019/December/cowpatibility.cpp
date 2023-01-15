#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 50005;

long N;

struct seq{
    int n;
    int nums[5];
};

bool operator < (const seq &a, const seq &b){
    for(int j = 0; j < 5; j++){
        if(a.nums[j] < b.nums[j])
            return true;
        if(a.nums[j] > b.nums[j])
            return false;
    }
    return false;
}

map<seq, long> mp;
int nums[MAXN][5];

void gen(int i, int j){
    seq t;
    t.n = 0;
    t.nums[0] = 0;
    t.nums[1] = 0;
    t.nums[2] = 0;
    t.nums[3] = 0;
    t.nums[4] = 0;
    for(int k = 0; k < 5; k++){
        if((1 << k) & j){
            t.nums[t.n++] = nums[i][k];
        }
    }
    mp[t]++;
}

int main(){
    setIO("cowpatibility");
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++){
            cin >> nums[i][j];
        }
        sort(nums[i], nums[i] + 5);
        for(int j = 0; j < 32; j++){
            gen(i, j);
        }
    }
    long ans = N * (N - 1LL) / 2LL;
    for(auto it: mp){
        if(it.first.n != 0 && it.second >= 2LL){
            // cout << it.first.n << " ";
            // for(int i = 0; i < it.first.n; i++){
            //     cout << it.first.nums[i] << " ";
            // }
            // cout << ": ";
            // cout << it.second << "\n";
            if(it.first.n % 2 == 1)
                ans -= (it.second * (it.second - 1LL) / 2LL) * 1LL;
            else
                ans += (it.second * (it.second - 1LL) / 2LL) * 1LL;
        }
        
    }
    cout << ans;
}

/*
4
1 2 3 4 5
1 2 3 4 5
6 7 8 9 10
1 2 3 4 10
*/
//5 * 4 / 2 = 10
//6 + 6 - 3 = 9