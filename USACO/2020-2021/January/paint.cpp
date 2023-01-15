#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXA = 27;

int N, Q, pre[MAXN], suff[MAXN], mn[MAXA]; 
string s;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N >> Q >> s;
    s = " " + s;
    for(int i = 0; i < MAXA; i++)
        mn[i] = -1;
    for(int i = 1; i <= N; i++){
        int curr = s[i] - 'A';
        for(int j = 0; j < MAXA; j++)
            mn[j] = min(mn[j], curr);
        pre[i] = pre[i - 1] + (mn[curr] < curr);
        mn[curr] = curr;
    }
    for(int i = 0; i < MAXA; i++)
        mn[i] = -1;
    for(int i = N; i >= 1; i--){
        int curr = s[i] - 'A';
        for(int j = 0; j < MAXA; j++)
            mn[j] = min(mn[j], curr);
        suff[i] = suff[i + 1] + (mn[curr] < curr);
        mn[curr] = curr;
    }
    while(Q--){
        int a, b;
        cin >> a >> b;
        cout << pre[a - 1] + suff[b + 1] << "\n";
    }
}