#include <string>
#include <vector>
#include <cstring>

using namespace std;

int leng;
bool visited[200];

void check_network(int node, const vector<vector<int>> & computers)
{
    visited[node] = true;
    
    for(int next = 0; next < leng; ++next)
    {
        if(visited[next])
            continue;
        if(computers[node][next])
            check_network(next, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    leng = computers.size();    
    
    for(int i = 0 ; i < leng; ++i)
    {
        if(visited[i])
            continue;        
        check_network(i, computers);
        ++answer;
    }
    
    return answer;
}
