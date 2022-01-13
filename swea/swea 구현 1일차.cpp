#include <stdio.h>
#include <string.h> 

int main(){
	int T, leng;
	char curChar;
	int curN;
	char inputData[101];
	char ans[401] = {'\0'};
	char hexaTable[16][5] = {"0000", "0001", "0010", "0011",
							 "0100", "0101", "0110", "0111",
							 "1000", "1001", "1010", "1011",
							 "1100", "1101", "1110", "1111"};
							 
	scanf("%d", &T);
	
	for(int t = 1; t <= T; ++t){
		printf("#%d ", t);
		scanf("%d %s", &leng, inputData);
		
		for(int idxIn = 0; idxIn < leng; ++idxIn){
			curChar = inputData[idxIn];
			if('0' <= curChar && curChar <= '9'){
				curN = curChar - '0';
			}
			else{
				curN = curChar - 'A' + 10;
			}
			//printf("%d -> %d : %s\n", idxIn, curN, hexaTable[curN]);
			strcat(ans, hexaTable[curN]);	
		}
		printf("%s\n", ans);
	}
	return 0;
}
