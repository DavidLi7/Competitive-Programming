#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 105;

int N, T, W, g[MAXN][MAXN], curr[MAXN], mn[MAXN];
vector<map<int, int> > s;

void solve(){

    cin >> N >> W;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < W; j++){
            cin >> g[i][j];
        }
    }

    int ans = 0;
    for(int j = 0; j < W; j++){
        int mn = 1e9;
        for(int i = 0; i < N; i++){
            mn = min(mn, g[i][j]);
        }
        ans += 2 * mn;
        for(int i = 0; i < N; i++){
            g[i][j] -= mn;
        }
    }    

    //iniate start
    map<int, int> temp;
    for(int j = 0; j < W; j++){
        curr[j] = g[0][j];
        ans += curr[j];
        temp[j] = g[0][j];
    }
    s.push_back(temp);

    //initiate N
    for(int j = 0; j < W; j++){
        g[N][j] = g[N - 1][j];
    }

    //1. get rid of anything that doesn't overlap between i and i + 1
    //2. complete the overlap between i and i + 1
    //3. add the remaining stuff of i


    for(int i = 1; i < N; i++){
        for(int j = 0; j < W; j++){
            mn[j] = min(g[i][j], g[i + 1][j]);
        }

        //1. get rid of anything that doesn't overlap between i and i + 1.
        bool done = false;
        while(!done){
            done = true;
            map<int, int> t = s.back();
            s.pop_back();
            bool removeall = false;
            for(int j = 0; j < W; j++){
                if(curr[j] - mn[j] > t[j]){//NOT ENOUGH
                    removeall = true;
                    break;
                }
            }
            if(removeall){//get rid of this group
                for(int j = 0; j < W; j++){
                    ans += t[j];
                    curr[j] -= t[j];
                }
                done = false;
            }
            else{//edit this group
                for(int j = 0; j < W; j++){
                    if(curr[j] - mn[j] > 0){
                        ans += (curr[j] - mn[j]);
                        t[j] -= (curr[j] - mn[j]);
                        curr[j] = mn[j];
                    }
                }
                s.push_back(t);
            }
        }

        //2. complete the overlap between i and i + 1
        temp.clear();
        for(int j = 0; j < W; j++){
            temp[j] = 0;
            if(mn[j] > curr[j]){
                ans += (mn[j] - curr[j]);
                temp[j] = (mn[j] - curr[j]);
                curr[j] = mn[j];
            }
        }
        s.push_back(temp);

        //3. add the remaining stuff of i
        temp.clear();
        for(int j = 0; j < W; j++){
            ans += (g[i][j] - curr[j]);
            temp[j] = (g[i][j] - curr[j]);
            curr[j] = g[i][j];
        }
        s.push_back(temp);
    }

    for(int j = 0; j < W; j++){
        ans += curr[j];
    }

    cout << ans;
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }

    
    
    
}