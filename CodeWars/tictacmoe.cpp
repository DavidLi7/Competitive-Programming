#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

string s[3], t;
int p3[10];
bool vis[10], vict2;
map<char, set<vector<int> > > m;

bool dfs(int moves, char c, int x, int y){
    // cout << x << " " << y << " " << s[x][y] << "!\n";
    s[x][y] = c;
    // cout << x << " " << y << " " << s[x][y] << "!\n";
    bool cont = true;
    // cout << x << " " << y << " " << s[x][0] << " " << s[x][1] << " " << s[x][2] << '\n';
    if(s[x][0] == c && s[x][1] == c && s[x][2] == c){
        vector<int> ans;
        ans.push_back(3 * x);
        ans.push_back(3 * x + 1);
        ans.push_back(3 * x + 2);
        m[c].insert(ans);
    }
    if(s[0][y] == c && s[1][y] == c && s[2][y] == c){
        vector<int> ans;
        ans.push_back(y);
        ans.push_back(3 + y);
        ans.push_back(6 + y);
        m[c].insert(ans);
    }
    if(s[0][0] == c && s[1][1] == c && s[2][2] == c){
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(4);
        ans.push_back(8);
        m[c].insert(ans);
    }
    if(s[2][0] == c && s[1][1] == c && s[0][2] == c){
        vector<int> ans;
        ans.push_back(2);
        ans.push_back(4);
        ans.push_back(6);
        m[c].insert(ans);
    }
    if(cont && moves == 1){
        bool temp = false;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(s[i][j] == '.'){
                    if(c == 'O')
                        temp |= dfs(moves + 1, 'X', i, j);
                    else
                        temp |= dfs(moves + 1, 'O', i, j);
                }
            }
        }
        vict2 |= temp;
    }
    s[x][y] = '.';
    return !cont;
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    for(int i = 0; i < 3; i++){
        cin >> s[i];
    }
    vict2 = true;
    cin >> t;
    int counter = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            // cout << i << " " << j << " " << s[i][j] << "\n";
            if(s[i][j] == '.'){
                if(t[0] == 'X')
                    dfs(1, 'X', i, j);
                else
                    dfs(1, 'O', i, j);
                counter--;
            }
            
        }
    }
    char other;
    if(t[0] == 'X')
        other = 'O';
    else
        other = 'X';
    if(m[t[0]].size() != 0){
        cout << t[0] << " WILL WIN IN " << 1 << " MOVES\n";
        for(auto it: m[t[0]]){
            cout << it[0] + 1 << " " << it[1] + 1 << " " << it[2] + 1 << "\n";
        }
    }
    else if(m[other].size() != 0 && vict2){
        cout << other << " WILL WIN IN " << 2 << " MOVES\n";
        for(auto it: m[other]){
            cout << it[0] + 1 << " " << it[1] + 1 << " " << it[2] + 1 << "\n";
        }
    }
    else if(m[other].size()){
        cout << "NOT ENOUGH INFORMATION";
    }
    else if(counter >= 7){
        cout << "GAME WILL BE A TIE";
    }
    else{
        cout << "NOT ENOUGH INFORMATION";
    }


}