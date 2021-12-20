#include <string>
#include <vector>
#include <stack>

using namespace std;

void printMap(vector<vector<int>> & board){
    printf("=======printMap==========\n");
    int mapSize = board.size();
    for(int r = 0; r < mapSize; ++r){
        for(int c = 0; c < mapSize; ++c){
            printf("%2d", board[r][c]);   
        }
        printf("\n");
    }
}

void putInBasket(int d, int & cnt, stack<int> & basket){
    if(basket.empty()){
        basket.push(d);
        
        //printf("d %d push(empty)\n", d);
        return;
    }
    int lastDoll = basket.top();
    if(d == lastDoll){
        cnt += 2;
        //printf("d %d pop\n", d);
        basket.pop();
    }
    else{
        basket.push(d);
        //printf("d %d push\n", d);
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    int boardSize = board.size();
    //printMap(board);
    for(int m : moves){
        for(int c = 0; c < boardSize; ++c){
            int & d = board[c][m - 1];
            if(d == 0)  continue;
            putInBasket(d, answer, basket);
            d = 0;
            //printMap(board);
            break;
        }    
    }
    
    return answer;
}