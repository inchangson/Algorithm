#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> factorSimple(int n){
	vector<int> ret;
	int sqrtn = (int)sqrt(n);
	for(int div = 2; div <= sqrtn; ++div){
		while(n % div == 0){
			n /= div;
			ret.push_back(div);
		}
	}
	if(n > 1)	ret.push_back(n);
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> ans;
	ans = factorSimple(n);
	for(int elem : ans){
		printf("%d\n", elem);
	}
	return 0;
}
