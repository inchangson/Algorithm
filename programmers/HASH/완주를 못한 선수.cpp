#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
   
    map<string, int> map;
    for(string p : completion)
    {
        ++map[p];
    }
    
    for(string p : participant)
    {
        --map[p];
        if(map[p] < 0)
            return p;
    }
    return "";
}
