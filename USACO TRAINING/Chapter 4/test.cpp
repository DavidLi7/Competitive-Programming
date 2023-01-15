#include <iostream>
#include <set>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct state{
    set<int> vis;
    state(set<int> t) : vis(t) {}
};

const int MAXN =0;

int main(){
    //setIO("");
    set<int> q;
    q.insert(1);
    q.insert(2);
    state x(q);
    x.vis.insert(3);
    cout << q.size() << " " << x.vis.size();
}