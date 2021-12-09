#include <string>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int MX = 1000000;
int memo[MX];

int getMaxMoney(int idx, const int ep, vector<int> & memo, const vector<int> & money){
    if(idx == ep){
        return money[idx];
    }
    if(idx > ep){
        return 0;
    }
    
    int &ret = memo[idx];
    if(ret != -1)   return ret;
    
    ret = max(getMaxMoney(idx + 1, ep, memo, money), 
              money[idx] + getMaxMoney(idx + 2, ep, memo, money));
    return ret;
}

int solution(vector<int> money) {
    int h_cnt = money.size();
    vector<int> memo1, memo2;
    memo1.resize(h_cnt);
    memo2.resize(h_cnt);
    for(int idx = 0; idx < h_cnt; ++idx){
        memo1[idx] = memo2[idx] = -1;
    }
    int answer = max(getMaxMoney(1, h_cnt - 1, memo1, money), 
                 money[0] + getMaxMoney(2, h_cnt - 2, memo2, money));
    return answer;
}
