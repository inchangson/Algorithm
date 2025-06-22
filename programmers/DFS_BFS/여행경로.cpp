#include <string>
#include <vector>
#include <map>

using namespace std;

//int counts;
int leng;
map<string, int> city_list;
bool ticket_list[10000][10000];

vector<string> buffer;
vector<string> decided;

void input_answer()
{    
    if(decided.size() > buffer.size())
    {
        decided = buffer;
        return;
    }
    if(decided.size() < buffer.size())
    {
        return;
    }
    for(int i = 0; i < decided.size(); ++i)
    {
        if(decided[i] > buffer[i])
        {
            decided = buffer;
            return;   
        }
        if(decided[i] < buffer[i])
        {
            return;
        }            
    }
}

void solve(string city, int cnt, vector<vector<string>> & tickets)
{
    if(cnt == leng)
    {
        buffer.push_back(city);
        input_answer();
        buffer.pop_back();
        return;
    }
    for(int i = 0; i < leng; ++i)
    {
        if(tickets[i][0] == city)
        {
            tickets[i][0] = "NA";
            buffer.push_back(city);
            solve(tickets[i][1], cnt + 1, tickets);
            buffer.pop_back();
            tickets[i][0] = city;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    leng = tickets.size();
    decided.resize(10001);
    solve("ICN", 0, tickets);
    answer = decided;
    return answer;
}
