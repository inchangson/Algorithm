#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lost_size;
int reserve_size;
int max_case;

void borrow_clothes(int idx, int stu_num, vector<bool> & checked, const vector<int> & lost, const vector<int> & reserve){
    if(idx == lost_size){
        max_case = stu_num > max_case ? stu_num : max_case;
        return;
    }
    if(stu_num + lost_size - idx  <= max_case)  return;
    
    borrow_clothes(idx + 1, stu_num, checked, lost, reserve);
    for(int stu = 0; stu < reserve_size; ++stu){
        if(checked[stu])    continue;
        if(reserve[stu] - lost[idx] > 1)    continue;
        if(reserve[stu] - lost[idx] < -1)   continue;
        
        checked[stu] = true;
        borrow_clothes(idx + 1, stu_num + 1, checked, lost, reserve);
        checked[stu] = false;
    }
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    //init g var
    max_case = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    //optimize data
    int idx_r = 0;
    int idx_l = 0;
    while(idx_l < (int)lost.size() && idx_r < (int)reserve.size()){
        if(idx_l < 0)   ++idx_l;
        if(idx_r < 0)   ++idx_r;
        if(lost[idx_l] > reserve[idx_r]){
            ++idx_r;
        }else if(lost[idx_l] < reserve[idx_r]){
            ++idx_l;
        }else{
            lost.erase(lost.begin() + idx_l);
            reserve.erase(reserve.begin() + idx_r);
            --idx_l;
            --idx_r;
        }
    }
    
    vector<bool> checked;
    for(int idx = 0; idx < reserve.size(); ++idx){
        checked.push_back(false);
    }
    
    lost_size = lost.size();
    reserve_size = reserve.size();
    
    max_case = n - lost_size;
    borrow_clothes(0, n - lost_size, checked, lost, reserve);
    
    int answer = max_case;
    return answer;
}