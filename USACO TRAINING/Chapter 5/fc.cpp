/*
ID: divadxl1
LANG: C++
TASK: fc
*/
#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>

#define ll long long
#define ld long double
#define f first
#define s second

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 10000;

int N, k;
pair<ld, ld> points[MAXN], hull[MAXN];

ld cross(pair<ld,ld> O, pair<ld,ld> A, pair<ld,ld> B){
    return (A.f - O.f) * (B.s - O.s) - (A.s- O.s) * (B.f - O.f);
}

ld dist(pair<ld,ld> A, pair<ld,ld> B){
    return sqrt((A.f - B.f) * (A.f - B.f) + (A.s - B.s) * (A.s - B.s));
}

int main(){
    setIO("fc");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> points[i].f >> points[i].s;
    }
    sort(points, points + N);
    for(int i = 0; i < N; i++){
        while(k >= 2 && cross(hull[k - 2], hull[k - 1], points[i]) <= 0)
            k--;
        hull[k++] = points[i];
    }
    for(int i = N - 1, t = k + 1; i > 0; --i){
        while(k >= t && cross(hull[k - 2], hull[k - 1], points[i - 1]) <= 0)
            k--;
        hull[k++] = points[i - 1];
    }
    ld ans = 0;
    for(int i = 0; i < k; i++){
        //cout << dist(hull[i], hull[(i + 1) % k]) << "\n";
        ans += dist(hull[i], hull[(i + 1) % k]);
    }
    cout << fixed << setprecision(2) << ans << "\n";

}