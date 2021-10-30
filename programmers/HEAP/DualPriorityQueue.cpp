#include <string>
#include <vector>
#include <queue>

#include <cstdio>

using namespace std;

constexpr int MX_SZ = 1000000;

struct node {
    int index;
    int value;
    bool operator < (const node& n) const{
        return value < n.value;
    }
    bool operator > (const node& n) const{
        return value > n.value;
    }
};

bool isExist[MX_SZ];
priority_queue<node, vector<node>, less<>> maxHeap;
priority_queue<node, vector<node>, greater<>> minHeap;

int heapSize;

void initData(int dataSize){
    for(int idx = 0; idx < dataSize; ++idx){
        isExist[idx] = false;
    }
    maxHeap = priority_queue<node, vector<node>, less<>>();
    minHeap = priority_queue<node, vector<node>, greater<>>();
    heapSize = 0;
}

vector<string> parsingString(string str)
{
    vector<string> rslt;
    
    int delimIdx = str.find(" ");
    rslt.push_back(str.substr(0, delimIdx));
    rslt.push_back(str.substr(delimIdx + 1, str.size()));
    
    return rslt;
}

void pushData(int val){
    //printf("\n======pushData Start======\n");
    ++heapSize;
    isExist[heapSize] = true;
    minHeap.push({heapSize, val});
    maxHeap.push({heapSize, val});
    
    //printf("heapSize %d val %d\n", heapSize, val);
    //printf("\n======pushData End======\n");

}

int popMax(bool & isSucceed){
    //printf("\n======popMax Start======\n");
    int retVal = -1;
    isSucceed = false;
    while(!maxHeap.empty() && !isExist[maxHeap.top().index]){
        //printf("index %d value %d\n", maxHeap.top().index, maxHeap.top().value);
        maxHeap.pop();
    }
    if(maxHeap.empty()) return retVal;
    isSucceed = true;
    
    isExist[maxHeap.top().index] = false;
    retVal = maxHeap.top().value;
    maxHeap.pop();
    
    //printf("pop -> index %d value %d\n", maxHeap.top().index, maxHeap.top().value);
    //printf("\n======popMax End======\n");
    return retVal;
}

int popMin(bool & isSucceed){
    //printf("\n======popMin Start======\n");
    int retVal = -1;
    isSucceed = false;
    while(!minHeap.empty() && !isExist[minHeap.top().index]){
        //printf("index %d value %d\n", minHeap.top().index, minHeap.top().value);
        minHeap.pop();    
    }
    if(minHeap.empty()) return retVal;
    
    isSucceed = true;
    isExist[minHeap.top().index] = false;
    retVal = minHeap.top().value;
    
    //printf("pop -> index %d value %d\n", minHeap.top().index, minHeap.top().value);
    
    minHeap.pop();
    
    //printf("\n======popMax End======\n");
    return retVal;
}

void executeOperation(string executionType, string executionVal){
    if(executionType == "I"){
        pushData(stoi(executionVal));
    }else if(executionVal == "1"){
        bool isSucceed;
        popMax(isSucceed);
    }else{
        bool isSucceed;
        popMin(isSucceed);
    }
}

void getAnswer(vector<int> & answer){
    
    int min;
    int max;
    bool isSucceed1;
    bool isSucceed2;
    min = popMin(isSucceed1);
    max = popMax(isSucceed2);
    if(isSucceed1 && isSucceed2){
        answer.push_back(max);
        answer.push_back(min);
    }else if(isSucceed1 && !isSucceed2){
        answer.push_back(min);
        answer.push_back(min);
    }else{
        answer.push_back(0);
        answer.push_back(0);
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int dataSize = operations.size();
    initData(dataSize);
    
    vector<string> operation;
    for(int idx = 0; idx < dataSize; ++idx){
        vector<string> operation = parsingString(operations[idx]);
        executeOperation(operation[0], operation[1]);
    }
    getAnswer(answer);
    
    return answer;
}
