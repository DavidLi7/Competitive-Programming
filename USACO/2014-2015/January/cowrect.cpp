#include <iostream>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 505;
const int MAXV = 1003;

int N, hpre[MAXV][MAXV], gpre[MAXV][MAXV];
set<int> yvals, xvals;

int main(){
    setIO("cowrect");
    cin >> N;
    for(int i = 0; i < N; i++){
        int x, y;
        char c;
        cin >> x >> y >> c;
        x++; y++;
        if(c == 'H'){
            hpre[x][y]++;
            yvals.insert(y);
        }
        else
            gpre[x][y]++;
        xvals.insert(x);
    }
    for(int i = 1; i < MAXV; i++){
        for(int j = 1; j < MAXV; j++){
            hpre[i][j] += hpre[i][j - 1];
            gpre[i][j] += gpre[i][j - 1];
        }
    }
    int cows = 0;
    int area = 0;
    for(int y1: yvals){
        for(int y2: yvals) if(y1 <= y2){
            int currcow = 0;
            int recg = 0;
            for(int x: xvals){
                int hc = hpre[x][y2] - hpre[x][y1 - 1];
                int gc = gpre[x][y2] - gpre[x][y1 - 1];
                if(gc != 0){
                    currcow = 0;
                    recg = x + 1;
                    continue;
                }
                if(currcow == 0)
                    recg = x;
                currcow += hc;
                
                if((currcow > cows) || (currcow == cows && (x - recg) * (y2 - y1) < area)){
                    cows = currcow;
                    area = (x - recg) * (y2 - y1);
                    // cout << y1 << " " << y2 << " " << currcow << " " << recg << " " << x << "\n";
                }
            }
        }
    }
    cout << cows << "\n" << area;

}

//500 * 500 * 500 = 125,000,000