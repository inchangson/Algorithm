#include <stdio.h>
#include <string.h>

int main(){
	char str1[100], str2[100];
	int n, idx;
	int isStr2Done = 0;

	scanf("%s %s %d", str1, str2, &n);
	sprintf(str1, "%s%s", str1, str2);
	
	printf("%s\n", str1);
	
	for(idx = 0; idx < n; ++idx){
		printf("%c", str1[idx]);
	}
	
	if(strlen(str2) < n)    return 0;
	
	while(str2[idx] != '\0'){
		printf("%c", str2[idx++]);
	}
	printf("\n");
	
	return 0;
}
