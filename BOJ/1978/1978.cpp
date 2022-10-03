#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(int num){
	if(num < 2)	return false;
	if(num == 2)	return true;
	if(num % 2 == 0)	return false;
	int range = (int)sqrt(num);
	for(int i = 2; i <= range ; ++i){
		if(num % i == 0)	return false;
	} 
	return true;
}

int main(){
	int n, p;
	scanf("%d", &n);
	int cnt = 0;
	for(; n > 0; --n){
		scanf("%d", &p);
		if(is_prime(p))	++cnt;
	}
	printf("%d", cnt);
	return 0;
}
