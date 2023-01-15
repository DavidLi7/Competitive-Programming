#include <iostream>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100;

int N;
set<int> el;
map<string, int> mtoi;
string itom[13];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    mtoi["A"] = 0;
    itom[0] = "A";
    mtoi["A#"] = 1;
    itom[1] = "A#";
    mtoi["B"] = 2;
    itom[2] = "B";
    mtoi["C"] = 3;
    itom[3] = "C";
    mtoi["C#"] = 4;
    itom[4] = "C#";
    mtoi["D"] = 5;
    itom[5] = "D";
    mtoi["D#"] = 6;
    itom[6] = "D#";
    mtoi["E"] = 7;
    itom[7] = "E";
    mtoi["F"] = 8;
    itom[8] = "F";
    mtoi["F#"] = 9;
    itom[9] = "F#";
    mtoi["G"] = 10;
    itom[10] = "G";
    mtoi["G#"] = 11;
    itom[11] = "G#";
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        el.insert(mtoi[s]);
    }
    int c = 0;
    for(int i = 0; i < 12; i++){
        set<int> ok;
        ok.insert(i);
        ok.insert((i + 2) % 12);
        ok.insert((i + 4) % 12);
        ok.insert((i + 5) % 12);
        ok.insert((i + 7) % 12);
        ok.insert((i + 9) % 12);
        ok.insert((i + 11) % 12);
        bool good = true;
        for(int x: el){
            if(ok.find(x) == ok.end()){
                good = false;
                break;
            }
        }
        if(good){
            cout << itom[i] << " ";
            c++;
        }
    }
    if(c == 0){
        cout << "none";
    }
}