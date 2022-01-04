#include <stdio.h>

int convertToInt(char * str){
	int num = 0;
	for(int idx = 0; idx < 101; ++idx){
		if(str[idx] < '0' || str[idx] > '9')    break;
		num = num * 10 + str[idx] - '0';
	}
	return num;
}

int main(){

	char num1[101];
	char num2[101];
	
	scanf("%s %s", num1, num2);

	int n1 = convertToInt(num1);
	int n2 = convertToInt(num2);
	
	//printf("n1 %d n2 %d\n", n1, n2);
	printf("%d\n", n1 * n2);
	
	
	return 0;
}
