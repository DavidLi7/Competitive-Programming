/*
ID: divadxl1
LANG: C++
TASK: job
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 30;

int N, M1, M2, A[MAXN], B[MAXN], At[MAXN], Bt[MAXN];
vector<int> t;

int main(){
    setIO("job");
    cin >> N >> M1 >> M2;
    for(int i = 0; i < M1; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M2; i++){
        cin >> B[i];
    }
    sort(A, A + M1);
    sort(B, B + M2);
    int a = -1;
    int b = -1;
    for(int i = 0; i < N; i++){
        int mn = At[0] + A[0];
        int mni = 0;
        for(int j = 1; j < M1; j++){
            if(At[j] + A[j] < mn){
                mni = j;
                mn = At[j] + A[j];
            }
        }
        t.push_back(mn);
        At[mni] += A[mni];
        a = max(a, mn);
    }
    sort(t.begin(), t.end());
   /* for(int i = 0; i < N; i++){
        cout << t[i] << "\n";
    }*/
    for(int i = 0; i < N; i++){
        int mn = Bt[0] + B[0];
        int mni = 0;
        for(int j = 1; j < M2; j++){
            if(Bt[j] + B[j] < mn){
                mni = j;
                mn = Bt[j] + B[j];
            }
        }
        Bt[mni] = mn;
        b = max(b, Bt[mni] + t[N - 1 - i]);
    }
    
    cout << a << " " << b << "\n";
    
}   