#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    
    int cameraCnt = 1;
    int endPoint = routes[0][1];
    int loopSize = routes.size();
    for(int idx = 1; idx < loopSize; ++idx){
        if(routes[idx][0] <= endPoint){
            if(routes[idx][1] < endPoint){
                endPoint = routes[idx][1];
            }
        }else{
            ++cameraCnt;
            endPoint = routes[idx][1];
        }
    }
    
    answer = cameraCnt;
    return answer;
}
