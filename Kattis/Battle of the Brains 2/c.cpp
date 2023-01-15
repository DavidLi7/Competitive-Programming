#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

long long N;

vector<pair<long long, int> > getFact(long long n){
    vector<pair<long long, int> > ret;
    pair<long long, int> temp = make_pair(2, 0);
    while(n % 2 == 0){
        temp.second++;
        n /= 2;
    }
    if(temp.second != 0){
        ret.push_back(temp);
    }
    for(long long i = 3; i * i <= n; i += 2){
        pair<long long, int> temp = make_pair(i, 0);
        while(n % i == 0){
            temp.second++;
            n /= i;
        }
        if(temp.second != 0){
            ret.push_back(temp);
        }
    }
    if(n > 2){
        ret.push_back(make_pair(n, 1));
    }
    return ret;
}

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    cin >> N;
    vector<pair<long long, int> > f = getFact(N);
    int bigval = 0;
    int k = 0;
    for(auto it: f){
        if(it.second > bigval){
            k = it.first;
            bigval = it.second;
        }
    }
    cout << k << '\n';

        
    
    
}