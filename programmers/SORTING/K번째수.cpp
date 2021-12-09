#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int commands_size = (int)commands.size();
    answer.reserve(commands_size);
    
    int case_leng;
    int case_start;
    int case_end;
    for(int case_idx = 0; case_idx < commands_size; ++case_idx)
    {
        case_start = commands[case_idx][0] - 1;
        case_end = commands[case_idx][1] - 1;
        case_leng = case_end - case_start + 1;
        int * buf = new int[case_leng];
        int buf_idx = 0;
        for(int idx = case_start; idx <= case_end; ++ idx)
        {
            buf[buf_idx++] = array[idx];
        }
        sort(buf, buf + case_leng);
        if(commands[case_idx][2] > case_leng)
        {
            answer.push_back(buf[case_leng - 1]);
        }
        else
        {
            answer.push_back(buf[commands[case_idx][2] - 1]);
        }
        delete[] buf;
    }
    
    return answer;
}
