#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 2e5 + 5;

int N, P, d[MAXN];
pair<pair<int, int>, pair<int, int> > boards[MAXN];
map<int, int> m;//y value, dist - x2 - y2

int main(){
    setIO("boards");
    cin >> N >> P;
    for(int i = 0; i < P; i++){
        cin >> boards[2 * i].first.first >> boards[2 * i].first.second >> boards[2 * i + 1].first.first >> boards[2 * i + 1].first.second;
        boards[2 * i].second.first = -1;
        boards[2 * i + 1].second.first = 1;
        boards[2 * i].second.second = i;
        boards[2 * i + 1].second.second = i;
    }
    sort(boards, boards + 2 * P);
    m[-1] = 0;
    m[1e9 + 5] = -2e9;
    for(int i = 0; i < 2 * P; i++){
        if(boards[i].first.first > N)
            break;
        if(boards[i].second.first == -1){
            map<int, int>::iterator it = prev(m.upper_bound(boards[i].first.second));
            d[boards[i].second.second] = (*it).second + boards[i].first.first + boards[i].first.second;
        }
        else{
            int numtoinsert = d[boards[i].second.second] - boards[i].first.second - boards[i].first.first;
            map<int, int>::iterator it = prev(m.upper_bound(boards[i].first.second));
            if((*it).second <= numtoinsert)
                continue;
            m[boards[i].first.second] = numtoinsert;
            int key = boards[i].first.second;
            while(m[key] <= (*m.upper_bound(key)).second){
                m.erase(m.upper_bound(key));
            }
        }
    }
    map<int, int>::iterator it = prev(m.upper_bound(N));
    int dist = (*it).second + N + N;
    cout << dist;


}