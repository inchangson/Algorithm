//memoization
#if 0
#include <iostream>
#include <string.h>
#include <algorithm>

#define LENG 1000

using namespace std;

int leng;
int arr[LENG + 1];
int memo[LENG + 1];

int getAns(int now)
{
	int & ret = memo[now];
	if(ret != - 1) return ret;
	
	ret = arr[now];
	for(int next = now + 1; next <= leng; next++)
		if(arr[now] < arr[next])
			ret = max(ret, getAns(next) + arr[now]);
			
	return ret;
}

int main()
{
	int i;
	memset(memo, -1, sizeof(memo));
	cin >> leng;
	for(i = 0; i < leng ; i++)
		cin >> arr[i + 1];
	
	cout << getAns(0) << endl;
	
	return 0;
} 
#endif

