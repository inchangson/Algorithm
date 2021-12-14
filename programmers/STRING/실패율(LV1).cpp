#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Stage{
    int num;
    int numer;
    int denom;
};

bool stageCmp(Stage & s1, Stage & s2){
    /*double d1 = (double)s1.numer/ s1.denom;
    double d2 = (double)s2.numer/ s2.denom;

    if(d1 == d2) return s1.num < s2.num;
    else    return d1 > d2;*/

    if(s1.numer * s2.denom == s1.denom * s2.numer){
        return s1.num < s2.num;
    }
    return s1.numer * s2.denom > s1.denom * s2.numer;
}

vector<int> solution(int N, vector<int> players) {
    vector<int> answer;
    vector<Stage> stages;

    sort(players.begin(), players.end());

    int stageIdx = 0;
    int totalCnt = players.size();
    for(int sNum = 1; sNum <= N; ++sNum){
        int cnt = 0;
        while(stageIdx < players.size() &&
              sNum == players[stageIdx]){
            ++stageIdx;
            ++cnt;
        }
        totalCnt = totalCnt <= 0 ? 1 : totalCnt;
        stages.push_back({sNum, cnt, totalCnt});
        totalCnt -= cnt;
    }

    sort(stages.begin(), stages.end(), stageCmp);

    for(Stage s : stages){
        //printf("%d %d %d %lf\n", s.num, s.numer, s.denom, (double)s.numer/s.denom);
        answer.push_back(s.num);
    }

    return answer;
}
