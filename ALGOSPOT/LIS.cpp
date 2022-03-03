//LIS
#if 0
#include <iostream>
#define _MX 987654321
#define _MAX(X, Y) (((X) > (Y))? (X) : (Y))

using namespace std;

int* arr;
int* cache;
int leng;

void inputData()
{
	cin >> leng;
	arr = new int[leng];
	cache = new int[leng];
	for (int i = 0; i < leng; i++)
	{
		cin >> arr[i];
		cache[i] = -1;
	}
}

void outputData()
{
	cout << leng;
	cout << endl << "output" << endl;

	for (int i = 0; i < leng; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int LIS(int idx)
{
	int &ret = cache[idx];

	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = idx + 1; i < leng; i++)
	{
		if (arr[i] <= arr[idx])
			continue;
		int cand = LIS(i) + 1;
		ret = _MAX(ret, cand);
	}
	return ret;
}

int solve()
{
	int ans = -_MX;
	for (int i = 0; i < leng; i++)
	{
		if (cache[i] != -1)
			continue;
		ans = _MAX(ans, LIS(i));
	}
	return ans;
}

int main()
{
	int C;
	cin >> C;
	for (; C > 0; C--)
	{
		inputData();
		//outputData();
		cout << solve() << endl;
		delete[] arr;
		delete[] cache;
	}
	return 0;
}
#endif
