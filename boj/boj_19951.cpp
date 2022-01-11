#include <stdio.h>
#include <algorithm>

using namespace std;

const int MX_N = 100000;
const int MX_M = MX_N;

typedef struct Order{
	int s, e, k;
}Order;

int N;
int M;
int preSum[MX_N];
int ground[MX_N];
Order orders[MX_M];

void inputData(){
	int idx;
	scanf("%d %d", &N, &M);
	
	scanf("%d", &ground[0]);
	preSum[0] = ground[0];
	for(idx = 1; idx < N; ++idx){
		scanf("%d", &ground[idx]);
		preSum[idx] = preSum[idx - 1] + ground[idx];
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
	
	for(idx = 0; idx < N; ++idx){
		printf("%d ", preSum[idx]);
	}
	printf("\n");
	for(idx = 0; idx < M; ++idx){
		printf("%d %d %d\n", orders[idx].s, orders[idx].e, orders[idx].k);
	}
}

void doProcess(){
	int s, e, k, idx1, idx2;
	for(idx1 = 0; idx1 < M; ++idx1){
		s = orders[idx1].s - 1;
		e = orders[idx1].e - 1;
		k = orders[idx1].k;
		for(idx2 = s; idx2 <= e; ++idx2){
			ground[idx2] += k;
		}
	}
}

int main(){
	inputData();
	printData();
	
	doProcess();	
	
	for(int idx = 0; idx < N; ++idx){
		printf("%d ", ground[idx]);
	}
	return 0;
}
