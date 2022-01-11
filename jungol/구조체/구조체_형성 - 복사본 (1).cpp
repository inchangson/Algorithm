#include <stdio.h>

typedef struct member{
	char name[101];
	char num[101];
	char addr[101];
}member;

int main(){
	member m;
	scanf("%s %s %s", m.name, m.num, m.addr);
	printf("name : %s\ntel : %s\naddr : %s\n", m.name, m.num, m.addr);
	return 0;
}
