#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> closet;
    for(vector<string> cloth : clothes)
    {
        ++closet[cloth[1]];
    }
    
    int answer = 1;
    for(auto item : closet)
    {
        answer *= item.second + 1;
    }
    --answer;
    return answer;
}
