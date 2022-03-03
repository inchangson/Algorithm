// BOJ 20058 : 마법사 상어와 파이어스톰
// 2021-09-24 12:36 ~ 14:18

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define MX_SIZE 64

using namespace std;

int n, q, l;

int map_size;
int total;

int map[MX_SIZE][MX_SIZE];
int buffer[MX_SIZE][MX_SIZE];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int pow_two[7];

int get_map_size(int n)
{
	int ret = 1;
	pow_two[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		ret *= 2;
		pow_two[i] = ret;
	}
	return ret;
}

void input_data()
{
	cin >> n >> q;
	map_size = get_map_size(n);
	for(int i = 0 ; i < map_size; ++i)
	{
		for(int j = 0; j < map_size; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

void fill_buf()
{
	for(int i = 0 ; i < map_size; ++i)
	{
		for(int j = 0; j < map_size; ++j)
		{
			buffer[i][j] = map[i][j];
		}
	}
}

void print_data()
{
	cout << endl;
	cout << n << " " << q << " " << l << endl;
	for(int i = 0 ; i < map_size; ++i)
	{
		for(int j = 0; j < map_size; ++j)
		{
			printf("%2d ", map[i][j]);
		}
		printf("\n");
	}
}

void spin(int cr, int cc, int sz, int leng)
{
	if(sz != leng)
	{
		--sz;
		spin(cr, cc, sz, leng);
		spin(cr + pow_two[sz], cc, sz, leng);
		spin(cr, cc + pow_two[sz], sz, leng);
		spin(cr + pow_two[sz], cc + pow_two[sz], sz, leng);
		return;
	}
	
	for(int r = 0; r < pow_two[sz]; ++r)
	{
		for(int c = 0; c < pow_two[sz]; ++c)
		{
			map[cr + r][cc + c]
			= buffer[cr + (pow_two[sz] - 1 - c)][cc + (r)];
		}
	}
}

void remove_snow()
{
	int cnt, nr, nc;
	for(int r = 0; r < map_size; ++r)
	{
		for(int c = 0; c < map_size; ++c)
		{
			if(buffer[r][c] == 0)
				continue;
			cnt = 0;
			for(int i = 0; i < 4; ++i)
			{
				nr = r + dir[i][0];
				nc = c + dir[i][1];
				if(nr < 0 || nr >= map_size || nc < 0 || nc >= map_size)
					continue;
				if(buffer[nr][nc] == 0)
					continue;
				++cnt;
			}
			if(cnt < 3)
			{
				--map[r][c];
			}
		}
	}
}

void fire_storm(int leng)
{
	fill_buf();
	spin(0, 0, n, leng);
	fill_buf();
	remove_snow();
}

int collect_ice(int cr, int cc)
{
	int nr, nc;
	int ret = 1;
	total += map[cr][cc];
	map[cr][cc] = 0;
	for(int i = 0; i < 4; ++i)
	{
		nr = cr + dir[i][0];
		nc = cc + dir[i][1];
		
		if(nr < 0 || nr >= map_size || nc < 0 || nc >= map_size)
			continue;
		if(map[nr][nc] == 0)
			continue;
		ret += collect_ice(nr, nc);//check overflow later
	}
	return ret;
}

int main()
{
	input_data();
	for(int i = 0; i < q; ++i)
	{
		cin >> l;
		fire_storm(l);
		//print_data();
	}
	
	int largest = 0;
	for(int r = 0; r < map_size; ++r)
	{
		for(int c = 0; c < map_size; ++c)
		{
			if(map[r][c])
			{
				int tmp = collect_ice(r, c);
				largest = max(largest, tmp);
			}
		}
	}
	cout << total << "\n" << largest << endl;
	return 0;
}
