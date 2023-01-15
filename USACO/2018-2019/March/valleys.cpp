#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 755;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

struct cell{
    int i, j, h, index;
};

bool cmp(const cell& a, const cell& b){
    return a.h < b.h;
}

int grid[MAXN][MAXN], N, C, par[MAXN * MAXN], sz[MAXN * MAXN], V[MAXN * MAXN], E[MAXN * MAXN], F[MAXN * MAXN];
cell cells[MAXN * MAXN];

int find(int p){
    while(p != par[p])
        p = par[p];
    return p;
}

void merge(int p, int q, int addE, int addF){
    int rp = find(p);
    int rq = find(q);
    if(rp == rq)
        return;
    if(sz[rp] > sz[rq])
        swap(rp, rq);
    par[rp] = rq;
    sz[rq] += sz[rp];
    V[rq] += V[rp];
    E[rq] += E[rp] + addE;
    F[rq] += F[rp] + addF;
}

int main(){
    setIO("valleys");
    cin >> N;
    C = N * N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int index = N * i + j;
            cells[index].i = i;
            cells[index].j = j;
            cin >> cells[index].h;
            grid[i][j] = cells[index].h;
            cells[index].index = index;
            sz[index] = 1;
            par[index] = index;
            V[index] = 1;
        }
    }
    sort(cells, cells + C, cmp);
    long long ans = 0;
    for(int i = 0; i < C; i++){
        map<int, vector<int> > parents;
        for(int j = 0; j < 4; j++){
            int newi = cells[i].i + di[j];
            int newj = cells[i].j + dj[j];
            if(newi >= 0 && newi < N && newj >= 0 && newj < N && cells[i].h > grid[newi][newj]){
                int idx = N * newi + newj;
                //merge(idx, cells[i].index);
                parents[find(idx)].push_back(j);
            }
        }
        for(auto it: parents){
            int addF = 0;
            for(int j = 0; j < it.second.size(); j++){
                if((it.second[j] + 1) % 4 == it.second[(j + 1) % it.second.size()]){
                    int newi = cells[i].i + di[it.second[j]] + di[it.second[(j + 1) % it.second.size()]];
                    int newj = cells[i].j + dj[it.second[j]] + dj[it.second[(j + 1) % it.second.size()]];
                    if(find(N * newi + newj) == it.first)
                        addF++;
                }
            }
            merge(it.first, cells[i].index, it.second.size(), addF);
        }
        int p = find(cells[i].index);
        if(E[p] - V[p] + 2 - F[p] == 1){
            ans += 1LL * sz[p];
            //cout << "ok ";
        }
        //cout << E[p] << " " << V[p] << " " << E[p] << " " << sz[p] << "\n";
    }
    cout << ans;
}