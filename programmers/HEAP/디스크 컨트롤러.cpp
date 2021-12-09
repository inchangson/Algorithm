#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int ST = 0;
constexpr int PT = 1;

int curSec;
int jobCnt;

class Task{
    public:
    //start time, process time
    int _st;
    int _pt;    
    Task(int st, int pt){
        _st = st;
        _pt = pt;
    }
    bool operator < (const Task& task)const{
        return _pt > task._pt;
    }
};

priority_queue<Task> taskQueue;

bool job_cmp(vector<int> & v1, vector<int> & v2){
    if(v1[ST] < v2[ST]) return true;
    else    return false;
}

void Enqueue(int & idx, const vector<vector<int>> & jobs){
    while(idx < jobCnt){
        if(jobs[idx][ST] <= curSec){
            Task curTask = Task(jobs[idx][ST], jobs[idx][PT]);
            taskQueue.push(curTask);
        }
        else{
            break;
        }
        ++idx;
    }
}


int solution(vector<vector<int>> jobs) {
    jobCnt = jobs.size();
    sort(jobs.begin(), jobs.end(), job_cmp);
    
    int totalSec = 0;
    int idx = 0;
    int completed = 0; 
    
    for(curSec = 0; completed != jobCnt ; ){
        
        Enqueue(idx, jobs);
        if(taskQueue.empty()){
            ++curSec;
            continue;
        }
        Task curTask = taskQueue.top(); taskQueue.pop();
        ++completed;
        
        curSec += curTask._pt;
        totalSec += curSec - curTask._st;
    }
    return totalSec / jobCnt;
}
