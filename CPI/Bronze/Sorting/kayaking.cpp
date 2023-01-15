#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 55;

int N, w[MAXN];

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    //read in the input values
    cin >> N;
    for(int i = 0; i < 2 * N; i++){
        cin >> w[i];
    }

    //sort the people by weight
    sort(w, w + 2 * N);
    
    int ans = 1e9;//this variable will store our answer

    //loop through all possible combinations of people in the single kayaks
    for(int i = 0; i < 2 * N; i++){
        for(int j = i + 1; j < 2 * N; j++){

            //vector 's' will store the weights of the people who need to be placed in tandem kayaks
            vector<int> s;
            for(int k = 0; k < 2 * N; k++){
                if(k != i && k != j)
                    s.push_back(w[k]);
            }

            int temp = 0;//this variable stores the instability of this situation

            //calculating instability
            for(int k = 0; k < 2 * N - 2; k += 2){
                temp += s[k + 1] - s[k];
            }

            //if this instability is lower than our current answer, then update answer
            ans = min(ans, temp);
        }
    }

    //print the answer
    cout << ans << "\n";

        
    
    
}