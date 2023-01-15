#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100001;

int N; //number of cows
int M; //number of stores
int R; //number of people willing to rent
long long f[MAXN]; //max money we can make from renting the i best cows
long long g[MAXN]; //max money we can make from selling the i worst cows
long long cows[MAXN]; 
long long farmers[MAXN]; 
pair<int, int> stores[MAXN];
// first = p, second = q

int main(){
    setIO("rental");
    cin >> N >> M >> R;

    //read cows, sort from best to worst
    for(int i = 0; i < N; i++){
        cin >> cows[i];
    }
    sort(cows, cows + N);
    reverse(cows, cows + N);

    //read stores, sort from best price to worst price
    for(int i = 0; i < M; i++){
        cin >> stores[i].second >> stores[i].first;
    }
    sort(stores, stores + M);
    reverse(stores, stores + M);

    //read farmers, sort from best to worst price
    for(int i = 0; i < R; i++){
        cin >> farmers[i];
    }
    sort(farmers, farmers + R);
    reverse(farmers, farmers + R);

    // find the various f[i]s
    int sindex = 0;
    for(int i = 1; i <= N; i++){
        f[i] = f[i - 1];
        long long curr = cows[i - 1];
        //while we can buy out the whole store and stores are available
        while(sindex < M && stores[sindex].second <= curr){
            curr -= stores[sindex].second;
            f[i] += stores[sindex].first * stores[sindex].second;
            sindex++;
        }
        //this store can not be completely bought out, so buy out cow
        if(sindex < M){//only if there is a store available
            f[i] += curr * stores[sindex].first;
            stores[sindex].second -= curr; //store has less cows left to buy
        }
    }

    //find the various g[i]s
    for(int i = 1; i <= N; i++){
        g[i] = g[i - 1];
        //we only add if there are still renters available
        if(i <= R){
            g[i] += farmers[i - 1];
        }
    }

    // find max = f[i] + g[N - i]
    long long ans = 0;
    for(int i = 0; i <= N; i++){
        ans = max(ans, f[i] + g[N - i]);
    }
    cout << ans;
}