#include <stdio.h>

constexpr int MaxN = 100;

int nBowls;
int targetGap;
int bowls[MaxN][MaxN];
int bufBowls[MaxN][MaxN];
int lastRow;

void initData(){
	//global variable initailization
}

void inputData(){
	scanf("%d %d", &nBowls, &targetGap);
	lastRow = nBowls - 1;
	for(int idx = 0; idx < nBowls; ++idx){
		scanf("%d", &bowls[lastRow][idx]);
	}
}

void printData(){
	printf("%d %d\n", nBowls, targetGap);
	for(int idx = 0; idx < nBowls; ++idx){
		printf("%d", bowls[lastRow][idx]);
	}
	printf("\n");
}

void printStatus(){
	printf("\n======= printStatus Start =========\n");
	for(int r = lastRow - 10; r <= lastRow; ++r){
		for(int c = 0; c < nBowls; ++c){
			if(bowls[r][c])
				printf("%2d ", bowls[r][c]);
			else
				printf("   ");
		}
		printf("\n");
	}
	printf("\n======= printStatus End =========\n");
}

void stackBowls(int idx, int cnt){
	
	printf("\n======= stackBowls Start =========\n");
	int preCnt = cnt - 1;
	for(int r = lastRow; r >= lastRow - preCnt ;--r){
		for(int c = idx; c < idx + cnt ; ++c){
			bowls[r - 1][c + cnt] = bowls[r][c];
			bowls[r][c] = 0;
		}
	}
	printf("idx %d cnt %d\n", idx, cnt);
	printf("\n======= stackBowls End =========\n");
}

void rollBowls(int cur, int left){
	printf("\n======= rollBowls Start =========\n");
	if(left < cur){
		return;
	}
	printf("cur %d left %d curIdx %d\n", cur, left, curIdx);
	//stackBowls(curIdx, cur);
	
	int width = 
	int curIdx = nBowls - 1 - left;
	
	printStatus();
	rollBowls(cur + 1, left - cur);
	printf("\n======= rollBowls End =========\n");
}

int getAns(){
	rollBowls(1, nBowls - 1);
	return 0;
}

int main(){
	initData();
	inputData();
	//printData();
	printf("%d\n", getAns());
	
	return 0;
}
