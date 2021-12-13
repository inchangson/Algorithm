#include <iostream>

using namespace std;

constexpr int MX_N = 123456 * 2 + 1;

int primeCnt[MX_N];
int isPrime[MX_N];

void makePrimeSet(){
	isPrime[0] = isPrime[1] = primeCnt[0] = primeCnt[1] = 0;
	int cnt = 0;
	int n;
	for(n = 2; (n * n) <= MX_N; ++n){
		if(isPrime[n]){
			++cnt;
			for(int m = 2 * n; m < MX_N; m += n){
				if(m % n == 0)  isPrime[m] = 0;
			}
		}
		primeCnt[n] = cnt;
	}
	for(;n < MX_N;++n){
		if(isPrime[n])  ++cnt;
		primeCnt[n] = cnt;
	}
	
}

int main(){
	for(int &n : isPrime){
		n = 1;
	}
	makePrimeSet();
	
	int n;
	while(true){
		scanf("%d", &n);
		if(n == 0)  return 0;
		printf("%d\n", (primeCnt[2 * n] - primeCnt[n]));
	}
	return 0;
}
