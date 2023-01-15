/*
ID: divadxl1
LANG: C++
TASK: buylow
*/
#include <iostream>
#include <map>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

class bignum{
    public:
        int len;
        int d[200];
        bignum() {len = 1; d[1] = 0;}
        bignum(long long x) {
            if(x == 0){
                len = 1;
                d[1] = 0;
                return;
            }
            for(len = 1; x != 0; len++){
                d[len] = x % 10;
                x /= 10;
            }
            len--;
        }
        bignum operator + (const bignum &b){
            bignum ret = bignum();
            int l = max(this->len, b.len);
            int i = 1;
            int rem = 0;
            int temp = 0;
            while(i <= l || rem != 0){
                temp = rem;
                if(i <= this->len) temp += this->d[i];
                if(i <= b.len) temp += b.d[i];
                ret.d[i] = temp % 10;
                rem = temp / 10;
                i++;
            }
            ret.len = i - 1;
            return ret;
        }
        friend ostream &operator<<(ostream &out, const bignum &b){
            for(int i = b.len; i >= 1; i--){
                out << b.d[i];
            }
            return out;
        }

};

const int MAXN = 5000;

int N;
long long p[MAXN];
pair<long long, bignum> dp[MAXN];

int main(){
    setIO("buylow");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    pair<long long, bignum> ans = make_pair(1, bignum());
    map<long long, bignum> use;
    for(int i = 0; i < N; i++){
        dp[i] = make_pair(1, bignum());
        map<long long, bignum> used;
        used[p[i]] = bignum(1);
        for(int j = 0; j < i; j++) if(p[j] > p[i]){
            if(dp[j].first + 1 > dp[i].first){
                dp[i] = make_pair(dp[j].first + 1, 0);
                used.clear();
                used[p[j]] = dp[j].second;
            }
            else if(dp[j].first + 1 == dp[i].first){
               used[p[j]] = dp[j].second;
            }
        }
        for(map<long long, bignum>::iterator it = used.begin(); it != used.end(); it++){
            dp[i].second = dp[i].second + it->second;
        }
        if(dp[i].first == ans.first){
            use[p[i]] = dp[i].second;
        }
        else if(dp[i].first > ans.first){
            use.clear();
            use[p[i]] = dp[i].second;
            ans = make_pair(dp[i].first, 0);
        }
    }
    for(map<long long, bignum>::iterator it = use.begin(); it != use.end(); it++){
        ans.second = ans.second + it->second;
    }
    cout << ans.first << " " << ans.second << "\n";
}