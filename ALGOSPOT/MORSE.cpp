#include <algorithm>
#include <iostream>
#include <string>
#include <memory.h>
#include <stdio.h>

#define _SZ 201
#define _MX 1000000100

using namespace std;

int memo[_SZ][_SZ];

int morse(int line, int dot)
{
	int & ret = memo[line][dot];
	if(ret != -1)	return ret;
	
	ret = 0;
	if (line > 0)
		ret += morse(line - 1, dot);
	if (dot > 0)
		ret += morse(line, dot - 1);	
	if(ret > _MX)
		ret = _MX;
	return ret;
}

void reconstruct(int line, int dot, int msg)
{
	if(line == 0)
	{
		for(int i = 0; i < dot; i++)
			printf("o");
		return;
	}
	
	if(dot == 0)
	{
		for(int i = 0; i < line; i++)
			printf("-");
		return;
	}
	
	int sz = morse(line - 1, dot);
	if(msg <= sz)
	{
		printf("-");
		reconstruct(line - 1, dot, msg);
		return;
	}
	printf("o");
	reconstruct(line, dot - 1, msg - sz);	
}

int main()
{
	int c;
	cin >> c;
	memset(memo, -1, sizeof(memo));
	for(;c > 0; c--)
	{
		int n, m, k;
		memo[0][0] = 0;
		memo[1][0] = memo[0][1] = 1;	
		cin >> n >> m >> k;
		morse(n, m);
		reconstruct(n, m, k);
		printf("\n");
	}
	return 0;
}
