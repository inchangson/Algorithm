#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int ISLAND1 = 0;
constexpr int ISLAND2 = 1;
constexpr int COST = 2;

vector<int> islandID;
int costsSize;
int minBridgeCnt;

void printIslandID(){
    printf("\n");
    for(int n : islandID){
        printf("%d\t", n);
    }printf("\n");
}

bool cmp(vector<int> a, vector<int> b){
    return (a[2] < b[2]);
}

int getParent(int node) {
    if(islandID[node] == node) return node;
    return islandID[node] = getParent(islandID[node]);
}

int getIslandID(int island){
    int & idx = islandID[island];
    while(islandID[idx] != idx){
        idx = islandID[idx];
    }
    return idx;
}

int buildBridge(int curIdx, int bridgeCnt, int curCost, const vector<vector<int>> & costs){
    if(curIdx == costsSize)  return curCost;
    //if(bridgeCnt == minBridgeCnt)    return curCost;    
    printIslandID();
    
    int island1 = getParent(costs[curIdx][ISLAND1]);
    int island2 = getParent(costs[curIdx][ISLAND2]);
    
    if(island1 == island2)
        return buildBridge(curIdx + 1, bridgeCnt, curCost, costs);
    curCost += costs[curIdx][COST];
    
    if(island1 < island2){
        islandID[island2] = island1;
    }
    else{
        islandID[island1] = island2;
    }
    printf("build between %d and %d with %d cost\n", island1, island2, costs[curIdx][COST]);
    
    return buildBridge(curIdx + 1, bridgeCnt + 1, curCost, costs);
}

int solution(int n, vector<vector<int>> costs) {
    
    int answer = 0;
    
    //sort costs array
    sort(costs.begin(), costs.end(), cmp);
    
    costsSize = costs.size();
    minBridgeCnt = n - 1;
    
    //initialize islandID array
    islandID = vector<int>(n);
    int val = 0;
    for(int idx = 0; idx < n; ++idx){
        islandID[idx] = idx;
    }
    answer = buildBridge(0, 0, 0, costs);
    
    return answer;
}