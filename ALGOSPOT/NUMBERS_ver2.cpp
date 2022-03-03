//NUMB3RS - N * d complexity (tabulation)
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
		for (int k = 0; k <= d; k++)
			memo[i][k] = -1;
	}
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> target[i];
}

double find_dunnibal(int now, int days)
{
	if (days == 0)	return (now == p);
	double & ret = memo[now][days];
	if (ret != -1) return ret;
	ret = 0;
	for (int before = 0; before < n; before++)
		if (map[before][now])
			ret += find_dunnibal(before, days - 1) / counts[before];	
	return ret;
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
			cout << find_dunnibal(target[cand], d) << " ";
		cout << endl;
	}
	return 0;
}
#endif
