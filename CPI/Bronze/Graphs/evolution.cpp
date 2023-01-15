#include <iostream>
#include <vector>
#include <string>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 26;

int N, K;
vector<string> ind[MAXN], all;

bool crosses(int a, int b){
    int A = 0, B = 0, AB = 0;
    for(int i = 0; i < N; i++){
        bool has_a = false, has_b = false;
        for(string x: ind[i]){
            if(x == all[a])
                has_a = true;
            if(x == all[b])
                has_b = true;
        }
        if(has_a && has_b)
            AB++;
        else if(has_a)
            A++;
        else if(has_b)
            B++;
    }
    return A > 0 && B > 0 && AB > 0;
}

int main(){

    setIO("evolution");

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> K;
        ind[i].resize(K);
        for(int j = 0; j < K; j++){
            cin >> ind[i][j];
            bool alreadyexists = false;
            for(string x: all)
                alreadyexists |= (ind[i][j] == x);
            if(!alreadyexists)
                all.push_back(ind[i][j]);
        }
    }
    
    bool ok = true;
    for(int i = 0; ok && i < all.size(); i++)
        for(int j = i + 1; ok && j < all.size(); j++)
            if(crosses(i, j))
                ok = false;

    if(ok)
        cout << "yes\n";
    else
        cout << "no\n";
}