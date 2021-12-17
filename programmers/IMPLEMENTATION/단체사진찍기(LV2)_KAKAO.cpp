#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int friendsCnt;
int totalCnt;
int conditionCnt;
string kakaoFriends;
string curLine;
vector<string> conditions;

void initData(int n, vector<string> & data){
    friendsCnt = 8;
    totalCnt = 0;
    conditionCnt = n;
    kakaoFriends = "ACFJMNRT";
    conditions = vector<string>(data);
    totalCnt = 0;
}

bool checkCondition(){
    char friend1, friend2, condition;
    int distance;
    int idx1, idx2;
    for(int cIdx = 0; cIdx < conditionCnt; ++cIdx){
        friend1 = conditions[cIdx][0];
        friend2 = conditions[cIdx][2];
        condition = conditions[cIdx][3];
        distance = conditions[cIdx][4] - '0' + 1;
        
        for(int idx = 0; idx < friendsCnt; ++ idx){
            if(curLine[idx] == friend1) idx1 = idx;
            if(curLine[idx] == friend2) idx2 = idx;
        }
        
        switch(condition){
            case '=' : 
                if(abs(idx1 - idx2) != distance)   
                    return false; 
                break;
            case '<' : 
                if(abs(idx1 - idx2) >= distance)   
                    return false; 
                break;
            case '>' : 
                if(abs(idx1 - idx2) <= distance)   
                    return false; 
                break;
        }
    }
    
    return true;
} 

void makeLine(int cnt, int visit){
    if(cnt == friendsCnt){
        if(checkCondition()){
            ++totalCnt;
        }
        return;
    }
    
    for(int idx = 0; idx < friendsCnt; ++idx){
        if((visit & (1 << idx)))    continue;
        visit |= (1 << idx);
        curLine.push_back(kakaoFriends[idx]);
        makeLine(cnt + 1, visit);
        curLine.pop_back();
        visit ^= (1 << idx);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    initData(n, data);
    makeLine(0, 0);    
    int answer = totalCnt;
    return answer;
}