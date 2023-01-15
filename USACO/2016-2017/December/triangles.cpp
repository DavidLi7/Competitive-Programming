#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 300;

long long x[MAXN], y[MAXN], N, below[MAXN][MAXN], c[MAXN];

bool isUnder(int a, int b, int c){
    if(x[a] > x[b])
        swap(a, b);
    if(x[c] <= x[b] && x[c] >= x[a]){
        return ((long double)y[a] + (long double)((x[c] - x[a]) * (y[b] - y[a])) / (long double)(x[b] - x[a])) > y[c];
    }
    return false;
}

bool isAbove(int a, int b, int c){
    if(x[a] >= x[b])
        swap(a, b);
    if(x[c] <= x[b] && x[c] >= x[a]){
        return ((long double)y[a] + (long double)((x[c] - x[a]) * (y[b] - y[a])) / (long double)(x[b] - x[a])) < y[c];
    }
    return false;
}

int inside(int a, int b, int c){
    if(isUnder(a, b, c)){
        return below[a][b] - below[a][c] - below[b][c] - 1;
    }
    if(isUnder(a, c, b)){
        return below[a][c] - below[b][c] - below[a][b] - 1;
    }
    if(isUnder(b, c, a)){
        return below[b][c] - below[a][c] - below[a][b] - 1;
    }
    if(isAbove(a, b, c)){
        return -below[a][b] + below[a][c] + below[b][c];
    }
    if(isAbove(a, c, b)){
        return -below[a][c] + below[b][c] + below[a][b];
    }
    if(isAbove(b, c, a)){
        return -below[b][c] + below[a][c] + below[a][b];
    }
    return 0;

}

int main(){
    setIO("triangles");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = 0; k < N; k++) if(k != i && k != j){
                if(isUnder(i, j, k))
                    below[i][j]++;
            }
            below[j][i] = below[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                c[inside(i, j, k)]++;
            }
        }
    }

    for(int i = 0; i < N - 2; i++){
        cout << c[i] << "\n";
    }



}