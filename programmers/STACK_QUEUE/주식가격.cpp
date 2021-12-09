#include <string>
#include <vector>
#include <map>
#include <queue>

#include <iostream>

using namespace std;

typedef struct stock{
    int _won;
    int _clock;
    bool operator < (const stock & s) const{
        return _won < s._won;
    }
}stock;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    priority_queue<stock> s;
    int idx1;
    
    for(idx1 = 0; idx1 < prices.size(); ++idx1){
        s.push({prices[idx1], idx1});
        answer.push_back(0);
        while(s.top()._won > prices[idx1]){
            stock tmp = s.top();  
            answer[tmp._clock] = idx1 - tmp._clock;
            s.pop();
        }
    }
    --idx1;
    while(!s.empty()){
        stock tmp = s.top();  
        answer[tmp._clock] = idx1 - tmp._clock;
        s.pop();
    }
    
    return answer;
}
