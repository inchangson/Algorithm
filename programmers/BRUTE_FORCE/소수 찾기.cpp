#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MX = 10000000;
const int CARDNUM = 10;
bool isPrime[MX];
int cardsNo[CARDNUM];
void makePrimeSet(){
    static bool isAlreadyMade = false;
    for(int n = 0; n < MX; ++n)
        isPrime[n] = true;
    isPrime[0] = isPrime[1] = false;
    
    int sqrtN = sqrt(MX);
    for(int p = 2; p <= sqrtN; ++p){
        if(isPrime[p]){
            for(int num = p * p; num < MX; num += p){
                isPrime[num] = false;
            }            
        }
    }    
    isAlreadyMade = true;
}

void makeCardsNo(const string & numbers){
    for(char elem : numbers){
        ++cardsNo[elem - '0'];
    }
}

bool isPossible(const string & number){
    int n;
    int usedCards[CARDNUM] = {0, };
    for(char elem : number){
        n = elem - '0';
        ++usedCards[n];
        if(usedCards[n] > cardsNo[n])
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    makePrimeSet();
    makeCardsNo(numbers);
    
    sort(numbers.begin(), numbers.end(), greater<int> ());
    int mxNum = stoi(numbers);
    
    for(int n = 1; n <= mxNum; ++n){
        if(isPrime[n] && isPossible(to_string(n)))
            ++answer;        
    }
    
    return answer;
}
