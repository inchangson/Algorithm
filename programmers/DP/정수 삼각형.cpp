#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int MX = 500;

int end_row;
int memo[MX][MX];

int get_max_sum(int row, int col, const vector<vector<int>> & triangle){
    if(row == end_row){
        return 0;
    }
    int & rslt = memo[row][col];
    if(rslt != -1)  return rslt;
    int now = triangle[row][col];
    //max case : 5,000,000
    rslt = max(now + get_max_sum(row + 1, col, triangle), now + get_max_sum(row + 1, col + 1, triangle));
    return rslt;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    memset(memo, -1, sizeof(memo));
    end_row = triangle.size();
    answer = get_max_sum(0, 0, triangle);
    return answer;
}