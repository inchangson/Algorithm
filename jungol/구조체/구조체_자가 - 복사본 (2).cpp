#include <stdio.h>
#include <string.h>
typedef struct student{
	char school[21];
	int  grade;
}student;

int main(){
	student s1, s2;
	strcpy(s1.school, "Jejuelementary");
	s1.grade = 6;
	scanf("%s %d", &s2.school, &s2.grade);
	printf("%d grade in %s School\n", s1.grade, s1.school);
	printf("%d grade in %s School\n", s2.grade, s2.school);
	return 0;
}
