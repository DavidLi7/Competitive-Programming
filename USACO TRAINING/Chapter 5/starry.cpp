/*
ID: divadxl1
LANG: C++
TASK: starry
*/
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

struct cluster{
    int sz;
    vector<pair<int, int> > points;
    vector<int> xs;
    vector<int> ys;
    void ready(){
        sort(points.begin(), points.end());
        int curr = points[0].first;
        int l = 1;
        for(int i = 1; i < sz; i++){
            if(points[i].first != curr){
                xs.push_back(l);
                curr = points[i].first;
                l = 0;
            }
            l++;
            swap(points[i].first, points[i].second);
        }
        swap(points[0].first, points[0].second);
        xs.push_back(l);
        for(int i = 0; i < xs.size() / 2; i++){
            if(xs[i] > xs[xs.size() - 1 - i]){
                reverse(xs.begin(), xs.end());
                break;
            }
        }
        sort(points.begin(), points.end());
        curr = points[0].first;
        l = 1;
        for(int i = 1; i < sz; i++){
            if(points[i].first != curr){
                ys.push_back(l);
                curr = points[i].first;
                l = 0;
            }
            l++;
            swap(points[i].first, points[i].second);
        }
        swap(points[0].first, points[0].second);
        ys.push_back(l);
        for(int i = 0; i < ys.size() / 2; i++){
            if(ys[i] > ys[ys.size() - 1 - i]){
                reverse(ys.begin(), ys.end());
                break;
            }
        }
        if(xs.size() > ys.size()){
            swap(xs, ys);
        }
        if(xs.size() == ys.size()){
            for(int i = 0; i < xs.size(); i++){
                if(xs[i] < ys[i])
                    break;
                if(xs[i] > ys[i]){
                    swap(xs, ys);
                    break;
                }
            }
        }
    }
};

bool cmp(const cluster& a, const cluster& b){
    if(a.sz != b.sz){
        return a.sz < b.sz;
    }
    if(a.xs.size() != b.xs.size()){
        return a.xs.size() < b.xs.size();
    }
    //if(b.ys.size() != b.ys.size()){
        return a.ys.size() < b.ys.size();
    //}
}

bool eq(const cluster& a, const cluster& b){
    for(int i = 0; i < a.xs.size(); i++){
        if(a.xs[i] != b.xs[i])
            return false;
    }
    for(int i = 0; i < a.ys.size(); i++){
        if(a.ys[i] != b.ys[i])
            return false;
    }
    return true;
}

const int MAXN = 100;

int W, H, k, comp[501], ans[MAXN][MAXN];
bool grid[MAXN][MAXN];
cluster c[501];
map<int, char> m;

void dfs(int i, int j){
    if(i == -1 || i == H || j == -1 || j == W || !grid[i][j]){
        return;
    }
    grid[i][j] = false;
    c[k].sz++;
    c[k].points.push_back(make_pair(i, j));
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i - 1, j - 1);
    dfs(i - 1, j + 1);
    dfs(i + 1, j - 1);
    dfs(i + 1, j + 1);
}

int main(){
    setIO("starry");
    cin >> W >> H;
    for(int i = 0; i < H; i++){
        string s;
        cin >> s;
        for(int j = 0; j < W; j++){
            grid[i][j] = (s[j] == '1');
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(grid[i][j]){
                dfs(i, j);
                c[k].ready();
                k++;
            }
            ans[i][j] = 0;
        }
    }
    sort(c, c + k, cmp);
    int curr = 1;
    for(int i = 0; i < k; i++){
        int j = i + 1;
        while(j < k && c[j].sz == c[i].sz && c[j].xs.size() == c[i].xs.size() && c[j].ys.size() == c[i].ys.size()){
            j++;
        }
        for(int l = i; l < j; l++) if(comp[l] == 0){
            comp[l] = curr;
            for(int p = l + 1; p < j; p++) if(comp[p] == 0){
                if(eq(c[l], c[p])){
                    comp[p] = curr;
                }
            }
            curr++;
        }
        i = j - 1;
    }
    for(int i = 0; i < k; i++){
        for(auto it: c[i].points){
            ans[it.first][it.second] = comp[i];
        }
    }
    curr = 0;
    m[0] = '0';
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(m.find(ans[i][j]) == m.end()){
                m[ans[i][j]] = 'a' + curr;
                curr++;
            }
            cout << m[ans[i][j]];
        }
        cout << "\n";
    }

}