#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

int N, xl, yl, xb, yb, x[MAXN], y[MAXN];
map<int, vector<int> >mx, my;
set<int> visx, visy;

int main(){
    setIO("lasers");
    cin >> N >> xl >> yl >> xb >> yb;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
        mx[x[i]].push_back(y[i]);
        my[y[i]].push_back(x[i]);
    }
    priority_queue<pair<int, pair<int, int> > > PQ;
    PQ.push(make_pair(0, make_pair(xl, 0)));
    PQ.push(make_pair(0, make_pair(yl, 1)));
    int ans = -1;
    while(!PQ.empty()){
        pair<int, pair<int, int> > temp = PQ.top();
        PQ.pop();
        if(temp.second.second == 0){
            if(temp.second.first == xb){
                ans = temp.first;
                break;
            }
            if(visx.find(temp.second.first) != visx.end())
                continue;
            visx.insert(temp.second.first);
            for(int t: mx[temp.second.first]){
                if(visy.find(t) == visy.end()){
                    PQ.push(make_pair(temp.first - 1, make_pair(t, 1)));
                }
            }
        }
        else{
            if(temp.second.first == yb){
                ans = temp.first;
                break;
            }
            if(visy.find(temp.second.first) != visy.end())
                continue;
            visy.insert(temp.second.first);
            for(int t: my[temp.second.first]){
                if(visx.find(t) == visx.end()){
                    PQ.push(make_pair(temp.first - 1, make_pair(t, 0)));
                }
            }
        }
    }
    cout << -ans;
}