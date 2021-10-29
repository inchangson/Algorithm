#include <string>
#include <vector>
#include <queue>

#include <iostream>

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
priority_queue<node, vector<node>, greater<>> maxHeap;
priority_queue<node, vector<node>, less<>> minHeap;
int heapSize;

void initData(int dataSize){
    for(int idx = 0; idx < dataSize; ++idx){
        isExist[idx] = 0;
    }
    maxHeap = priority_queue<node, vector<node>, greater<>>();
    minHeap = priority_queue<node, vector<node>, less<>>();
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
    cout << "\n======pushData Start======\n";
    ++heapSize;
    isExist[heapSize] = true;
    minHeap.push({heapSize, val});
    maxHeap.push({heapSize, val});
    
    cout << heapSize << " " << val << endl;    
    cout << "======pushData End======\n";

}

int popMax(bool isSucceed){
    int retVal = -1;
    isSucceed = false;
    while(isExist[maxHeap.top().index] && !maxHeap.empty()){
        maxHeap.pop();    
    }
    if(maxHeap.empty()) return retVal;
    isSucceed = true;
    isExist[maxHeap.top().index] = false;
    retVal = maxHeap.top().value;
    maxHeap.pop();
    return retVal;
}

int popMin(bool isSucceed){
    int retVal = -1;
    isSucceed = false;
    while(isExist[minHeap.top().index] && !minHeap.empty()){
        minHeap.pop();    
    }
    if(minHeap.empty()) return retVal;
    isSucceed = true;
    isExist[minHeap.top().index] = false;
    retVal = minHeap.top().value;
    minHeap.pop();
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
        answer.push_back(min);
        answer.push_back(max);
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
        operation = parsingString(operations[idx]);
        executeOperation(operation[0], operation[1]);
    }
    getAnswer(answer);
    
    return answer;
}
