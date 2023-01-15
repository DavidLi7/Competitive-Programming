#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2;
const int MAXQ = 10;
const int MAXS = 1 << 10;

int T, N, Q, a[MAXN], score[MAXS], s[MAXN];

void gen(int x, int bit, int curr, int currsum){
    if(bit == Q){
        score[curr] += currsum;
    }
    else{
        bool hasbit = (x & (1 << bit));
        gen(x, bit + 1, curr + (1 << bit), currsum + hasbit);
        gen(x, bit + 1, curr, currsum + 1 - hasbit);
    }
}

int getGCD(int a, int b){
    if(b == 0)
        return a;
    return getGCD(b, a % b);
}

void solve(){
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp >> a[i];
        s[i] = 0;
        for(int j = 0; j < Q; j++){
            if(temp[j] == 'T')
                s[i] += (1 << j);
        }
    }
    for(int i = 0; i < (1 << Q); i++){
        score[i] = 0;
    }
    int tot = 0;
    for(int i = 0; i < (1 << Q); i++){
        bool ok = true;
        for(int j = 0; j < N; j++){
            int c = 0;
            for(int k = 0; k < Q; k++){
                if((i & (1 << k)) == (s[j] & (1 << k))){
                    c++;
                }
            }
            if(c != a[j]){
                ok = false;
                break;
            }
        }
        if(ok){
            tot++;
            gen(i, 0, 0, 0);
        }
    }
    pair<int, int> ans = make_pair(0, 0);
    for(int i = 0; i < (1 << Q); i++){
        ans = max(ans, make_pair(score[i], i));
    }
    for(int i = 0; i < Q; i++){
        if(ans.second & (1 << i)){
            cout << "T";
        }
        else{
            cout << "F";
        }
    }
    cout << " ";
    int gcd = getGCD(ans.first, tot);
    cout << ans.first/gcd << "/" << tot/gcd << "\n";
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    
    
    
}