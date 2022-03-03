//PI
#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

#define INT32MX 100000//0X7FFFFFFF 

using namespace std;

string pi_num;
int* cache;
int strleng;

int score(int low, int high)
{
	int idx;
	int scores[6] = { 1,2,2,4,5,10 };
	int diff = pi_num[low + 1] - pi_num[low];

	int odd = (low % 2) ? pi_num[low] : pi_num[low + 1];
	int even = (low % 2) ? pi_num[low + 1] : pi_num[low];

	for (idx = low; idx <= high; idx++)
	{
		//case 1
		if (pi_num[idx] != pi_num[low])
		{
			scores[0] = 0;
		}

		//case 2 a
		if (idx != high && (pi_num[idx] != (pi_num[idx + 1] + 1)))
		{
			scores[1] = 0;
		}

		//case 2 b
		if (idx != high && (pi_num[idx] != (pi_num[idx + 1] - 1)))
		{
			scores[2] = 0;
		}

		//case 3 
		if (idx % 2)
		{
			if (pi_num[idx] != odd)
				scores[3] = 0;
		}
		else
		{
			if (pi_num[idx] != even)
				scores[3] = 0;
		}

		//case 4
		if (idx != high && ((pi_num[idx + 1] - pi_num[idx]) != diff))
		{
			scores[4] = 0;
		}
	}

	for (idx = 0; idx < 6; idx++)
	{
		if (scores[idx])
			return scores[idx];
	}
}

int solve(int cur_idx)
{
	//base case
	if (cur_idx == strleng)
		return 0;

	//dp
	int &ret = cache[cur_idx];
	if (ret != -1)
		return ret;

	ret = INT32MX;

	for (int leng = 2; leng < 5; leng++)
	{
		if (cur_idx + leng < strleng)
			ret = min(ret,
				solve(cur_idx + leng + 1)
				+ score(cur_idx, cur_idx + leng));
	}

	return ret;
}

int main()
{
	int c;
	cin >> c;
	for (; c > 0; c--)
	{
		cin >> pi_num;
		strleng = pi_num.size();
		cache = new int[strleng];
		//memset(cache, -1, sizeof(cache));
		for (int i = 0; i < strleng; i++)
			cache[i] = -1;
		cout << solve(0) << endl;
		//cout<< "score: " << score(0, pi_num.size() - 1) << endl;
		delete[] cache;
	}
	return 0;
}
#endif
