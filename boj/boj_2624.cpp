// 동전바꿔주기

#include <iostream>
#include <algorithm>

using namespace std;

struct Coin{
	int p;
	int n;
};
constexpr int MX_T = 10000;
constexpr int MX_K = 100;
constexpr int EMPTY = -1;

int T;
int k;
int memo[MX_K][MX_T + 1];
Coin coins[MX_K];

void initData(){
	T = k = 0;
	for(int idxK = 0; idxK < MX_K; ++idxK){
		for(int idxT = 0; idxT < (MX_T + 1); ++idxT)
			memo[idxK][idxT] = -1;
	}
	for(Coin & coin : coins){
      coin.p = coin.n = 0;
	}
}

void inputData(){
	scanf("%d", &T);
	scanf("%d", &k);
	for(int idx = 0; idx < k; ++idx){
		scanf("%d %d", &(coins[idx].p), &(coins[idx].n));
	}
}

void printData(){
	printf("%d\n", T);
	printf("%d\n", k);
	for(int idx = 0; idx < k; ++idx){
		printf("%d %d\n", coins[idx].p, coins[idx].n);
	}
}

int makePrice(int idx, int target){
	if(target == 0)    return 1;
	if(target < 0)  	return 0;
	if(idx == k)        return 0;
	
	int & ret = memo[idx][target];
	if(ret != EMPTY)    return ret;

	ret = 0;
	for(int coinNum = 0; coinNum <= coins[idx].n; ++coinNum){
		ret += makePrice(idx + 1, target - (coinNum * coins[idx].p));
	}
	return ret;
}

int main(){
	initData();
	inputData();
	//printData();
	printf("%d\n", makePrice(0, T));
	return 0;
}
