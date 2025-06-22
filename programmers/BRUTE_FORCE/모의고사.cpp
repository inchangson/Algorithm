#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int STU_NO = 3;
const int MX_LENG = 10;
const int STU_ANS[STU_NO][MX_LENG] = {  {1, 2, 3, 4, 5, },
                                        {2, 1, 2, 3, 2, 4, 2, 5},
                                        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
const int STU_LENG[STU_NO] = {5, 8, 10};

int get_score(int stu_idx, const vector<int> & answers){
    int rslt = 0;
    for(int no = 0; no < answers.size(); ++no){
        if(STU_ANS[stu_idx][no % STU_LENG[stu_idx]] == answers[no])
            ++rslt;
    }
    return rslt;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int mx_score = -1;
    int score[STU_NO];
    for(int idx = 0; idx < STU_NO; ++idx){
        score[idx] = get_score(idx, answers);
        mx_score = max(mx_score, score[idx]);
    }
    for(int idx = 0; idx < STU_NO; ++idx){
        if(score[idx] == mx_score){
            answer.push_back(idx + 1);
        }
    }
    return answer;
}
