#include <stdio.h>
#include <string.h>
typedef struct member{
	char name[101];
	char num[101];
	char addr[101];
}member;

int main(){
	member m, school[3];
	strcpy(m.name, "zzzzzzzzzzzzzzz");
	for(int i = 0; i < 3; ++i){
		scanf("%s %s %s", school[i].name, school[i].num, school[i].addr);
		if(strcmp(school[i].name, m.name) < 0){
			m = school[i];
		}
	}
	printf("name : %s\ntel : %s\naddr : %s\n", m.name, m.num, m.addr);
	return 0;
}
