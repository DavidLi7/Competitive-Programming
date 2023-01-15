#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 5005;

int T, N, K, t[MAXN], x[MAXN], y[MAXN];
vector<int> G, H;

int main(){

    cin >> T >> N >> K;
    for(int i = 0; i < N; i++){
        char c;
        cin >> c;
        t[i] = (c == 'G');
        if(t[i])
            G.push_back(i);
        else
            H.push_back(i);
        cin >> x[i];
        cin >> y[i];
    }


}