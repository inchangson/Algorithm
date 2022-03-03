//TRIANGLEPATH
#if 0
#include <iostream>

#define MX_SIZE 100
#define MX_N 987654321
#define MAX(x, y) ((x > y)? x: y)

using namespace std;

int map[MX_SIZE][MX_SIZE];
int cache[MX_SIZE][MX_SIZE];

int C;
int N;

void initData()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cache[i][j] = -1;
		}
	}
}

void inputData()
{
	cin >> N;
	initData();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> map[i][j];
		}
	}
}

//void printData()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

int solve(int r, int c)
{
	if (c > r)
		return -MX_N;
	if (r == N)
		return 0;
	int &ret = cache[r][c];
	if (ret == -1)
	{
		int cand1 = solve(r + 1, c);
		int cand2 = solve(r + 1, c + 1);
		ret = map[r][c] + MAX(cand1, cand2);
	}
	return ret;
}

int main()
{
	cin >> C;
	for (; C > 0; C--)
	{
		inputData();
		//printData();
		cout << solve(0, 0) << endl;
	}

	return 0;
}
#endif
