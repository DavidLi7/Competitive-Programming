#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

const int MAXN = 1e5;
const int MOD = 1e9 + 7;
const int MAXX = 1e9;
 
void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int N, K, a[MAXN], mn[MAXN], t[4 * MAXN], lazy[4 * MAXN];
bool fix[MAXN], used[MAXN];

void push(int v){
	t[2 * v] = max(lazy[v], t[2 * v]);
	t[2 * v + 1] = max(lazy[v], t[2 * v + 1]);
	lazy[2 * v] = max(lazy[v], lazy[2 * v]);
	lazy[2 * v + 1] = max(lazy[v], lazy[2 * v + 1]);
	lazy[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int val){
	if(l > r)
		return;
	if(l == tl && r == tr){
		t[v] = max(val, t[v]);
		lazy[v] = max(lazy[v], val);
	}
	else{
		push(v);
		int tm = (tl + tr) / 2;
		upd(2 * v, tl, tm, l, min(tm, r), val);
		upd(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
		t[v] = max(t[2 * v], t[2 * v + 1]);
	}
}
 
int get(int v, int tl, int tr, int l, int r){
	if(l > r)
		return 0;
	if(l == tl && r == tr)
		return t[v];
	push(v);
	int tm = (tl + tr) / 2;
	return max(get(2 * v, tl, tm, l, min(r, tm)),
		get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
} 

long long solve(int d, long long y){
	
	vector<long long>pow(K + 1);
	long long x = MAXX - y;
	pow[0] = 1;
	for(int i = 1; i <= K; i++){
		pow[i] = pow[i - 1] * x;
		pow[i] %= MOD;
	}
	vector<long long> dp(d + 2);
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= d + 1; i++){
		dp[i] = 0;
		long long temp = dp[i - 1];
		if(i - 1 - K >= 0)
			temp -= (dp[i - 1 - K] * pow[K - 1]) % MOD;
		temp %= MOD;
		dp[i] = (temp * x) % MOD + dp[i - 1];
		dp[i] %= MOD;
		if(dp[i] < 0)
			dp[i] += MOD;
	}
	return dp[d + 1];
}

int main()
{
    setIO("tracking2");
	cin >> N >> K;
	for(int i = 0; i < N - K + 1; i++){
		cin >> a[i];//[i, i + K - 1]
		upd(1, 0, N - 1, i, i + K - 1, a[i]);
	}
	for(int i = 0; i < N - K + 1; i++){
		if(i != 0 && a[i] > a[i - 1]){
			fix[i - 1] = true;
			mn[i - 1] = a[i - 1];
			used[i - 1] = true;
		}
		if(i != 0 && a[i] < a[i - 1]){
			fix[i + K - 1] = true;
			mn[i + K - 1] = a[i];
			used[i] = true;
		}
	}
	long long ans = 1;
	//int ki = 0;
	for(int i = 0; i < N; i++) if(!fix[i]){
		int j = i;
		while(j < N && !fix[j])
			j++;
		j--;
		int v = get(1, 0, N - 1, i, j);
		int dist = j - i + 1;
		ans *= solve(dist, 1LL * v);
		ans %= MOD;
		i = j;
	}
	cout << ans;
	
}