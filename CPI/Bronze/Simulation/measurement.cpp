#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int main(){
    setIO("measurement");
 
    int N;
    cin >> N;
    vector<int> day(N), change(N);
    vector<string> cow(N);
    for(int i = 0; i < N; i++){
        cin >> day[i] >> cow[i] >> change[i];
    }
    int bessieMilk = 7, elsieMilk = 7, mildredMilk = 7;
    bool bessieOn = true, elsieOn = true, mildredOn = true;
    int ans = 0;

    for(int d = 1; d <= 100; d++){
        for(int i = 0; i < N; i++){
            if(day[i] == d){
                if(cow[i] == "Bessie") {
                    bessieMilk += change[i];
                }
                if(cow[i] == "Elsie") {
                    elsieMilk += change[i];
                }
                if(cow[i] == "Mildred") {
                    mildredMilk += change[i];
                }
            }
        }
        int highestMilk = max(bessieMilk, max(elsieMilk, mildredMilk));
        bool bessieOnNext = bessieMilk == highestMilk;
        bool elsieOnNext = elsieMilk == highestMilk;
        bool mildredOnNext = mildredMilk == highestMilk;
        if(bessieOn != bessieOnNext || elsieOn != elsieOnNext || mildredOn != mildredOnNext) {
            ans++;
        }
        bessieOn = bessieOnNext;
        elsieOn = elsieOnNext;
        mildredOn = mildredOnNext;
    }

    cout << ans;
}