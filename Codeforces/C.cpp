#include <iostream>
#include <set>

using namespace std;

const int MAXN = 55;

int T, N;
char grid[MAXN][MAXN];

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> N;
        for(int j = 0; j < N; j++)
            cin >> grid[j];
        int mn = 1e9;
        int amt = 0;
        set<pair<int, int> > ifone;
        for(int j = 0; j < N; j++){
            int xcount = 0;
            int ocount = 0;
            for(int k = 0; k < N; k++){
                if(grid[j][k] == 'X')
                    xcount++;
                if(grid[j][k] == 'O')
                    ocount++;
            }
            if(ocount == 0 && N - xcount == mn)
                amt++;
            else if(ocount == 0 && N - xcount < mn){
                mn = N - xcount;
                amt = 1;
            }
            if(ocount == 0 && N - xcount == 1){
                for(int k = 0; k < N; k++){
                    if(grid[j][k] == '.')
                        ifone.insert(make_pair(j, k));
                }
            }
            xcount = 0;
            ocount = 0;
            for(int k = 0; k < N; k++){
                if(grid[k][j] == 'X')
                    xcount++;
                if(grid[k][j] == 'O')
                    ocount++;
            }
            if(ocount == 0 && N - xcount == mn)
                amt++;
            else if(ocount == 0 && N - xcount < mn){
                mn = N - xcount;
                amt = 1;
            }
            if(ocount == 0 && N - xcount == 1){
                for(int k = 0; k < N; k++){
                    if(grid[k][j] == '.')
                        ifone.insert(make_pair(k, j));
                }
            }
        }
        cout << "Case #" << i << ": ";
        if(amt == 0)
            cout << "Impossible";
        else if(mn == 1)
            cout << mn << " " << ifone.size();
        else
            cout << mn << " " << amt;
        if(i != T)
            cout << "\n";
    }
    
    
}