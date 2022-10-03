#include <stdio.h>
#include <algorithm>

using namespace std;

const int MX_N = 100000;
const int MX_M = MX_N;

typedef struct Order{
	int s, e, k;//start, end, k(mount)
}Order;

int N;
int M;
int ground[MX_N + 1];
int preSum[MX_N + 1];
Order orders[MX_M + 1];


void inputData(){
	int idx;
	scanf("%d %d", &N, &M);
	
	scanf("%d", &ground[0]);
	for(idx = 1; idx < N; ++idx){
		scanf("%d", &ground[idx]);
		preSum[idx] = 0;
	}
	for(idx = 0; idx < M; ++idx){
		scanf("%d %d %d", &orders[idx].s, &orders[idx].e, &orders[idx].k);
	}
}

void printData(){
	int idx;
	printf("%d %d\n", N, M);
	for(idx = 0; idx < N; ++idx){
		printf("%d ", ground[idx]);
	}
	printf("\n");
	for(idx = 0; idx < M; ++idx){
		printf("%d %d %d\n", orders[idx].s, orders[idx].e, orders[idx].k);
	}
}

void calculateAmount(){
	int s, e, k, idx1, idx2;	
	for(idx1 = 0; idx1 < M; ++idx1){
		s = orders[idx1].s - 1;
		e = orders[idx1].e - 1;
		k = orders[idx1].k;
		preSum[s] += k;
		preSum[e + 1] -= k;
	}
}

void doProcess(){
	for(int idx1 = 1; idx1 < N; ++idx1){
		preSum[idx1] = preSum[idx1] + preSum[idx1 - 1];
	}
	for(int idx = 0; idx < N; ++idx){
		//preSum[idx1] = preSum[idx1] + preSum[idx1 - 1];
		ground[idx] += preSum[idx];
	}
}

void solve(){
	calculateAmount();
	doProcess();
}

void printGround(){
	for(int idx = 0; idx < N; ++idx){
		printf("%d ", ground[idx]);
	}	
}

int main(){
	inputData();
	//printData();	
	solve();	
	printGround();
	return 0;
}
