#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int> > m;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        m.push_back(make_pair(b, a));//(ending time, starting time)
    }
    sort(m.begin(), m.end());//sorts by ending time
    int ans = 0;
    int curr = 0;
    for(int i = 0; i < N; i++){
        if(m[i].second >= curr){
            curr = m[i].first;
            ans++;
        }
    }
    cout << ans << "\n";
}