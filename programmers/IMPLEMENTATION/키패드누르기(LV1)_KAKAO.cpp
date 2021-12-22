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

int getAbs(int n){
    if(n < 0) return -n;
    return n;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    initData();
    
    bool isRightHanded = hand[0] == 'r';
    int keyR, keyC;
    int distR, distL;
    for(int curNum : numbers){
        keyR = keyLookUp[curNum].r;
        keyC = keyLookUp[curNum].c;
        
        if(keyC == 0){
            answer += L;
            curL = keyLookUp[curNum];
            continue;
        }
        if(keyC == 2){
            answer += R;
            curR = keyLookUp[curNum];
            continue;
        }
        
        distR = (getAbs(keyR - curR.r) + getAbs(keyC - curR.c));
        distL = (getAbs(keyR - curL.r) + getAbs(keyC - curL.c));
        
        if(distL < distR){
            answer += L;
            curL = keyLookUp[curNum];
            continue;
        }
        if(distL > distR){
            answer += R;
            curR = keyLookUp[curNum];
            continue;
        }
        
        if(isRightHanded){
            answer += R;
            curR = keyLookUp[curNum];
        }
        else{
            answer += L;
            curL = keyLookUp[curNum];
        }        
    }
    
    return answer;
}