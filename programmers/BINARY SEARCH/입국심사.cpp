#include <string>
#include <vector>

using namespace std;
constexpr long long MX = 1000000000;
long long getProcessed(long long totalSec, const vector<int> &times){
    long long cnt = 0;
    for(int unit : times){
        cnt += totalSec / (long long)unit;
    }
    return cnt;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long lo = 1;
    long long hi = MX * MX;//times.size();
    long long mid;
    long long tmp;
    
    while(hi >= lo){
        mid = (lo + hi) / 2;
        tmp = getProcessed(mid, times);
        if(tmp >= n){
            hi = mid - 1;
            answer = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return answer;
}
