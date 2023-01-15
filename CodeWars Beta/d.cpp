#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    map<int, string> m;
    m[10] = "ten";
    m[11] = "eleven";
    m[12] = "twelve";
    m[13] = "thirteen";
    m[14] = "fourteen";
    m[15] = "fifteen";
    m[16] = "sixteen";
    m[17] = "seventeen";
    m[18] = "eighteen";
    m[19] = "nineteen";
    m[20] = "twenty";
    m[21] = "twenty one";
    m[22] = "twenty two";
    m[23] = "twenty three";
    m[24] = "twenty four";
    m[25] = "twenty five";
    m[26] = "twenty six";
    m[27] = "twenty seven";
    m[28] = "twenty eight";
    m[29] = "twenty nine";
    m[30] = "thirty";
    cout << "There are " << m[N] << " K-Pop bands touring";
    
}