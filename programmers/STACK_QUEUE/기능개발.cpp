#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> leftDays;
    const int SUCCESS = 100;
    
    for(int idx = 0; idx < progresses.size(); ++idx){
        leftDays.push_back(1 + ceil((double)(SUCCESS - progresses[idx]) / speeds[idx]));
    }
    
    for(int idx1 = 0; idx1 < leftDays.size(); ++idx1){
        int cnt = 1;
        int releaseDay = leftDays[idx1];
        for(int idx2 = idx1 + 1; idx2 < leftDays.size(); ++idx2){
            if(leftDays[idx2] > releaseDay) break;
            ++cnt;
            ++idx1;
        }
        answer.push_back(cnt);
    }
    return answer;
}
