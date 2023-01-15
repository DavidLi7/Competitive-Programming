#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct peak{
    int x, y;
};

bool cmp(const peak& p1, const peak& p2){
    if((p1.x - p1.y) == (p2.x - p2.y)){
        return (p1.x + p1.y) > (p2.x + p2.y);
    }
    return (p1.x - p1.y) < (p2.x - p2.y);
}

const int MAXN = 1e5;

int N;
peak peaks[MAXN];

int main(){
    setIO("mountains");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> peaks[i].x >> peaks[i].y;
    }
    sort(peaks, peaks + N, cmp);
    int mx = -1;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(peaks[i].x + peaks[i].y > mx){
            ans++;
            mx = peaks[i].x + peaks[i].y;
        }
    }
    cout << ans;

}