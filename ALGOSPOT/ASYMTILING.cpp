//ASYMTILING
#if 0
#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int n;
int memo[101];

void setData()
{
	cin >> n;
	for (int i = 0; i <= n; ++i)
		memo[i] = -1;
}

int tiling(int idx)
{
	if (idx <= 1)
		return 1;

	int& ret = memo[idx];
	if (ret != -1) return ret;

	ret = (tiling(idx - 1) + tiling(idx - 2)) % MOD;
	return ret;
}

int getAns()
{
	if (n % 2)
	{
		return (tiling(n) - tiling(n / 2) + MOD) % MOD;
	}
	else
	{
		int tmp = (tiling(n / 2) + tiling(n / 2 - 1)) % MOD;
		return (tiling(n) - tmp + MOD) % MOD;
	}
}

int main()
{
	int c;
	cin >> c;
	for (; c > 0; c--)
	{
		setData();
		cout << getAns() << endl;
	}
	return 0;
}
#endif
