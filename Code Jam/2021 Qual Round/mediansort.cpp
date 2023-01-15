#include <iostream>

using namespace std;

const int MAXN = 55;

int T, N, Q, ans[MAXN], loc[MAXN], a[MAXN];
bool wrongans;

int query(int i, int j, int k){
    cout << i << " " << j << " " << k << endl;
    int ret;
    cin >> ret;
    return ret;

    // testing
    // if((loc[i] < loc[j] && loc[k] < loc[i]) || (loc[i] > loc[j] && loc[k] > loc[i]))
    //     return i;
    // if((loc[j] < loc[i] && loc[k] < loc[j]) || (loc[j] > loc[i] && loc[k] > loc[j]))
    //     return j;
    // return k;
}

bool submit(){
    for(int i = 1; i <= N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    int result;
    cin >> result;
    return (result == 1);


    //testing
    // return true;
}

void setup(){
    int ret = query(1, 2, 3);
    bool gotfirst = false;
    for(int i = 1; i <= 3; i++){
        if(ret == i){
            ans[2] = i;
        } else{
            if(gotfirst){
                ans[3] = i;
            } else{
                gotfirst = true;
                ans[1] = i;
            }
        }
    }
}

void insert(int k){
    int lo = 1;
    int hi = k;
    while(lo < hi - 1){
        int mid = (lo + hi) / 2;
        int ret = query(ans[lo], k, ans[mid]);
        if(ret == ans[lo]){
            for(int i = k - 1; i >= lo; i--){
                ans[i + 1] = ans[i];
            }
            // cout << "testing insert: " << k << " " << lo << "\n";
            ans[lo] = k;
            return;
        }
        if(ret == k){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    if(hi == k){
        int ret = query(ans[lo - 1], ans[lo], k);
        if(ret == ans[lo])
            lo++;
    } else{
        int ret = query(ans[lo], k, ans[hi]);
        if(ret == k)
            lo++;
    }
    for(int i = k - 1; i >= lo; i--){
        ans[i + 1] = ans[i];
    }
    // cout << "testing insert: " << k << " " << lo << "\n";
    ans[lo] = k;
}

void solve(){
    for(int i = 1; i <= N; i++){
        ans[i] = -1;
    }

    // testing
    // for(int i = 1; i <= N; i++){
    //     cin >> a[i];
    //     loc[a[i]] = i;
    // }

    setup();
    // cout << ans[1] << " " << ans[2] << " " << ans[3] << " : initial\n";
    for(int i = 4; i <= N; i++){
        insert(i);
    }
    if(!submit()){
        wrongans = true;
    }
}   

int main() {

     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T >> N >> Q;
    while(T--){
        solve();
        if(wrongans)
            break;
    }
    
}