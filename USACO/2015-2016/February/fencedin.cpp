#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 25001;

int vert[MAXN], hori[MAXN], N, M, a, b;

int main(){
    setIO("fencedin");
    cin >> a >> b >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> vert[i];
    }
    for(int i = 0; i < M; i++){
        cin >> hori[i];
    }
    sort(vert, vert + N);
    sort(hori, hori + M);
    vert[N] = a;
    hori[M] = b;
    for(int i = N; i > 0; i--){
        vert[i] = vert[i] - vert[i - 1];
    }
    for(int i = M; i > 0; i--){
        hori[i] = hori[i] - hori[i - 1];
    }
    sort(vert, vert + N + 1);
    sort(hori, hori + M + 1);

    int v = 1;
    int h = 1;
    long long ans = 0;
    ans += 1LL * vert[0] * M + 1LL * hori[0] * N;
    while(v <= N && h <= M){
        if(vert[v] < hori[h]){
            ans += 1LL * vert[v] * (M - h + 1);
            v++;
        }
        else{
            ans += 1LL * hori[h] * (N - v + 1);
            h++;
        }
    }
    cout << ans;




}