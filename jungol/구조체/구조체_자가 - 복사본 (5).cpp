#include <stdio.h>

typedef struct student{
	char name[20];
	int height;
}student;
int main(){
	int target_idx;
	int smallest = 987654321;
	student classroom[5];
	for(int i = 0; i < 5; ++i){
		scanf("%s %d", classroom[i].name, &classroom[i].height);
		if(smallest > classroom[i].height){
			smallest = classroom[i].height;
			target_idx = i;
		}
	}
	printf("%s %d\n", classroom[target_idx].name, classroom[target_idx].height);
	return 0;
}
