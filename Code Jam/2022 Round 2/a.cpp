#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 105;

int N, T, K;

void solve(){
    cin >> N >> K;
    int base = N - 1;
    if(K < base || K >= N * N || (K - base) % 2 == 1){
        cout << "IMPOSSIBLE\n";
        return;
    }
    K -= (N / 2);
    K -= (N / 2);
    int s = 1 + N / 2;
    int ls = 1;
    int state = 1;
    vector<pair<int, int> > ans;
    for(int l = N; l >= 3; l -= 2){
        //cout << ls << " " << s << " " << state << " " << K << "\n";
        if(K >= ls + (l * l) - (l - 2) * (l - 2) - s + (l - 2) / 2 - 1){
            K -= (ls + (l * l) - (l - 2) * (l - 2) - s + (l - 2) / 2 - 1);
            ls += (l * l) - (l - 2) * (l - 2);
            state = 1;
            s = ls + (state - 1) * ((l - 2) - 1) + (l - 2) / 2;
            
            //cout << "uno";
        }
        else if(K >= 3 * (l - 1) && state <= 1){
            int st = s + 3 * (l - 1);
            ls += (l * l) - (l - 2) * (l - 2);
            state = state + 3;
            int en = ls + (state - 1) * ((l - 2) - 1) + (l - 2) / 2;
            ans.push_back(make_pair(st, en));
            s = en;
            
            K -= 3 * (l - 1);
            //cout << "dos";
        }
        else if(K >= 2 * (l - 1) && state <= 2){
            int st = s + 2 * (l - 1);
            ls += (l * l) - (l - 2) * (l - 2);
            state = state + 2;
            int en = ls + (state - 1) * ((l - 2) - 1) + (l - 2) / 2;
            ans.push_back(make_pair(st, en));
            s = en;
            
            K -= 2 * (l - 1);
            //cout << "tres";
        }
        else if(K >= l - 1 && state <= 3){
            int st = s + l - 1;
            ls += (l * l) - (l - 2) * (l - 2);
            state = state + 1;
            int en = ls + (state - 1) * ((l - 2) - 1) + (l - 2) / 2;
            ans.push_back(make_pair(st, en));
            s = en;
            
            K -= (l - 1);
            //cout <<" quadro";
        }
        else{
            int st = s;
            ls += (l * l) - (l - 2) * (l - 2);
            int en = ls + (state - 1) * ((l - 2) - 1) + (l - 2) / 2;
            ans.push_back(make_pair(st, en));
            s = en;
            state = state;
            //cout << "cinco";
        }
    }
    if (K != 0){
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << ans.size() << "\n";
    for(auto it: ans){
        cout << it.first << " " << it.second << "\n";
    }
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> T;
    
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    
    
    
}