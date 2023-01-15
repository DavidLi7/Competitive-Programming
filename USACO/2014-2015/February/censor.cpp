#include <iostream>
#include <map>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N;
long long po[MAXN], invpo[MAXN], inv, b = 998244353;
string s;
map<int, vector<pair<int, string> > > m;
vector<int> curr;
vector<char> ans;
vector<int> hsh;

int getHash(string t){
    long long ret = 0;
    for(int i = 0; i < t.size(); i++){
        ret = (ret + 1LL * (t[i] - 'a' + 1) * po[i]) % MOD;
    }
    return ret;
}

int getHash(int d){
    if(d == ans.size())
        return hsh.back();
    int en = ans.size() - 1;
    int st = ans.size() - d;
    long long ret = hsh[en];
    ret -= hsh[st - 1];
    ret = (ret * invpo[st]) % MOD;
    return ret;
}

int power(long long x, long long y){
    if(y == 0)
        return 1;
    long long p = power(x, y / 2);
    p = (p * p) % MOD;
    if(y % 2 == 1)
        p = (p * x) % MOD;
    return p;
}

int getInv(int t){
    return power(t, MOD - 2);
}

int main(){
    setIO("censor");
    cin >> s >> N;
    inv = getInv(b);
    po[0] = invpo[0] = 1;
    for(int i = 1; i < MAXN; i++){
        po[i] = (1LL * po[i - 1] * b) % MOD;
        invpo[i] = getInv(po[i]);
    }
    for(int i = 0; i < N; i++){
        string t;
        cin >> t;
        m[-t.size()].push_back(make_pair(getHash(t), t));
    }
    for(int i = 0; i < s.size(); i++){
        if(!hsh.size())
            hsh.push_back(((s[i] - 'a' + 1) * po[i]) % MOD);
        else
            hsh.push_back((hsh.back() + 1LL * (s[i] - 'a' + 1) * po[ans.size()]) % MOD);
        ans.push_back(s[i]);
        bool done = false;
        for(auto it: m){
            if(done)
                break;
            if(-it.first <= ans.size()){
                int thsh = getHash(-it.first);
                if(thsh < 0)
                        thsh += MOD;
                for(auto x: it.second){
                    if(x.first == thsh){
                        string sub = "";
                        for(int j = ans.size() + it.first; j < ans.size(); j++)
                            sub += ans[j];
                        if(x.second == sub){
                            for(int j = 0; j < -it.first; j++){
                                ans.pop_back();
                                hsh.pop_back();
                            }
                            done = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    for(char x: ans)
        cout << x;
    
}