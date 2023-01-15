#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1e5 + 5;

int N;
long double x[MAXN], v[MAXN];
map<long double, map<int, set<int> > > m;

long double collisionTime(int i, int j){
    if(v[i] == v[j])
        return 1;
    long double t = (x[i] - x[j]) / (v[i] - v[j]);
    return t;
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    set<int> a;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> v[i];
        a.insert(i);
    }
    for(int i = 0; i < N - 1; i++){
        long double t = collisionTime(i, i + 1);
        // cout << i << " " << i + 1 << " " << t << "\n";
        if(t < (long double)0){
            m[-t][i].insert(i + 1);
            m[-t][i + 1].insert(i);
        }
    }
    long double key = 0;
    map<long double, map<int, set<int> > >::iterator it5 = m.upper_bound(key);
    if(it5 == m.end())
        key = -1;
    else
        key = (*it5).first;
    while(key != -1){
        for(auto it: m[key]){
            if(a.find(it.first) == a.end())
                continue;
            if(it.second.empty())
                continue;
            for(int x = *it.second.begin();;){
                if(a.find(x) == a.end())
                    it.second.erase(x);
                set<int>::iterator it2 = it.second.upper_bound(x);
                if(it2 == it.second.end())
                    break;
                x = *it2;
            }
            if(it.second.empty())
                continue;
            int left = -1;
            int right = -1;
            set<int>::iterator it2 = a.lower_bound(it.first);
            if(it2 != a.begin()){
                it2 = prev(it2);
                left = *it2;
            }
            set<int>::iterator it3 = a.upper_bound(*it.second.rbegin());
            if(it3 != a.end()){
                right = *it3;
            }
            if(left != -1 && right != -1){
                long double t = collisionTime(left, right);
                if(t < 0){
                    m[-t][left].insert(right);
                    m[-t][right].insert(left);
                }
            }
            // cout << it.first << " ";
            // for(int x: it.second)
            //     cout << x << " ";
            // cout << "\n";
            a.erase(it.first);
            for(int x: it.second)
                a.erase(x);
            
        }
        m.erase(key);
        map<long double, map<int, set<int> > >::iterator it = m.upper_bound(key);
        if(it == m.end())
            key = -1;
        else
            key = (*it).first;
    }
    cout << a.size() << "\n";
    for(int x: a)
        cout << x + 1 << " ";
    
    

        
    
    
}