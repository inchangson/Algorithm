#include <string>
#include <vector>

#define PLUS 0
#define MINUS 1
#define MULT 2
#define DIV 3

using namespace std;

int src;
int target;

constexpr int OPER_CNT = 4;
vector<vector<long long>> memo;

long long make_nn(int cards){
    if(cards == 0)  return 0;
    long long ret = src;
    while(--cards > 0){
        ret = ret * 10 + src;
    }
    return ret;
}

int get_calc_rslt(long long n1, long long  n2, int oper, bool & success){
    success = true;
    switch(oper){
        case PLUS : return int(n1 + n2);
        case MINUS : return int(n1 - n2);
        case MULT : return int(n1 * n2);
        case DIV : if(n2)   return int(n1 / n2);
    }
    success = false;
    return -1;
}

int make_number(int cards){
    if(cards == 9) return -1;
    long long nn = make_nn(cards);
    if(nn == target)    return cards;
    vector<long long> buf;
    buf.push_back(nn);
    
    int rslt;
    int idx1, idx2;
    int oper;
    int n1, n2;
    bool bTmp;
    
    for(idx1 = 1 ; idx1 < cards; ++idx1){
        idx2 = cards - idx1;
        for(n1 = 0; n1 < memo[idx1].size(); ++n1){
            for(n2 = 0; n2 < memo[idx2].size(); ++n2){
                for(oper = 0; oper < OPER_CNT; ++oper){
                    bTmp = false;
                    rslt = get_calc_rslt(memo[idx1][n1], memo[idx2][n2], oper, bTmp);
                    if(!bTmp)   continue;
                    if(rslt == target)  return cards;
                    buf.push_back(rslt);
                }
            }
        }
    }
    
    memo.push_back(buf);
    return make_number(cards + 1);
}

int solution(int N, int number) {
    int answer = 0;
    src = N;
    target = number;
    answer = make_number(0);
    
    return answer;
}
