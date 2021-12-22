#include <string>
#include <vector>

using namespace std;

constexpr int DIR_CNT = 4;
constexpr int DIR[DIR_CNT][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
constexpr int WIDTH = 3;
constexpr int HEIGHT = 4;
constexpr int START_ROW = HEIGHT - 1;
constexpr int START_COL_L = 0;
constexpr int START_COL_R = WIDTH - 1;
constexpr char L = 'L';
constexpr char R = 'R';
    
struct key{
    int r, c;
};

key keyLookUp[10];
key curR;
key curL;

void makeKeyLookUp(){
    for(int i = 0; i <= 9; ++i){
        keyLookUp[i + 1] = {(i / WIDTH), (i % WIDTH)};
    } 
    keyLookUp[0] = {START_ROW, 1};
}

void initData(){
    makeKeyLookUp();
    curL = {START_ROW, START_COL_L};
    curR = {START_ROW, START_COL_R};
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    initData();
    
    bool isRightHanded = hand[0] == 'r';
    int keyR, keyC;
    for(int curNum : numbers){
        keyR = keyLookUp[curNum].r;
        keyC = keyLookUp[curNum].c;
        
        if(keyC == 0){
            answer += L;
            curL = {keyR, keyC};
        }
        else if(keyC == 2){
            answer += R;
            curR = {keyR, keyC};
        }
        else{
            int distL = (keyR - curL.r) * (keyR - curL.r) +
                        (keyC - curL.c) * (keyC - curL.c);
            int distR = (keyR - curR.r) * (keyR - curR.r) +
                        (keyC - curR.c) * (keyC - curR.c);
            if(distL == distR){
                if(isRightHanded){
                    answer += R;
                    curR = {keyR, keyC};
                }
                else{
                    answer += L;
                    curL = {keyR, keyC};
                }
            }
            else if(distL < distR){
                answer += L;
                curL = {keyR, keyC};
            }
            else{
                answer += R;
                curR = {keyR, keyC};
            }
        }
        
    }
    
    return answer;
}