#include <stdio.h>

typedef struct person{
	int h;
	double w;
}person;
int main(){
	person mom, dad;
	scanf("%d %lf", &mom.h, &mom.w );
	scanf("%d %lf", &dad.h, &dad.w );
	printf("height : %dcm\nweight : %.1lfkg\n", 5 + (mom.h + dad.h)/2, 
	(mom.w + dad.w)/2.0 - 4.5);
	return 0;
}
