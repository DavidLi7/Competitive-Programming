#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5 + 5;

long long N, a[MAXN], BIT[MAXN], ans[MAXN];

void upd(int i){
    i++;
    while(i <= N){
        BIT[i]++;
        i += i & -i;
    }
}

long long get(int i){
    i++;
    int ret = 0;
    while(i > 0){
        ret += BIT[i];
        i -= i & -i;
    }
    return ret;
}

int main(){
    setIO("haircut");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(long long i = 0; i < N; i++){
        ans[a[i] + 1] += i - get(a[i]);
        upd(a[i]);
    }
    for(int i = 0; i < N; i++){
        ans[i + 1] += ans[i];
        cout << ans[i] << "\n";
    }
}