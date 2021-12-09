#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const int & num1, const int & num2){
    string str1 = to_string(num1);
    string str2 = to_string(num2);
    return str1 + str2 > str2 + str1;
}

void get_answer(string & ans, const vector<int> & numbers){
    for(int elem : numbers){
        ans += to_string(elem);
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    if(!numbers[0])   return "0";
    get_answer(answer, numbers);
    return answer;
}
