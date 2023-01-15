#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 55;

int T, N, M, rel[MAXN][MAXN], in[MAXN];
//1 = inside, 2 = outside
vector<int> c[MAXN], adj[MAXN];

bool solve(){

    for(int i = 0; i < N; i++){
        int s = 0;
        while(s < M && find(c[s].begin(), c[s].end(), i) == c[s].end())
                s++;
        int e = M - 1;
        while(e >= 0 && find(c[e].begin(), c[e].end(), i) == c[e].end())
            e--;
        for(; s < e; s++)
            if(find(c[s].begin(), c[s].end(), i) == c[s].end())
                return false;
    }

    for(int i = 0; i < M; i++){
        vector<int> s;
        set<int> seen;
        set<int> popped;
        int prev = -1;
        for(int x: c[i]){
            if(seen.find(x) == seen.end()){
                s.push_back(x);
                seen.insert(x);
                for(int y: popped){
                    if(rel[x][y] == 1)
                        return false;
                    rel[x][y] = 2;
                    rel[y][x] = 2;
                }
                if(prev != -1){
                    adj[prev].push_back(x);
                }
                prev = x;
            }
            else{
                if(s.back() != x)
                    return false;
                s.pop_back();
                seen.erase(x);
                popped.insert(x);
                for(int y: seen){
                    if(rel[x][y] == 2)
                        return false;
                    rel[x][y] = 1;
                    rel[y][x] = 1;
                }
            }
        }
    }

    vector<int> curr;
    int s = 0;
    for(int i = 0; i < N; i++){
        if(in[i] == 0)
            curr.push_back(i);
    }
    while(curr.size()){
        int temp = curr.back();
        curr.pop_back();
        s++;
        for(int x: adj[temp]){
            in[x]--;
            if(!in[x])
                curr.push_back(x);
        }
    }
    return s == N;
    
}

int main(){

    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < M; i++){
            int s;
            cin >> s;
            c[i].resize(s);
            for(int j = 0; j < s; j++){
                cin >> c[i][j];
                c[i][j]--;
            }
        }
        for(int i = 0; i < N; i++){
            adj[i].clear();
            in[i] = 0;
        }
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}