//TILING2
#if 0
#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int n;
int* cache;

int solve(int cur_idx)
{
	////ver 1
	//if (cur_idx == n)
	//	return 1;
	//if (cur_idx > n)
	//	return 0;

	//int & ret = cache[cur_idx];
	//if (ret != -1)
	//	return ret;

	//ret = 0;
	//ret += solve(cur_idx + 1);
	//ret += solve(cur_idx + 2);

	//ret %= MOD;
	//return ret;


	//ver2: optimized version
	if (cur_idx >= n - 1) return 1;
	int & ret = cache[cur_idx];
	if (ret != -1) return ret;
	ret = (solve(cur_idx + 1) + solve(cur_idx + 2)) % MOD;
	return ret;
}

// answer on the jongman book
int tiling(int width)
{
	if (width <= 1) return 1;
	int &ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

int main()
{
	int c;
	cin >> c;
	for (; c > 0; c--)
	{
		cin >> n;
		cache = new int[n];
		for (int i = 0; i < n; i++)
			cache[i] = -1;
		cout << solve(0) << endl;
		delete[] cache;
	}
	return 0;
}
#endif
