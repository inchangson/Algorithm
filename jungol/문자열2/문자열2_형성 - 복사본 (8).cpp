#include <stdio.h>

int IsEnd(int strLeng, char * str){
	if(strLeng != 3)    return 0;
	char * end = "END";
	for(int idx = 0; idx < 4; ++idx){
		if(str[idx] != end[idx])    return 0;
	}
	return 1;
}

int main(){
	int i = 0;
	while(i++ < 20){
		char str[21];
		int strLeng;
		scanf("%s", str);

		int idx;
		for(idx = 0; str[idx] != '\0' && idx < 21; ++idx){}
		strLeng = idx;

		if(IsEnd(strLeng, str))  break;

		for(idx = strLeng - 1; idx >= 0; --idx){
			putchar(str[idx]);
		}
		printf("\n");
	}

	return 0;
}
