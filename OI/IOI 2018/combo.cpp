#include "combo.h"
#include <vector>

char terms[4] = {'A', 'B', 'X', 'Y'};

std::string guess_sequence(int N) {
    std::string p = "";
    std::string answer = "";
    std::vector <int> ok;
    int s = -1;
    p = answer + terms[0] + answer + terms[1];
    if(press(p) > 0){
        ok.push_back(2);
        ok.push_back(3);
        p = answer + terms[0];
        if(press(p) > 0){
            s = 0;
            ok.push_back(1);
        }
        else{
            s = 1;
            ok.push_back(0);
        }
    }
    else{
        ok.push_back(0);
        ok.push_back(1);
        p = answer + terms[2];
        if(press(p) > 0){
            s = 2;
            ok.push_back(3);
        }
        else{
            s = 3;
            ok.push_back(2);
        }
    }
    answer += terms[s];
    if(N == 1)
        return answer;
    for(int i = 1; i < N - 1; i++){
        p = answer + terms[ok[0]] + terms[ok[0]] + answer + terms[ok[0]] + terms[ok[1]] + answer + terms[ok[0]] + terms[ok[2]] + answer + terms[ok[1]];
        int count = press(p);
        if(count == i + 2){
            answer += terms[ok[0]];
        }
        else if(count == i + 1){
            answer += terms[ok[1]];
        }
        else{
            answer += terms[ok[2]];
        }
    }
    p = answer + terms[0] + answer + terms[1];
    if(press(p) == N){
        p = answer + terms[0];
        if(press(p) == N){
            answer += terms[0];
        }
        else{
            answer += terms[1];
        }
    }
    else{
        p = answer + terms[2];
        if(press(p) == N){
            answer += terms[2];
        }
        else{
            answer += terms[3];
        }
    }

    return answer;
}