#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}


int N, K, A1, A2, B1, B2, res[101];//res stores the result

int nex(int x) {
	if (A1 <= x && x <= A2)//simulate step 1
        x = A1 + A2 - x;
	if (B1 <= x && x <= B2)//simulate step 2
        x = B1 + B2 - x;
	return x;
}

int main() {
	setIO("swap");
	
	//read in input
	cin >> N >> K >> A1 >> A2 >> B1 >> B2;

	//solve for each cow
	for (int i = 1; i <= N; ++i) {
		//p = how many turns so far?
		//cur = where are we after p turns?
		int p = 1, cur = nex(i);
		while (cur != i) { //keep going until we have found a cycle
			p++;
			cur = nex(cur);//simulating another turn
		}
		int k = K % p; //reduce k
		for (int j = 0; j < k; ++j)
            cur = nex(cur);
		res[cur] = i; // position of cow i after k steps is cur
	}
	//print answer
	for (int i = 1; i <= N; ++i)
        cout << res[i] << "\n";
}