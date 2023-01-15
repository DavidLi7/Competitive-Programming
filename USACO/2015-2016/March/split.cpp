#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct cow{
    long long x, y;
};

bool sortbyx(const cow& c1, const cow& c2){
    if(c1.x == c2.x){
        return c1.y < c2.y;
    }
    return c1.x < c2.x;
}

bool sortbyy(const cow& c1, const cow& c2){
    if(c1.y == c2.y){
        return c1.x > c2.x;
    }
    return c1.y < c2.y;
}

const int MAXN = 50001;

int N;
long long mnx, mxx, mny, mxy, mx[MAXN], mn[MAXN], maxarea, currmx, currmn, ans;
cow cows[MAXN];

int main(){
    setIO("split");
    cin >> N;
    mnx = 1e10;
    mny = 1e10;
    for(int i = 0; i < N; i++){
        cin >> cows[i].x >> cows[i].y;
        mnx = min(mnx, cows[i].x);
        mny = min(mny, cows[i].y);
        mxx = max(mxx, cows[i].x);
        mxy = max(mxy, cows[i].y);
    }
    maxarea = (mxx - mnx) * (mxy - mny);

    sort(cows, cows + N, sortbyx);
    mn[N] = 1e10;
    currmn = 1e10;
    for(int i = N - 1; i >= 0; i--){
        mx[i] = max(mx[i + 1], cows[i].y);
        mn[i] = min(mn[i + 1], cows[i].y);
    }
    mx[N] = mx[N - 1];
    mn[N] = mn[N - 1];
    ans = maxarea;
    for(int i = 0; i < N; i++){
        currmx = max(currmx, cows[i].y);
        currmn = min(currmn, cows[i].y);
        ans = min(ans, (currmx - currmn) * (cows[i].x - cows[0].x) + (mx[i + 1] - mn[i + 1]) * (mxx - cows[i + 1].x));
        //cout << (currmx - currmn) * (cows[i].x - cows[0].x) + (mx[i + 1] - mn[i + 1]) * (mxx - cows[i + 1].x) << "\n";
    }

    sort(cows, cows + N, sortbyy);
    mn[N] = 1e10;
    currmn = 1e10;
    for(int i = N - 1; i >= 0; i--){
        mx[i] = max(mx[i + 1], cows[i].x);
        mn[i] = min(mn[i + 1], cows[i].x);
    }
    mx[N] = mx[N - 1];
    mn[N] = mn[N - 1];
    currmx = 0;
    for(int i = 0; i < N; i++){
        currmx = max(currmx, cows[i].x);
        currmn = min(currmn, cows[i].x);
        ans = min(ans, (currmx - currmn) * (cows[i].y - cows[0].y) + (mx[i + 1] - mn[i + 1]) * (mxy - cows[i + 1].y));
        //cout << (currmx - currmn) * (cows[i].x - cows[0].x) + (mx[i + 1] - mn[i + 1]) * (mxx - cows[i + 1].x) << "\n";
    }


    cout << maxarea - ans << "\n";



}