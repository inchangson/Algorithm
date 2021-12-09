#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int target_num;
int leng;
int cnt;

void make_number(int idx, int buf, const vector<int> & numbers)
{
    if(idx == leng)
    {
        if(buf == target_num)
        {
            ++cnt;
        }
        return;
    }
    
    make_number(idx + 1, buf + numbers[idx], numbers);
    make_number(idx + 1, buf - numbers[idx], numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    target_num = target;
    leng = numbers.size();
    
    make_number(0, 0, numbers);
    answer = cnt;
    return answer;
}
