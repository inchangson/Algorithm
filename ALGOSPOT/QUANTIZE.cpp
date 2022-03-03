//QUANTIZE
#if 0
#include <iostream>
#include <algorithm>
#include <cmath>

#define _MX 987654321

using namespace std;

int n;
int s;

int* numbers;
int** cache;
int** preSum;

void set_data()
{
	//data input
	cin >> n >> s;
	//memory allocation
	numbers = new int[n];
	cache = new int*[n];
	preSum = new int*[n];
	//data input
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];

		//cache initialization
		cache[i] = new int[s + 1];
		for (int j = 0; j < s + 1; j++)
			cache[i][j] = -1;
	}
	sort(numbers, numbers + n);

	//set preSum data
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		preSum[i] = new int[2];
		sum1 += numbers[i];
		sum2 += numbers[i] * numbers[i];
		preSum[i][0] = sum1;
		preSum[i][1] = sum2;
	}
}

void delete_data()
{
	for (int i = 0; i < n; i++)
	{
		delete[] cache[i];
		delete[] preSum[i];
	}

	delete[] numbers;
	delete[] cache;
	delete[] preSum;
}

int get_score(int lo, int hi)
{
	int leng = hi - lo + 1;
	int ceff1 = (lo == 0) ? preSum[hi][0]
		: preSum[hi][0] - preSum[lo - 1][0];
	int ceff2 = (lo == 0) ? preSum[hi][1]
		: preSum[hi][1] - preSum[lo - 1][1];
	int mean = int(0.5 + (double)ceff1 / leng);

	return leng * mean * mean - 2 * ceff1 * mean + ceff2;
}

int quantize(int from, int parts)
{
	if (from == n)
		return 0;

	if (parts == 0)
		return _MX;

	int &ret = cache[from][parts];
	if (ret != -1)
		return ret;

	ret = _MX;
	for (int leng = 1; leng <= n - from; leng++)
	{
		ret = min(ret, quantize(from + leng, parts - 1)
			+ get_score(from, from + leng - 1));
	}
	return ret;
}

int main()
{
	int c;
	cin >> c;
	for (; c > 0; c--)
	{
		set_data();
		cout << quantize(0, s) << endl;
		delete_data();
	}
	return 0;
}
#endif
