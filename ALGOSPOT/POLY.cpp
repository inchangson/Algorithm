//POLY
#if 0
#include <iostream>
#include <algorithm>
#include <string.h>
#define MOD 10000000

using namespace std;

int n;
int cache[101][101];

int makePoly(int spare, int now)
{
	if (spare <= 0)
		return 1;

	int & ret = cache[spare][now];
	if (ret != -1)	return ret;

	ret = 0;
	int left, cnt, add;
	for (int next = 1; next <= spare; next++)
	{
		left = spare - next;
		cnt = next + now - 1;
		add = (cnt * makePoly(left, next)) % MOD;

		ret = (add + ret) % MOD;
	}
	return ret;
}

int main()
{
	int c;
	cin >> c;
	for (; c > 0; c--)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		int ans = 0;
		for (int i = 1; i <= n; i++) ans = (ans + makePoly(n - i, i)) % MOD;
		cout << ans << endl;
	}
	return 0;
}
#endif
