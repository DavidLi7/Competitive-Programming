#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXK = 20;
const int MAXN = 1e5 + 5;

int N, K, dist[1 << 20];

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> K;
    for(int i = 0; i < (1 << K); i++){
        dist[i] = -1;
    }
    priority_queue<pair<int, int> > PQ;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        int val = 0;
        for(int j = 0; j < K; j++){
            if(s[j] == '1')
                val += (1 << j);
        }
        dist[val] = K;
        PQ.push(make_pair(K, val));
    }
    int ans = -1;
    int d = 1e9;
    while(!PQ.empty()){
        pair<int, int> temp = PQ.top();
        PQ.pop();
        dist[temp.second] = temp.first;
        if(temp.first < d){
            d = temp.first;
            ans = temp.second;
        }
        for(int j = 0; j < K; j++){
            if((1 << j) & (temp.second)){
                if(dist[temp.second - (1 << j)] == -1){
                    PQ.push(make_pair(temp.first - 1, temp.second - (1 << j)));
                    dist[temp.second - (1 << j)] = temp.first - 1;
                }
            }
            else{
                if(dist[temp.second + (1 << j)] == -1){
                    PQ.push(make_pair(temp.first - 1, temp.second + (1 << j)));
                    dist[temp.second + (1 << j)] = temp.first - 1;
                }
            }
        }
    }
    for(int i = 0; i < K; i++){
        if((1 << i) & (ans))
            cout << "1";
        else
            cout << "0";
    }
    cout << "\n";
        
    
    
}