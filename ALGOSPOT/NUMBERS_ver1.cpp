//NUMB3RS - N^2 * d complexity (memoization)
#if 0
#include <iostream>
#include <string.h>
#include <algorithm>

#define _TOWNS 50
#define _DAYS 100

using namespace std;

int c;
int n;
int d;
int t;//towns for calculate prob
int p;//prison

int map[_TOWNS][_TOWNS];
int target[_TOWNS];
int counts[_TOWNS];

double memo[_TOWNS][_DAYS + 1];

void inputData()
{
	cin >> n >> d >> p;
	memset(counts, 0, sizeof(counts));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j])	counts[i]++;
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> target[i];
}

void printData()
{
	cout << "====" << endl;
	cout << "n: " << n << " ";
	cout << "d: " << d << " ";
	cout << "p: " << p << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "t: " << t << endl;
	for (int i = 0; i < t; i++)
		cout << target[i] << " ";

	//cout << "counts" << endl;
	//for (int i = 0; i < n; i++)
	//	cout << counts[i] << " ";

	cout << "\n === " << endl;
}

double FindDunnibal(int cur, int left, int target)
{
	if (left == 0)
	{
		if (target == cur) return 1;
		else    return 0;
	}

	double & ret = memo[cur][left];
	if (ret != -1) return ret;

	ret = 0;
	for (int nxt = 0; nxt < n; nxt++)
	{
		if (map[cur][nxt])
			ret += (FindDunnibal(nxt, left - 1, target) / counts[cur]);
	}
	return ret;
}

void setData()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= d; j++)
			memo[i][j] = -1;
}

int main()
{
	cin >> c;
	for (; c > 0; c--)
	{
		inputData();
		cout << fixed;
		cout.precision(10);
		for (int cand = 0; cand < t; cand++)
		{
			setData();
			cout << FindDunnibal(p, d, target[cand]) << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif
