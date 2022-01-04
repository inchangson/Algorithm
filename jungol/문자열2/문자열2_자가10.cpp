#include <stdio.h>

int main(){
	int idx;
	char str[21];
	
	int numer = 0;
	int denom = 1;
	int dotCnt = 0;
	
	scanf("%s", str);
	
	for(idx = 0; str[idx] != '\0'; ++idx){
		if(dotCnt){
			if(str[idx] < '0' || str[idx] > '9')    break;
			
			numer = numer * 10 + (str[idx] - '0');
			denom *= 10;

			continue;
		}

		if(str[idx] == '.'){
			dotCnt++;
			continue;
		}

		if(str[idx] < '0' || str[idx] > '9')    break;
		numer = numer * 10 + (str[idx] - '0');
	}
	//printf("numer %d denom %d\n", numer, denom);
	int numInt = numer / denom;
	
	printf("%d\n", numInt * 2);
	
	double numDouble = (double)numer/ denom;
	
	printf("%.2lf\n", numDouble);
	
	return 0;
}
