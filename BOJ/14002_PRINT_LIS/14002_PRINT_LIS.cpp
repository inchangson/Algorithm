#include <iostream>
#include <cstring>

#define MXLENG 1000

using namespace std;

int leng;
int arr[MXLENG + 1];
int memo[MXLENG + 1];
int bucket[MXLENG + 1];


int lis(int now)
{
	int & ret = memo[now];
	if(ret != -1) return ret;
	ret = 0;
	for(int next = now + 1; next <= leng; next++)
	{
		if(arr[now] < arr[next])
		{
			if(ret < (lis(next) + 1))
			{
				ret =lis(next) + 1;
				bucket[now] = next;
			}
		}
	}
	return ret;
}

int main()
{
	cin >> leng;
	for(int i = 0; i < leng; i++)
		cin >> arr[i + 1];
	memset(memo, -1, sizeof(memo));
	cout << lis(0) << endl;
	for(int i = 0; bucket[i] != 0 ;)
	{
		cout << arr[bucket[i]]<< " ";
		i = bucket[i];
		if(i == 0)
			break;
	}
	return 0;
}













