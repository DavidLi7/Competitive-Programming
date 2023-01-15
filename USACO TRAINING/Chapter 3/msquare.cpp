/*
ID: divadxl1
LANG: C++
TASK: msquare
*/

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <stack>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

map<int, pair<int, char> > m;

int main(){
    setIO("msquare");
    queue<int>PQ;
    int t = 0;
    for(int i = 0; i < 8; i++){
        t *= 10;
        int x;
        cin >> x;
        t += x;
    }
    if(t == 12345678){
        cout << "0\n\n";
        return 0;
    }
    PQ.push(12345678);
    m[12345678] = make_pair(-1, 'Z');
    while(!PQ.empty()){
        int temp = PQ.front();
        PQ.pop();
        if(temp == t){
            stack<char> ans;
            while(m[temp].first != -1){
                ans.push(m[temp].second);
                temp = m[temp].first;
            }
            cout << ans.size();
            int x = 0;
            while(!ans.empty()){
                if(x % 60 == 0)
                    cout << "\n";
                cout << ans.top();
                ans.pop();
                x++;
            }
            cout << "\n";
        }
        vector<int> nums(8);
        int copy = temp;
        for(int i = 7; i >= 0; i--){
            nums[i] = copy % 10;
            copy /= 10;
        }
        int a = 0;
        for(int i = 7; i >= 0; i--){
            a *= 10;
            a += nums[i] % 10;
        }
        
        if(m.find(a) == m.end()){
            m[a] = make_pair(temp, 'A');
            PQ.push(a);
        }
        int b = nums[3];
        for(int i = 0; i < 3; i++){
            b *= 10;
            b += nums[i];
        }
        for(int i = 5; i < 8; i++){
            b *= 10;
            b += nums[i];
        }
        b *= 10;
        b += nums[4];
        if(m.find(b) == m.end()){
            m[b] = make_pair(temp, 'B');
            PQ.push(b);
        }
        swap(nums[1], nums[6]);
        swap(nums[6], nums[2]);
        swap(nums[6], nums[5]);
        int c = 0;
        for(int i = 0; i < 8; i++){
            c *= 10;
            c += nums[i] % 10;
        }
        if(m.find(c) == m.end()){
            m[c] = make_pair(temp, 'C');
            PQ.push(c);
        }
    }

}