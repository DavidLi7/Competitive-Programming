#include <iostream>

using namespace std;


int x;

string query(int t){
    if(t == x){
        return "correct";
    }
    if(t > x)
        return "lower";
    return "higher";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    x = 253;

    int lo = 1;
    int hi = 1000;
    bool solved = false;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        cout << mid << endl;
        string s;
        cin >> s;
        //s = query(mid);
        if(s == "lower"){
            hi = mid - 1;
        }
        else if(s == "higher"){
            lo = mid + 1;
        }
        else{
            solved = true;
            break;
        }
    }
    if(!solved){
        cout << lo << endl;
    }
}