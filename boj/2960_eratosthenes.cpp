#include <iostream>
using namespace std;
int n, k, ans, is_prime[1001];
int main(){
	cin >> n >> k;
	for(int p = 2; p <= n ; ++p)
		if(!is_prime[p])
			for(int target = p; target <= n; target += p)
				if(!is_prime[target]){
					is_prime[target] = true;
					if(--k == 0) ans = target;
				}
	cout << ans << endl;
	return 0;
}
