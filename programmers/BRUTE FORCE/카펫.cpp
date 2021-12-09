#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int b = brown / 2 - 2;
    int c = sqrt(b * b - 4 * yellow);
    int width = (b + c) / 2 + 2;
    int height = (b - c) / 2 + 2;
    answer.push_back(width);
    answer.push_back(height);
    return answer;
}
