#include <vector>

using namespace std;

constexpr int DIR_CNT = 4;
constexpr int DIR[DIR_CNT][2] = {{1, 0}, {0, 1}, {-1 , 0}, {0, -1}};

int mxR, mxC;

int getAreaSize(int r, int c, int color, vector<vector<int>> & picture){
    int ret = 1;
    int nr, nc;
    picture[r][c] = 0;
    for(int idx = 0; idx < DIR_CNT; ++idx){
        nr = r + DIR[idx][0];
        nc = c + DIR[idx][1];
        if(nr < 0 || nr >= mxR || nc < 0 || nc >= mxC)  continue;
        if(picture[nr][nc] != color)    continue;
        ret += getAreaSize(nr, nc, color, picture);
    }
    return ret;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int areaCnt = 0;
    int maxAreaSize = 0;

    int r, c;
    int areaSize;

    mxR = n;
    mxC = m;
    for(r = 0; r < mxR; ++r){
        for(c = 0; c < mxC; ++c){
            if(picture[r][c] == 0)  continue;
            areaSize = getAreaSize(r, c, picture[r][c], picture);
            if(areaSize > maxAreaSize){
                maxAreaSize = areaSize;
            }
            areaCnt++;
        }
    }

    vector<int> answer(2);
    answer[0] = areaCnt;
    answer[1] = maxAreaSize;

    return answer;
}
