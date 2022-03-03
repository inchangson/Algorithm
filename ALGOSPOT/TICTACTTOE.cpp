// tic tack toe
#include <cstdio>
#include <iostream>

using namespace std;

const int SZ = 3;

char board[SZ][SZ];
int n;

void input_data(){
	for(int r = 0; r < SZ; ++r){
		scanf("%s", &board[r]);
//		printf("[%d] : %s\n", idx, board[idx]);
	}
}

void print_data(){
	printf("\n==================\n", n);
	for(int r = 0; r < SZ; ++r){
		for(int c = 0; c < SZ; ++c)
			printf("%2c", board[r][c]);	
		printf("\n");
	}
	printf("\n");
}

int main(){
	int c;
	scanf("%d", &c);
	for(;c > 0; --c){
		input_data();
		print_data();
		
	}
	return 0;	
}
