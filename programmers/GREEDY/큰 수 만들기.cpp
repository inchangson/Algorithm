#include <string>
#include <vector>

using namespace std;

int numCnt;
vector<int> num;

void findMax(int curIdx, int digits, string & ans){
    if(digits == 0) return;
    
    int maxIdx = -1;
    int max = -1;
    for(int idx = curIdx + 1; idx <= numCnt - digits; ++idx){
        if(num[idx] > max){
            max = num[idx];
            maxIdx = idx;
        }
    }
    ans += to_string(max);
    findMax(maxIdx, digits - 1, ans);
}

string solution(string number, int k) {
    string answer = "";
    
    num.clear();
    for(int idx = 0; idx < number.size(); ++idx){
        num.push_back(number[idx] - '0');
    }
    
    numCnt = number.size();
    findMax(-1, numCnt - k, answer);
    
    return answer;
}