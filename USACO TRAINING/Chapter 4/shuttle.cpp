/*
ID: divadxl1
LANG: C++
TASK: shuttle
*/
#include <iostream>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 25;



int main(){
    setIO("shuttle");
    int N;
    cin >> N;
    set<int> b;
    set<int> w;
    int empty = N + 1;
    for(int i = 1; i <= N; i++){
        w.insert(i);
    }
    for(int j = N + 2; j <= 2 * N + 1; j++){
        b.insert(j);
    }
    cout << N;
    w.erase(N);
    w.insert(N + 1);
    empty = N;
    bool B = true;
    int m = 2;
    int c = 1;
    while(m != 1){
        m = 1;
        if(B){
            int t = -1;
            for(set<int>::iterator it = b.upper_bound(empty); it != b.end(); it = b.upper_bound(t)){
                t = *it;
                if(m != 1 && empty == t - 1 && b.find(t - 2) != b.end())
                    break;
                if(c % 20 == 0){
                    cout << "\n" << t;
                }
                else{
                    cout << " " << t;
                }
                b.erase(t);
                b.insert(empty);
                empty = t;
                m++;
                c++;
            }
        }
        else{
            int t = -1;
            for(set<int>::iterator it = w.lower_bound(empty); it != w.begin(); it = w.lower_bound(t)){
                it = prev(it);
                t = *it;
                if(m != 1 && empty == t + 1 && w.find(t + 2) != w.end())
                    break;
                if(c % 20 == 0){
                    cout << "\n" << t;
                }
                else{
                    cout << " " << t;
                }
                w.erase(t);
                w.insert(empty);
                empty = t;
                m++;
                c++;
            }
        }
        B = !B;
    }
    cout << "\n";
}