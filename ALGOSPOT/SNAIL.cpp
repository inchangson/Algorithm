//SNAIL
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int n;//depth
int m;//range
double rain = 0.75;//probability to rain
double** cache;

void setData()
{
	cin >> n >> m;
	cache = new double*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		cache[i] = new double[m + 1];
		for (int j = 0; j < m + 1; j++)
			cache[i][j] = -1;
	}
}

void initData()
{
	for (int i = 0; i < n + 1; i++)
		delete[] cache[i];
	delete[] cache;
}

double climb(int left, int days)
{
	if (left <= 0)
		return 1;
	if (days == 0)
		return 0;

	double &ret = cache[left][days];
	if (ret != -1) return ret;

	ret = rain * climb(left - 2, days - 1)
		+ (1 - rain) * climb(left - 1, days - 1);

	return ret;
}

int main()
{
	int c;
	cin >> c;
	cout.setf(ios::showpoint);
	cout.precision(10);
	for (; c > 0; c--)
	{
		setData();
		cout << climb(n, m) << endl;
		initData();
	}
	return 0;
}
#endif
