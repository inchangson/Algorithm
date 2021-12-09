#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int get_answer(const vector<int> & citations){
    int lo, hi, mid, cnt, ans;
    ans = lo = 0;
    hi = citations.size() - 1;
    
    if(!citations[0])   return 0;
    
    while(lo < hi){
        mid = (lo + hi) / 2;
        cnt = mid + 1;
        if(cnt >= citations[mid]){
            hi = mid - 1;
            ans = max(ans, citations[mid]);
        }
        else{
            lo = mid + 1;
            ans = max(ans, cnt);
        }
    }
    
    if(ans)
        return ans;
    else
        return citations.size();
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare);
    answer = get_answer(citations);
    return answer;
}
