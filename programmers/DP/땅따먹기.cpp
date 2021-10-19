#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node{
    int val;
    int pos;
    bool operator < (const node& n) const{
        return val < n.val;
    }
    bool operator > (const node& n) const{
        return val > n.val;
    }
}node;

int end_row;
const int FIRST = 0;
const int SECOND = 1;

int get_max_score(int row, int col, const vector<vector<int>> & land){
    if(row == end_row)  return 0;

    vector<node> next_node;
    int next_row = row + 1;
    for(int idx = 0; idx < land[next_row].size(); ++idx){
        if(idx == col)  continue;
        node tmp;
        tmp.val = land[next_row][idx];
        tmp.pos = idx;
        next_node.push_back(tmp);
    }
    sort(next_node.begin(), next_node.end());
   
    if(row < 0){
        return max(get_max_score(row + 1, next_node[FIRST].pos, land),
                  get_max_score(row + 1, next_node[SECOND].pos, land));
    }
    return max( get_max_score(row + 1, next_node[FIRST].pos, land) + land[row][col],
                get_max_score(row + 1, next_node[SECOND].pos, land) + land[row][col]);
}

int solution(vector<vector<int> > land)
{
    end_row = land.size();
    int answer = get_max_score(-1, -1, land);
    return answer;
}

int main(){
	vector<vector<int>> input_data;
	vector<int> row1 = {1, 2, 3, 5};
	vector<int> row2 = {5,6,7,8};
	vector<int> row3 = {4,3,2,1};
	input_data.push_back((row1));
	input_data.push_back((row2));
	input_data.push_back((row3));
	solution(input_data);
	return 0;
}
