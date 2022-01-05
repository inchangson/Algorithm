#include <stdio.h>

int main(){
	int n1;
	double n2;
	char str[31];
	char rslt[101];
	int len;
	
	scanf("%d %lf %s", &n1, &n2, str);
	len = sprintf(rslt, "%d%.3lf%s", n1, n2, str);
	for(int idx = 0; idx < len; ++idx){
		printf("%c", rslt[idx]);
		if(idx == (len - 1) / 2)  printf("\n");
	}
	
	return 0;
}
