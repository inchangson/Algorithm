#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); 
    
    int lightest = 0;
    int weight;
    for(int heaviest = people.size() - 1; heaviest >= lightest && heaviest >= 0; --heaviest){
       // printf("%d %d\n", heaviest, lightest);
        if(heaviest == lightest){
            ++answer;
            break;
        }
        weight = people[heaviest] + people[lightest];
        if(weight > limit){
            ++answer;       
        }else{
            ++answer;
            ++lightest;
        }
    }
    return answer;
}