//algospot # POTION
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int K = 1000;

int n;
int r[K], p[K];
int bottle;

int r_gcd;

void init_data(){
	n = 0;
	memset(r, 0, sizeof(r));
	memset(r, 0, sizeof(p));
}

void input_data(){
	int idx;
	scanf("%d", &n);
	for(idx = 0; idx < n; ++idx){
		scanf("%d", &r[idx]);
	}
	for(idx = 0; idx < n; ++idx){
		scanf("%d", &p[idx]);
	}	
}

void print_data(){
	int idx;
	printf("%d\n", n);
	for(idx = 0; idx < n; ++idx){
		printf("%d ", r[idx]);
	}
	printf("\n");
	for(idx = 0; idx < n; ++idx){
		printf("%d ", p[idx]);
	}	
	printf("\n");
}

int get_gcd(int num1, int num2){
	if(num1 < num2){
		int tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	int mod;
	while(num2 > 0){
		mod = num1 % num2;
		num1 = num2;
		num2 = mod;	
	}
	return num1;
}

void set_r_gcd(){
	r_gcd = r[0];
	for(int potion = 1; potion < n; ++potion){
		r_gcd = get_gcd(r_gcd, r[potion]);
	}
}

int get_mistaken_potion(){
	int ret_idx = 0;
	double ratio = 0.0;
	for(int potion = 0; potion < n; ++potion){
		if(p[potion] < r[potion]) continue;
		if(ratio < p[potion] / r[potion]){
			ratio = p[potion] / r[potion];
			ret_idx = potion;
		}
	}
	return ret_idx;
}

int get_bottle_no(int potion){
	int tmp = r[potion] / r_gcd;
	int ret= p[potion];
	while(ret % tmp){
		++ret;
	}
	return ret / tmp;
}

void print_ans(){
	for(int potion = 0; potion < n ; ++potion){
		printf("%d ", bottle * r[potion] / r_gcd - p[potion]);
	}
	printf("\n");
}

void solve(){
	set_r_gcd();
	int mistaken = get_mistaken_potion();
	bottle = get_bottle_no(mistaken);
	print_ans();
}

int main(){
	int c;
	scanf("%d", &c);
	for(; c > 0; --c){
		//init_data();
		input_data();
		//print_data();
		solve();
	}
	return 0;
}
