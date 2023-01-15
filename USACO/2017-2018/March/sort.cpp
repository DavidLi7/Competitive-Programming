#include <iostream>
#include <set>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e5;

int N, nums[MAXN], work, mx[MAXN], mn[MAXN];

void qsort(int a, int b){
    //cout << a << " " << b << "\n";
    if(a == b)
        return;
    vector<int>part;
    do{
        work += b - a + 1;
        for(int i = a; i < b; i++){
            if(nums[i] > nums[i + 1]){
                swap(nums[i], nums[i + 1]);
            }
        }
        mx[a] = nums[a];
        for(int i = a + 1; i <= b; i++){
            mx[i] = max(mx[i - 1], nums[i]);
        }
        mn[b] = nums[b];
        for(int i = b - 1; i >= a; i--){
            mn[i] = min(mn[i + 1], nums[i]);
        }
        for(int i = a; i < b; i++){
            if(mn[i + 1] >= mx[i])
                part.push_back(i);
        }
        
    }while(part.size() == 0);
    int prev = a;
    for(int v: part){
        //cout << prev << " " << v << "\n";
        qsort(prev, v);
        prev = v + 1;
    }
    //cout << prev << " " << b << "\n";
    qsort(prev, b);
}

int main(){
    setIO("sort");
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    qsort(0, N - 1);
    cout << work;
}