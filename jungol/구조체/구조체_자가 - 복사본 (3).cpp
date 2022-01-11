#include <stdio.h>
#include <string.h>

typedef struct Student{
	char name[20];
	int kor, eng;
}stu;

int main(){
	stu s1, s2;
	scanf("%s %d %d", s1.name, &s1.kor, &s1.eng);
	scanf("%s %d %d", s2.name, &s2.kor, &s2.eng);
	printf("%s %d %d\n", s1.name, s1.kor, s1.eng);
	printf("%s %d %d\n", s2.name, s2.kor, s2.eng);
	
	printf("avg %d %d\n", (s1.kor + s2.kor)/2, (s2.eng + s1.eng)/2);
	
	return 0;
}
