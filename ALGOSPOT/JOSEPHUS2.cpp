#include <stdio.h>
#include <stdlib.h>
#define MX_N 1000
#define MX_K 1000

typedef struct person{
	int num;
	struct person* next;
}person;

person* gHead;
person* gTail;

void soldierListPush(int num){
	person* soldier = (person*)malloc(sizeof(person));
	soldier->num = num;
	soldier->next = gHead;
	
	if(gHead == NULL){
		gHead = soldier;
		gTail = soldier;
	}
	else{
		gTail->next = soldier;
		gTail = soldier;
	}
}

void makeSoldiersList(int n){
	gHead = NULL;
	gTail = NULL;
	for(int soldier = 1; soldier <= n; ++soldier){
		soldierListPush(soldier);
	}
}

void printSoldiers(){
	if(gHead == NULL)	return;
	
	person* now = gHead;
	person* before = NULL;
	int idx = 0;
	while(now != gHead || before != gTail){
		printf("%d ", now->num);
		before = now;
		now = now->next;
	}
	printf("\n");
}

int soldierListRemoveAt(int num){
	if(gHead == NULL)	return 0;
	
	person* before = NULL;
	person* now = gHead;
	
	while(now != gHead || before != gTail){
		if(now->num == num){
			if(now == gHead && now == gTail){
				gHead = gTail = NULL;
			}
			else if(now == gHead && now != gTail){
				gHead = now->next;
				gTail->next = gHead;
			}
			else if(now != gHead && now == gTail){
				gTail = before;	
				gTail->next = gHead;
			}
			else{
				before->next = now->next;			
			}			
			free(now);
			return 1;
		}
		before = now;
		now = now->next;
	}
	return -1;
}

void freeAll(){
	if(gHead == NULL)	return;	
	person* now = gHead;
	person* next = gHead->next;
	while(now){
		next = now->next;
		if(soldierListRemoveAt(now->num) != 1)	break;
		now = next;
	}	
}

person* getNextTurn(person* now, int steps){
	person* next = now;
	while(steps){
		next = next->next;
		--steps;
	}
	return next;
}

void killSoldiers(int cnt, int k){
	person* now = gHead; 
	person* next = NULL;
	while(cnt > 2){
		next = getNextTurn(now, k);
		soldierListRemoveAt(now->num);
		now = next;
		--cnt;
	}
}


int main(){
	int c, n, k;
	scanf("%d", &c);
	for(int idx = 1;idx <= c; ++idx){
		scanf("%d %d", &n, &k);
		makeSoldiersList(n);
		killSoldiers(n, k);
		printf("%d %d\n", gHead->num, gTail->num);
//		printSoldiers();
		freeAll();
	}
	return 0;
}
