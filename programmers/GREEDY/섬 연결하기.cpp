#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MX_CNT = 100;
constexpr int NONE = 0;

constexpr int ISLAND1 = 0;
constexpr int ISLAND2 = 1;
constexpr int COST_IDX = 2;

int islandCnt;
int states[MX_CNT];
int minCost;

vector<vector<int>> bridgeCosts;

void initData(){
    islandCnt = 0;
    minCost = 0x7FFFFFFF;
    for(int idx = 0; idx < MX_CNT; ++idx){
        states[idx] = NONE;
    }
}

bool checkAllConnected(){
    int islandNo = states[0];
    if(islandNo == 0)   return false;
    for(int idx = 0; idx < islandCnt; ++idx){
        if(states[idx] != islandNo)    return false;
    }
    return true;
}

void connectIsland(int curCost, int curIdx, int curIslandNo){
    if(curIdx == islandCnt){
        if(checkAllConnected()){
            if(minCost > curCost)   minCost = curCost;
        }
        return;
    }
    connectIsland(curCost, curIdx + 1, curIslandNo + 1);
                  
    int island1 = bridgeCosts[curIdx][ISLAND1];
    int island2 = bridgeCosts[curIdx][ISLAND2];
    int preIsland1 = states[island1];
    int preIsland2 = states[island2];
    
    if(preIsland1 && preIsland2){
        vector<int> tmpStates;
        tmpStates.reserve(islandCnt);
        for(int idx = 0; idx < islandCnt; ++idx){
            tmpStates.push_back(states[idx]);
            if(states[idx] == states[island1])  states[idx] = states[island2];
        }
        connectIsland(curCost + bridgeCosts[curIdx][COST_IDX], curIdx + 1, curIslandNo + 1);
        for(int idx = 0; idx < islandCnt; ++idx){
            states[idx] = tmpStates[idx];
        }
    }else{        
        if(preIsland1){
            states[island2] = states[island1];
        }else if(preIsland2){
            states[island1] = states[island2];
        }else{
            states[island1] = states[island2] = curIslandNo;
        }
        connectIsland(curCost + bridgeCosts[curIdx][COST_IDX], curIdx + 1, curIslandNo + 1);   
        states[island1] = preIsland1;
        states[island2] = preIsland2;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    initData();    
    islandCnt = n; 
    bridgeCosts = vector<vector<int>>(costs);
    connectIsland(0, 0, 1);
    bridgeCosts.clear();
    answer = minCost;
    return answer;
}