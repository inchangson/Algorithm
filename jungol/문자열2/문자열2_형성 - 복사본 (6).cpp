#include <stdio.h>

int main(){
	
	const int MX = 100;
	
	char str1[MX];
	char str2[MX];
	
	int n;
	
	scanf("%s %s %d", str1, str2, &n);
	printf("%s%s\n", str1, str2);
	
	char ch;
	int isStr1End = 0;
	for(int i = 0; str2[i] != '\0'; ++i){
		if(!isStr1End && str1[i] == '\0') isStr1End = 1;
		if(i >= n || isStr1End) 	ch = str2[i];
		else        				ch = str1[i];
		putchar(ch);
	}
	printf("\n");
	return 0;
}
