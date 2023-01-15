#include <iostream>
#include <algorithm>

using namespace std;


const int MAXN = 101;

int N;
pair<int, int> minions[MAXN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> minions[i].first >> minions[i].second;
    }
    sort(minions, minions + N);
    int end = minions[0].second;
    int ans = 0;
    for(int i = 1; i < N; i++){
        if(minions[i].first > end){
            ans++;
            end = minions[i].second;
        }
        else{
            end = min(end, minions[i].second);
        }
    }
    cout << ans + 1;


}
//--------
//   ------------
//    ---