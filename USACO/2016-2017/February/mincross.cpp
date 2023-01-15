#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;


int map1[MAXN], map2[MAXN], a[MAXN], b[MAXN], BIT[MAXN+5];

int get(int i){
    int ret = 0;
    i++;
    while(i > 0){
        ret += BIT[i];
        i -= i & -i;
    }
    return ret;
}
void inc(int i){
    i++;
    while(i < MAXN + 5){
        BIT[i]++;
        i += i & -i;
    }
}

int main(){
    //setIO("mincross");

    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i-1];
        a[i-1]--;
        map2[a[i-1]] = i;
    }
    for(int i = 1;i <= N; i++){
        cin >> b[i-1];
        b[i-1]--;
        map1[b[i-1]] = i;
    }
    long long curr = 0;
    for(int i = 0; i < N; i++){
        curr += (i - get(map1[a[i]]));
        inc(map1[a[i]]);
    }
    long long s = curr;
    long long mn = curr;
    //cout << curr<< endl;
    for(int i = N - 1; i > 0; i--){
        curr +=(2 * map1[a[i]] - N - 1);
        mn = min(mn, curr);
        //cout << curr<< endl;
    }
    curr = s;
    //cout<<curr<<" a"<<endl;
    for(int i = N - 1; i > 0; i--){
        curr += (2 * map2[b[i]] - N - 1);
        mn = min(mn,curr);
    }
    cout<<mn;

}