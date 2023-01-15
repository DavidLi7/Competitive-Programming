#include <iostream>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 50000;

int N, E[MAXN], pre[MAXN], suff[MAXN];
bool used[MAXN];
set<int>B;

int main(){
    setIO("cardgame");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> E[i];
        E[i]--;
        used[E[i]] = true;
    }

    for(int i = 0; i < 2 * N; i++){
        if(!used[i]){
            B.insert(i);
        }
    }

    for(int i = 0; i < N; i++){
        if(i!=0)
            pre[i] = pre[i - 1];
        set<int>::iterator it = B.upper_bound(E[i]);;
        if(it != B.end()){
            B.erase(it);
            pre[i]++;
        }
    }

    for(int i = 0; i < 2 * N; i++){
        if(!used[i]){
            B.insert(i);
        }
    }

    for(int i = N - 1; i >= 0; i--){
        if(i != N - 1)
            suff[i] = suff[i + 1];
        set<int>::iterator it = B.upper_bound(E[i]);
        if(it != B.begin()){
            it--;
            B.erase(it);
            suff[i]++;
        }
    }
    
    int mx = max(pre[N-1],suff[0]);
    for(int i = 0; i < N - 1; i++){
        mx = max(mx, pre[i] + suff[i + 1]);
    }
    cout << mx;

}