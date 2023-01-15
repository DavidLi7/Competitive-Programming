#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);

    //creating and reading in the number of nodes and the target value
    int n, x;
    cin >> n >> x;

    //creating and reading in the array
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    //Vals stores the location of every value in the array
    //The keys are values and they map to locations.
    map<int, int> vals;
    for(int i = 0; i < n; i++){
        //checking if we have seen the value x - a[i] before
        if(vals.count(x - a[i])){
            //Print answer and terminate program if we find one
            cout << i + 1 << " " << vals[x - a[i]] << "\n";
            return 0;
        }
        //adding new element to our map
        vals[a[i]] = i + 1;
    }
    //If no solution, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE" << "\n";
}