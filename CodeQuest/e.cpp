#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct event{
    int year, month, day, amt, type;
};

const int monthDayCounts[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool operator<(const event& a, const event& b){
    if(a.year == b.year){
        if(a.month == b.month){
            if(a.day == b.day){
                return a.amt < b.amt;
            }
            return a.day < b.day;
        }
        return a.month < b.month;
    }
    return a.year < b.year;
}

int getLeap(event a){
    int y = a.year;
    if(a.month <= 2)
        y--;
    return y / 4 - y / 100 + y / 400;
}

int daysBetween(event a, event b){
    int ad = a.year * 365 + a.day;
    ad += getLeap(a);
    for(int i = 0; i < a.month - 1; i++)
        ad += monthDayCounts[i];
    int bd = b.year * 365 + b.day;
    bd += getLeap(b);
    for(int i = 0; i < b.month - 1; i++)
        bd += monthDayCounts[i];
    return bd - ad;
}

int T;

int main() {
     
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout.tie (0);
    
    cin >> T;
    while(T--){
        int P, O;
        vector<event> a;
        cin >> P >> O;
        for(int i = 0; i < P; i++){
            string s;
            int t;
            cin >> s >> t;
            event temp;
            temp.year = stoi(s.substr(0, 4));
            temp.month = stoi(s.substr(5, 2));
            temp.day = stoi(s.substr(8, 2));
            temp.amt = t;
            temp.type = 1;
            a.push_back(temp);
        }
        for(int i = 0; i < O; i++){
            string s;
            int t;
            cin >> s >> t;
            event temp;
            temp.year = stoi(s.substr(0, 4));
            temp.month = stoi(s.substr(5, 2));
            temp.day = stoi(s.substr(8, 2));
            temp.amt = t;
            temp.type = 0;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        queue<event> curr;
        bool done = false;
        for(int i = 0; i < a.size() && !done; i++){
            // cout << a[i].year << " " << a[i].month << " " << a[i].day << "\n";
            if(!curr.empty() && daysBetween(curr.front(), a[i]) > 28)
                done = true;
            if(a[i].type == 0){
                if(a[i].amt > curr.size()){
                    done = true;
                    break;
                }
                for(int j = 0; j < a[i].amt; j++){
                    curr.pop();
                }
            }
            else{
                for(int j = 0; j < a[i].amt; j++){
                    curr.push(a[i]);
                }
            }
        }
        if(done || curr.size() != 0)
            cout << "NOT OK\n";
        else
            cout << "OK\n";
    }
    
}