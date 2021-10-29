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
};

bool isExist[MX_SZ];
priority_queue<node, vector<node>, greater<>> maxQueue;
priority_queue<node, vector<node>, less<>> minQueue;

void initData(int dataSize){
    for(int idx = 0; idx < dataSize; ++idx){
        isExist[idx] = 0;
    }
    maxQueue = priority_queue<node, vector<node>, greater<>>();
    minQueue = priority_queue<node, vector<node>, less<>>();
}

vector<string> parsingString(string str)
{
    vector<string> rslt;
    
    int delimIdx = str.find(" ");
    rslt.push_back(str.substr(0, delimIdx));
    rslt.push_back(str.substr(delimIdx + 1, str.size()));
    return rslt;
}

int executeOperation(string executionType, string executionVal){
    int val = stoi(executionVal);
    cout << executionType << " " << val << endl;
    return 0;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int dataSize = operations.size();
    initData(dataSize);
    
    vector<string> operation;
    for(int idx = 0; idx < dataSize; ++idx){
        operation = parsingString(operations[idx]);
        answer.push_back(executeOperation(operation[0], operation[1]));
    }
    
    return answer;
}
