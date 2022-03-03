#include <iostream>
#include <stdio.h>
#include <string>

#define MX 1000000100
#define M_N 50
using namespace std;

int n;
int p;
int l;

int case_count[M_N + 1];

void count_cases()
{
	int num = 1;
	bool bOverflow = false;
	//case_count[0] = 1;
	for (int i = 0; i < M_N + 1; i++)
	{
		if (bOverflow == false)
			case_count[i] = (num * 3 - 2);
		if (case_count[i] >= MX)//&& bOverflow == false)
			bOverflow = true;
		if (bOverflow == true)
			case_count[i] = MX;
		num *= 2;
	}
}

void make_dragon(int generation, int start, int leng, string src_string)
{
	int cnt = 0;
	int pre_cnt = 0;
	start = start > 0 ? start : 1;
	for (int idx = 0; idx < (int)src_string.length(); idx++)
	{
		char c = src_string[idx];
		switch (c)
		{
		case 'X':
			cnt += case_count[generation];
			if (cnt >= MX)	cnt = MX;
			if (start <= cnt)
			{
				if (generation == 0)
				{
					printf("X");
					l--;
				}
				else
					make_dragon(generation - 1, start - pre_cnt, leng, "X+YF");
				leng -= case_count[generation];
			}
			break;

		case 'Y':
			cnt += case_count[generation];
			if (cnt >= MX)	cnt = MX;
			if (start <= cnt)
			{
				if (generation == 0)
				{
					printf("Y");
					l--;
				}
				else
					make_dragon(generation - 1, start - pre_cnt, leng, "FX-Y");
				leng -= case_count[generation];
			}
			break;
		case 'F':
		case '+':
		case '-':
			cnt ++;
			if (cnt >= MX)	cnt = MX;
			if (start <= cnt)
			{
				printf("%c", c);
				leng--;
				l--;
			}
			break;

		default:
			printf("invalid value assertion\n");
			break;
		}

		pre_cnt = cnt;
		//if (leng <= 0)
		//{
		//	return;
		//}
		if (l <= 0)
			return;
	}
}

int main()
{
	int c;
	cin >> c;
	count_cases();
	for (; c > 0; c--)
	{
		cin >> n >> p >> l;
		if (n < 0)
			break;
		make_dragon(n, p, l, "FX");
		cout << endl;
	}
	return 0;
}
