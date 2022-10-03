//boj 21609
//18:30 ~ 22:11
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MX_N = 20;
const int EMPTY = -2;
const int BLACK = -1;
const int RAINBOW = 0;

const int DIR_CNT = 4;
const int dir[DIR_CNT][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
int m;

int biggest_r;
int biggest_c;

int total_score;

int map[MX_N][MX_N];
int tmp_map[MX_N][MX_N];
int visited[MX_N][MX_N];

int cur_round;

typedef struct NODE
{
	int r, c;
}node;

int wp, rp;
node que[MX_N * MX_N];
void input_que(int r, int c)
{
	que[wp].r = r;
	que[wp++].c = c;
}

void init_data()
{
	n = m = biggest_r = biggest_c = 0;
	total_score = 0;
	wp = rp = cur_round = 0;
	int r, c;
	for(r = 0; r < MX_N; ++r)
	{
		for(c = 0; c < MX_N; ++c)
		{
			map[r][c] = visited[r][c] = 0;
		}
	}
}

void input_data()
{
	scanf("%d %d", &n, &m);
	int r, c;
	for(r = 0; r < n; ++r)
	{
		for(c = 0; c < n; ++c)
		{
			scanf("%d", &map[r][c]);
		}
	}
}

void print_data()
{
	printf("\n");
	//printf("%d %d\n", n, m);
	int r, c;
	for(r = 0; r < n; ++r)
	{
		for(c = 0; c < n; ++c)
		{
			if(map[r][c] != EMPTY)
			printf("%3d", map[r][c]);
			else
			printf("   ");
		}
		printf("\n");
	}
	printf("\n");
	/*for(r = 0; r < n; ++r)
	{
		for(c = 0; c < n; ++c)
			printf("%3d", visited[r][c]);
		printf("\n");
	}
	printf("\n");*/
}

int get_group_size(int sr, int sc, int & rainbow)
{
	wp = rp = 0;
	input_que(sr, sc);
	visited[sr][sc] = cur_round;
	int cur_color = map[sr][sc];	
	int cr, cc, nr, nc;
	for(;wp > rp;)
	{
		node cur_node = que[rp++];
		cr = cur_node.r;
		cc = cur_node.c;
		
		for(int idx = 0; idx < DIR_CNT; ++idx)
		{
			nr = cr + dir[idx][0];
			nc = cc + dir[idx][1];
			
			if(nr < 0 || nr >= n || nc < 0 || nc >= n)
				continue;
			if(visited[nr][nc] == cur_round)
				continue;
			if(map[nr][nc] == BLACK || map[nr][nc] == EMPTY)
				continue;
			if(map[nr][nc] != cur_color && map[nr][nc] != RAINBOW)
				continue;
			if(map[nr][nc] == RAINBOW)
			{
				++rainbow;
			}
			input_que(nr, nc);
			visited[nr][nc] = cur_round;
		}
	}
	return wp;
}

int get_biggest()
{
	int ret = 0;
	int pre_rainbow = 0;
	int tmp;
	int r, c;
	for(r = 0; r < n; ++r)
	{
		for(c = 0; c < n; ++c)
		{
			if(map[r][c] == BLACK 
			|| map[r][c] == RAINBOW 
			|| map[r][c] == EMPTY)
				continue;
			if(visited[r][c] != 0 && visited[r][c] <= cur_round)
				continue;
			int tmp_rainbow = 0;
			tmp = get_group_size(r, c, tmp_rainbow);
			++cur_round;
			//printf("(%d, %d) : %d\n", r, c, tmp);
			if(tmp > ret)
			{
				biggest_r = r;
				biggest_c = c;
				pre_rainbow = tmp_rainbow;
				ret = tmp;
			}
			else if(tmp == ret)
			{
				if(pre_rainbow <= tmp_rainbow)
				{
					biggest_r = r;
					biggest_c = c;
					pre_rainbow = tmp_rainbow;
					ret = tmp;	
				}
			}
		}
	}
	return ret;
}

void remove_group(int sr, int sc)
{
	int cur_color = map[sr][sc];
	wp = rp = 0;
	input_que(sr, sc);
	map[sr][sc] = EMPTY;
		
	int cr, cc, nr, nc;
	for(;wp > rp;)
	{
		node cur_node = que[rp++];
		cr = cur_node.r;
		cc = cur_node.c;
		
		for(int idx = 0; idx < DIR_CNT; ++idx)
		{
			nr = cr + dir[idx][0];
			nc = cc + dir[idx][1];
			
			if(nr < 0 || nr >= n || nc < 0 || nc >= n)
				continue;
			if(map[nr][nc] == BLACK || map[nr][nc] == EMPTY)
				continue;
			if(map[nr][nc] != cur_color && map[nr][nc] != RAINBOW)
				continue;
			input_que(nr, nc);
			map[nr][nc] = EMPTY;
		}
	}
}

int get_arr_leng(int sr, int c, int & nr)
{
	int ret = 1;
	int next;
	for(next = sr - 1; next >= 0; --next)
	{
		if(map[next][c] == EMPTY || map[next][c] == BLACK)
		{
			break;
		}
	}
	nr = next;
	ret = sr - next;
	return ret;
}

int get_distance(int sr, int sc)
{
	int dist = 0;
	for(int next = sr + 1; next < n; ++next)
	{
		if(map[next][sc] != EMPTY)
		{
			break;		
		}
		++dist;
	}
	return dist;
}

void apply_gravity()
{
	int r, c, next;
	for(c = n - 1; c >= 0; --c)
	{
		for(r = n - 1; r >= 0; --r)
		{
			if(map[r][c] == EMPTY || map[r][c] == BLACK)
			{
				continue;
			}
			int nr;
			int arr_leng = get_arr_leng(r, c, nr);
			int distance = get_distance(r, c);
			//printf("(%d, %d), arrleng %d dist %d nr %d\n", r, c, arr_leng, distance, nr);
			if(distance != 0)
			{
				for(int idx = 0; idx < arr_leng; ++idx)
				{
					map[r - idx + distance][c] = map[r - idx][c];
					map[r - idx][c] = -2;
				}
			}
			r = nr;
		}				
	}
}

void copy_map()
{
	int r, c;
	for(r = 0; r < n; ++r)
		for(c = 0; c < n; ++c)
			tmp_map[r][c] = map[r][c];
}

void rotate_map()
{
	copy_map();
	
	int r, c;
	for(c = 0; c < n; ++c)
	{
		for(r = 0; r < n; ++r)
		{
			map[r][c] = tmp_map[ c][n - 1 -r];
		}
	}
}

void init_visited()
{
	for(int r = 0; r < n; ++r)
	for(int c = 0; c < n; ++c)
	visited[r][c] = 0;
}

void solve()
{	
	int group_size = 0;
	cur_round = 1;
	
	for(;;)
	{
		init_visited();
		//printf("<<<%d>>>", cur_round);
		//print_data();
		group_size = get_biggest();
		//printf("biggest : %d\n", group_size);
		if(group_size < 2)
			break;
		remove_group(biggest_r, biggest_c);
		//printf("remove\n");
		//print_data();
		total_score += group_size * group_size;
		apply_gravity();
		//printf("gravity\n");
		//print_data();
		rotate_map();	
		//printf("rotate\n");	
		//print_data();
		apply_gravity();
		//printf("gravity\n");
		//print_data();
	}
}

int main()
{
	init_data();
	input_data();
	//print_data();
	
	solve();
	printf("%d\n", total_score);
	
	return 0;
}
