#include <iostream>
#include <string.h>
#define LENG 1000
using namespace std;

int arr[LENG + 1];
int memo[LENG + 1];

int main()
{
	int leng, i, j, ans = 0;
	cin >> leng;
	
	for(i = 1; i <= leng; i++)
	{
		cin >> arr[i];
		for(j = 0; j < i; j++)
			if(arr[i] > arr[j]
			&& memo[j] + 1 > memo[i])
			memo[i] = memo[j] + 1;
		ans = (memo[i] > ans) ? memo[i] : ans;
	}
	
	cout << ans << endl;
	return 0;
}
