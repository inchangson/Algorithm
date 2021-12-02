#include <string>
#include <vector>
#include <queue>

using namespace std;

constexpr int MX = 20000;

bool relation[MX + 1][MX + 1];

struct node{
    int idx, d;
};

void makeRelationArr(int n, const vector<vector<int>> & edge){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n ; ++j){
            relation[i][j] = false;
        }
    }
    
    int node1, node2;
    for(int idx = 0; idx < edge.size(); ++idx){
        node1 = edge[idx][0];
        node2 = edge[idx][1];
        relation[node1][node2] = relation[node2][node1] = true;        
    }
}

int searchLongestCount(int n){
    vector<bool> visited(n + 1);
    
    queue<node> q;
    
    q.push({1, 0});
    visited[1] = true;
    
    int longest = -1;
    int longestCnt = 0;
    while(!q.empty()){
        node currentNode = q.front();
        q.pop();
        
        int curIdx = currentNode.idx;
        int curD = currentNode.d;
        
        if(longest == curD){
            ++longestCnt;
        }
        else if(longest < curD){
            longest = curD;
            longestCnt = 1;
        }
        
        for(int nextIdx = 1; nextIdx <= n; ++nextIdx){
            if(!relation[curIdx][nextIdx])  continue;
            if(visited[nextIdx])    continue;
            visited[nextIdx] = true;
            q.push({nextIdx, curD + 1});
        }
    }
    return longestCnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    makeRelationArr(n, edge);
    answer = searchLongestCount(n);
    return answer;
}
