#include <iostream>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 1e6;

int N;
double cows[MAXN];

int main(){
    setIO("cowdate");

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cows[i];
        cows[i] /= MAXN;
    }
    
    int s = 0;
    int e = 1;
    double prod = 1 - cows[0];
    double sum = cows[0] / (1 - cows[0]);
    double ans = sum * prod;
    while(s<N){
        if(e==N){
            prod /= (1 - cows[s]);
            sum -= (cows[s] / (1 - cows[s]));
            s++;
        }
        else{
            double sprod = prod / (1 - cows[s]);
            double ssum = sum - (cows[s] / (1 - cows[s]));
            double eprod = prod * (1 - cows[e]);
            double esum = sum + (cows[e] / (1 - cows[e]));
            if(sprod * ssum > eprod * esum){
                prod = sprod;
                sum = ssum;
                s++;
            }
            else{
                prod = eprod;
                sum = esum;
                e++;
            }
        }
        ans = max(sum * prod, ans);
    }
    cout << (int)(ans*MAXN);




}