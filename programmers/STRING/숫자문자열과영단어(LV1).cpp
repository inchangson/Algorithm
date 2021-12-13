#include <string>
#include <vector>

#include <iostream>

using namespace std;

bool isCorrectInput(char c){
    if(c == '-' || c == '_' || c == '.')    return true;
    if(c >= '0' && c <= '9')    return true;
    if(c >= 'a' && c <= 'z')    return true;
    return false;
}

string solution(string new_id) {
    string answer = "";
    
    const string DEFAULT_ID = "a";
    const int MX_LENG = 15;
    const int MIN_LENG = 3;
    
    int curLeng = 0;
    
    for(int idx = 0; idx < new_id.size(); ++idx){
        char c = new_id[idx];
        if(curLeng >= MX_LENG){
            break;
        }
        if(c == '.'){
            if(curLeng == 0)    continue;
            if(answer.back() == '.')  continue;
        }
        if(c >= 'A' && c <= 'Z'){
            c |= (0x1u << 5);
        }
        if(isCorrectInput(c) == false){
            continue;
        }
        answer += c;
        curLeng++;
    }
    
    if(answer.empty()){
        answer = "a";
        curLeng++;
    }
    
    if(answer.back() == '.'){
        answer.pop_back();
        curLeng--;
    }
    
    while(curLeng < MIN_LENG){
        answer += answer.back();
        curLeng++;    
    }
    
    return answer;
}