#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

struct bale{
    int x, w, i;
    bale() : i(0){}
    bale(int weight, int loc) : x(loc), w(weight), i(0){}
    bale(int weight, int loc, int ind) : x(loc), w(weight), i(ind){}
    bool operator <(const bale& y) const{
        return x < y.x;
    }
};

bool sortByW(const bale x, const bale y){
    return x.w > y.w;
}

int N, pre[MAXN];
bale bales[MAXN];

int main(){
    setIO("trapped");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> bales[i].w >> bales[i].x;
    }
    sort(bales, bales + N);
    for(int i = 0; i < N; i++){
        bales[i].i = i + 1;
    }
    sort(bales, bales + N, sortByW);
    set<bale> s;
    s.insert(bale(0, 1e9 + 1, N + 1));
    s.insert(bale(0, 0, 0));
    for(int i = 0; i < N; i++){
        // cout << bales[i].x << " " << bales[i].w << "\n";
        set<bale>::iterator it = s.upper_bound(bales[i]);
        //check right
        if(it -> x - bales[i].x <= min(it -> w, bales[i].w)){
            //bad
            // cout << i << " " << bales[i].i << " " << it -> i + 1 << " right \n";
            pre[bales[i].i]++;
            pre[it -> i]--;
        }
        //check left
        it = prev(it);
        if(bales[i].x - it -> x <= min(it -> w, bales[i].w)){
            //bad
            // cout << i << " " << it -> i << " " << bales[i].i + 1 << " left \n";
            pre[it -> i]++;
            pre[bales[i].i]--;
        }
        s.insert(bales[i]);
    }
    for(int i = 1; i <= N; i++){
        pre[i] += pre[i - 1];
    }
    int ans = 0;
    sort(bales, bales + N);
    for(int i = 1; i < N; i++){
        if(pre[i]){
            // cout << i << "hi\n";
            ans += bales[i].x - bales[i - 1].x;
        }
    }
    cout << ans;


}