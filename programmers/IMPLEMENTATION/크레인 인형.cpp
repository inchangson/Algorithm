#include <string>
#include <vector>
#include <stack>

using namespace std;

void putInBasket(int d, int cnt, stack<int> & basket){
    static int ftnCnt = 0;
    ftnCnt++;
    if(basket.empty()){
        basket.push(d);
        
        printf("ftnCnt %d d %d(empty)\n", ftnCnt, d);
        return;
    }
    int lastDoll = basket.top();
    if(d == lastDoll){
        ++cnt;
        printf("cnt %d d %d\n", ftnCnt, d);
        basket.pop();
    }
    else{
        basket.push(d);
        printf("cnt %d d %d\n", ftnCnt, d);
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    int boardSize = board.size();
    for(int m : moves){
        for(int c = 0; c < boardSize; ++c){
            int d = board[c][m - 1];
            if(d == 0)  continue;
            putInBasket(d, answer, basket);
            d = 0;
            break;
        }    
    }
    
    return answer;
}