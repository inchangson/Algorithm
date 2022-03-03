#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

#define MX 16
#define INF 1098765432

using namespace std;

int n;
int map[MX][MX];
int memo[MX][1 << 16];

unsigned int all_done;

int ans;
//int** memo;

void input_data()
{
	cin >> n;	
	//memo = new int* [n];
	all_done = (0x1u << n) - 1;
	for(int i = 0; i < n; ++i)
	{
		//memo[i] = new int[all_done + 1];
		for(int j = 0; j < n; ++j)
		{
			scanf("%d", &map[i][j]);
		}
		
		//for(int j = 0; j < all_done + 1; ++j)
		//{
		//	memo[i][j] = -1;
		//}
	}
	memset(memo, -1, sizeof(memo));
	ans = INF;
}

void print_data()
{
	cout << n << endl;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			printf("%3d ", map[i][j]);
		printf("\n");
	}
	//cout << ans << endl;
}

int traveling(int cur_city, unsigned int visited)//current node
{
	if(cur_city == 0 && visited == all_done)
	{
		return 0;
	}
	
	int & ret = memo[cur_city][visited];
	if(ret != -1)	return ret;	
	ret = INF;
	
	int cand, cost;
	for(int next_city = 0; next_city < n ; ++next_city)
	{
		cost = map[cur_city][next_city];
		if(cost == 0)
			continue;
		if(visited & (0x1u << next_city))
			continue;
		if(cost >= ans)
			continue;
		
		visited |= (0x1u << next_city);
		cand = min(INF, cost + traveling(next_city, visited));
		visited ^= (0x1u << next_city);
		
		ret = min(ret, cand);
	}
	
	return ret;
}

int main()
{
	input_data();
	cout << traveling(0, 0) << endl;
	
	return 0;
}
