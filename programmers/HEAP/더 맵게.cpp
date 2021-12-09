#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1;
    priority_queue<int, vector<int>, greater<int> > leo_dishes;
    for(int dish : scoville){
        leo_dishes.push(dish);
    }
    
    int now, next, cnt;
    for(cnt = 0; leo_dishes.size() > 1 ; ++cnt){
        now = leo_dishes.top();
        leo_dishes.pop();
        next = leo_dishes.top();
        leo_dishes.pop();
        if(now >= K)    break;
        leo_dishes.push(now + next * 2);        
    }
    if(leo_dishes.top() >= K)   return cnt;
    else                        return -1;
}
