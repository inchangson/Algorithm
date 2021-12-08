#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossibleCase(int dist, vector<int> rocks, int n){
    return true;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0);
    rocks.push_back(distance);
    
    sort(rocks.begin(), rocks.end());
    for(int idx = 1; idx < rocks.size(); ++idx){
        rocks[idx - 1] = rocks[idx] - rocks[idx - 1];
    }
    rocks.resize(rocks.size() - 1);
    
    int hi = distance;
    int lo = 0;
    int mid;
    bool isPossible;
    while(hi >= lo){
        mid = (hi + lo) / 2;
        if(isPossibleCase(mid, rocks, n) == true){
            lo = mid + 1;
            printf("lo %d hi %d mid %d\n", lo, hi, mid);
            answer = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    
    return answer;
}