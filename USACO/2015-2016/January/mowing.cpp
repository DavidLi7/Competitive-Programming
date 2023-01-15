#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 100005;

map<int, int> yindex;

struct event{
    int xindex;
    int day;
    int yi;
    int delta;
    event(int x, int dy, int y, int de){
        xindex = x;
        day = dy;
        yi = yindex[y];
        delta = de;
    }
};

bool eventcmp(const event& x, const event& y) {return x.xindex < y.xindex;}

struct line{
    int xindex;
    int day;
    int top;
    int bottom;
    line(int x, int d, int t, int b){
        xindex = x;
        day = d;
        top = yindex[max(t, b)];
        bottom = yindex[min(t, b)];
    }
};

bool linecmp(const line& x, const line& y) {return x.xindex < y.xindex;}

int N, T;
pair<int, int> points[MAXN];
vector<int> vert;

//xindex, day, of event, yindex of line, and sign
vector<event> events;
//xindex, day, top, bottom
vector<line> vertical;

struct node {
    int val;
    struct node* C[2];

    node() {
        val = 0;
        C[0] = C[1] = NULL;
    }

    node* getc(int c) {
        if (!C[c]) {
        C[c] = new node;
    }
    return C[c];
    }

    void add(int x, int v, int lo, int hi) {
        val += v;
        if (hi - lo == 1) {
            return;
        }
        int md = (lo + hi) / 2;
        if (x < md) {
            getc(0)->add(x, v, lo, md);
        } else {
           getc(1)->add(x, v, md, hi);
        }   
    }

    int query(int a, int b, int lo, int hi) {
        if (a <= lo && hi <= b) {
            return val;
        } else if (hi <= a || b <= lo) {
            return 0;
        }
        int md = (lo + hi) / 2;
        return (C[0] ? C[0]->query(a, b, lo, md) : 0) +
            (C[1] ? C[1]->query(a, b, md, hi) : 0);
  }
};

node BIT[MAXN + 5];

void bit_add(int idx, int y, int val) {
    for (; idx < MAXN; idx += idx & -idx) {
        BIT[idx].add(y, val, 0, MAXN);
    }
}

int bit_get(int y0, int y1, int idx) {
    int sum = 0;
    for (; idx; idx -= idx & -idx) {
        sum += BIT[idx].query(y0, y1, 0, MAXN);
    }
    return sum;
}

int main(){
    setIO("mowing");
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        cin >> points[i].first >> points[i].second;
        vert.push_back(points[i].second);
    }
    sort(vert.begin(), vert.end());
    for(int c = 0; c < vert.size(); c++){
        yindex[vert[c]] = c;
    }
    for(int i = 0; i < N -1 ; i++){
        pair<int, int> p0 = points[i], p1 = points[i + 1];
        if(p0 > p1)
            swap(p0, p1);
        if(p0.second == p1.second){
            events.push_back(event(p0.first + 1, i + 1, p0.second, 1));
            events.push_back(event(p1.first, i + 1, p1.second, -1));
        }
        else{
            vertical.push_back(line(p0.first, i + 1, p0.second, p1.second));
        }
    }
    sort(events.begin(), events.end(), eventcmp);
    sort(vertical.begin(), vertical.end(), linecmp);
    int ei = 0;
    int ans = 0;
    for(auto it: vertical){
        int x = it.xindex;
        for(;ei < events.size() && events[ei].xindex <= x; ei++){
            bit_add(events[ei].day, events[ei].yi, events[ei].delta);
        }
        int lo = it.bottom;
        int hi = it.top;
        int t1 = it.day - T;
        int t2 = it.day + T;
        if(t2 < MAXN){
            ans += bit_get(lo + 1, hi, MAXN - 1);
            ans -= bit_get(lo + 1, hi, t2);
        }
        if(t1 > 0){
            ans += bit_get(lo + 1, hi, t1);
        }
    }
    cout << ans;
}           