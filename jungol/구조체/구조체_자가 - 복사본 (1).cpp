#include <stdio.h>

typedef struct student{
	char name[20];
	char school[20];
	int grade;
}stu;

int main(){

	stu s;
	scanf("%s %s %d", &s.name, &s.school, &s.grade);

	printf("Name : %s\n", s.name);
	printf("School : %s\n", s.school);
	printf("Grade : %d\n", s.grade);

	return 0;
}
