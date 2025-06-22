#include <string>
#include <vector>
#include <set>
#include <algorithm>

#define MAX 987654321
using namespace std;

string target_word;
set<string> visited;
set<string>::iterator iter;

bool check_condition(string str1, string str2)
{
    int cnt = 0;
    for(int idx = 0; idx < str1.size(); ++idx)
    {
        if(str1[idx] != str2[idx])
            ++cnt;
    }
    if(cnt > 1)
        return false;
    else
        return true;
}

int make_word(string now, const vector<string> words)
{
    if(now == target_word)
        return 0;
    int ret = MAX;
    visited.insert(now);
    for(string next : words)
    {
        iter = visited.find(next);
        if(iter != visited.end())
            continue;
        if(check_condition(now, next))
            ret = min(ret, make_word(next, words) + 1);
    }
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    for(string word : words)
    {
        if(target == word)
        {
            target_word = target;
            answer = make_word(begin, words);
        }
    }
    return answer;
}
