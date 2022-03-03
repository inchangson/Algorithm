//JLIS 
#if 0
#include <iostream>
#include <algorithm>
#include <memory.h> 

#define SIZE 100
#define MX 0x7FFFFFFF

using namespace std;

int lengA;
int lengB;

int A[SIZE + 1];
int B[SIZE + 1];

int cache[SIZE + 1][SIZE + 1];

void inputData()
{
	memset(cache, -1, sizeof(cache));

	cin >> lengA >> lengB;

	for (int i = 0; i < lengA; i++)
		cin >> A[i];
	for (int i = 0; i < lengB; i++)
		cin >> B[i];
}

void printData()
{
	cout << "print data start" << endl;

	for (int i = 0; i < lengA + 1; i++)
	{
		for (int j = 0; j < lengB + 1; j++)
			cout << cache[i][j] << " ";
		cout << endl;
	}
	cout << "print data end" << endl;
	//cout << lengA << " " << lengB << endl;

	//for (int i = 0; i < lengA; i++)
	//	cout << A[i]<< " ";
	//cout << endl;
	//for (int i = 0; i < lengB; i++)
	//	cout << B[i]<< " ";
	//cout << endl;
}

const long long NEGINF = -MX - 1;//numeric_limits<long long>::min();

int JLIS(int ax, int bx, long long flag)
{
	int & ret = cache[ax + 1][bx + 1];
	if (ret != -1)
		return ret;
	//long long aa = (ax == -1) ? NEGINF : A[ax];
	//long long bb = (bx == -1) ? NEGINF : B[bx];
	//long long flag = max(aa, bb);

	ret = 0;

	for (int na = ax + 1; na < lengA; na++)
	{
		if (A[na] > flag)
			ret = max(ret, JLIS(na, bx, A[na]) + 1);
	}

	for (int nb = bx + 1; nb < lengB; nb++)
	{
		if (B[nb] > flag)
			ret = max(ret, JLIS(ax, nb, B[nb]) + 1);
	}
	return ret;
}

int main()
{
	int c;
	cin >> c;
	for (; c > 0; c--)
	{
		inputData();
		cout << JLIS(-1, -1, NEGINF) << endl;
		//printData();
	}
	return 0;
}
#endif
