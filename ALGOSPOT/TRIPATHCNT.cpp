//TRIPATHCNT
#if 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Path
{
	int value;
	int cnt;
};

int h;
int tower[100][100];
Path cache[100][100];

void setData()
{
	cin >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < (i + 1); j++)
		{
			cin >> tower[i][j];
			cache[i][j].value = -1;
			cache[i][j].cnt = -1;
		}
	}
}

void printData()
{
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < (i + 1); j++)
		{
			cout << tower[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < (i + 1); j++)
		{
			cout << cache[i][j].value << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < (i + 1); j++)
		{
			cout << cache[i][j].cnt << " ";
		}
		cout << endl;
	}
	cout << endl;
}


Path getMaxPathCnt(int r, int c)
{
	Path &ret = cache[r][c];
	if (ret.value != -1) return ret;

	if (r == h - 1)
	{
		ret.value = tower[r][c];
		ret.cnt = 1;
		return ret;
	}

	Path cand1 = getMaxPathCnt(r + 1, c);
	Path cand2 = getMaxPathCnt(r + 1, c + 1);
	if (cand1.value == cand2.value)
	{
		ret = cand1;
		ret.cnt += cand2.cnt;
	}
	else if (cand1.value < cand2.value)
	{
		ret = cand2;
	}
	else
	{
		ret = cand1;
	}
	ret.value += tower[r][c];
	return ret;
}

int main()
{
	int c;
	cin >> c;
	for (; c > 0; c--)
	{
		setData();
		//printData();
		cout /*<< "ans cnt : " */ << getMaxPathCnt(0, 0).cnt << endl;
		//cout << "ans val : " << getMaxPathCnt(0, 0).value << endl;
	}
	return 0;
}

