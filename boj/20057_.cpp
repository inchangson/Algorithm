
#include <iostream>
#include <stdio.h>
#include <cstring>

#define MX 499
#define DIR_CNT 4
using namespace std;

int n;
int map[MX][MX];// 250000
bool visited[MX][MX];

int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
//west	  south    east    north

int er, ec;//end point
int bucket;

void input_data()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	er = ec = 0;
	bucket = 0;
	memset(visited, 0, sizeof(visited));
}

void print_data()
{
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d", map[i][j]);
		printf("\n");
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%3d", visited[i][j]);
		printf("\n");
	}
}


void push_sand(int cr, int cc, int cd, int step, int sand)
{
	int nd, nr, nc;
	for(int i = 0; i < 2; i++)
	{
		nd = (cd + 1 + (2 * i)) % DIR_CNT;
		nr = cr + step * dir[nd][0];
		nc = cc + step * dir[nd][1];
		
		if(nr < 0 || nr >= n || nc < 0 || nc >= n)
		{
			bucket += sand;
		}
		else
		{
			map[nr][nc] += sand;
		}
		if(step == 0)
			return;
	}
}


//current r, c, dir
void tornado(int cr, int cc, int cd)
{
	if (cr == er && cc == ec)
	{
		return;
	}
	
	visited[cr][cc] = true;
	
	//next row/ col
	int nr = cr + dir[cd][0];
	int nc = cc + dir[cd][1];
	
	int total_sand = map[nr][nc];
	int cur_sand;

	int tr = cr;//tmp row
	int tc = cc;//tmp col

	cur_sand = total_sand / 100;
	push_sand(tr, tc, cd, 1, cur_sand);
	map[nr][nc] -= 2 * cur_sand;
	
	tr = nr;
	tc = nc;
	
	cur_sand = 7 * total_sand / 100;
	push_sand(tr, tc, cd, 1, cur_sand);
	map[nr][nc] -= 2 * cur_sand;
	
	cur_sand = 2 * total_sand / 100;
	push_sand(tr, tc, cd, 2, cur_sand);
	map[nr][nc] -= 2 * cur_sand;

	tr += dir[cd][0];
	tc += dir[cd][1];
	
	cur_sand = 10 * total_sand / 100;
	push_sand(tr, tc, cd, 1, cur_sand);
	map[nr][nc] -= 2 * cur_sand;
	
	tr += dir[cd][0];
	tc += dir[cd][1];
	
	cur_sand = 5 * total_sand / 100;
	push_sand(tr, tc, cd, 0, cur_sand);
	map[nr][nc] -= cur_sand;
	
	tr -= dir[cd][0];
	tc -= dir[cd][1];
	push_sand(tr, tc, cd, 0, map[nr][nc]);
	map[nr][nc] = 0;
	

	int nd;
	int cross_row = nr + dir[(cd + 1) % DIR_CNT][0];
	int cross_col = nc + dir[(cd + 1) % DIR_CNT][1];

	if (visited[cross_row][cross_col] == false)
	{
		nd = (cd + 1) % DIR_CNT;
	}
	else
	{
		nd = cd;
	}
	
	tornado(nr, nc, nd);
}

int main()
{
	input_data();
	//print_data();

	//odd number 
	tornado(n / 2, n / 2, 0);

	//even number
	//tornado(n / 2 - 1, n / 2, 1)

	printf("%d\n", bucket);

	return 0;
}
