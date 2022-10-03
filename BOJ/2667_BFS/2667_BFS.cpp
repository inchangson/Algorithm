#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

#define MX 25

using namespace std;

int n;
int map[MX][MX];
int visited[MX][MX];
vector<int> ans;

void input_data()
{
	cin >> n;
	char tmp;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			scanf(" %c", &tmp);	
			map[i][j] = tmp - '0';
			visited[i][j] = !map[i][j];
		}
}

void print_data()
{
	cout << "n : " << n << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

typedef struct NODE{
	int r, c;
}node;

node que[MX * MX];
int rp, wp;

void input_que(int r, int c)
{	
	que[wp].r = r;
	que[wp].c = c;	
	wp++;
}

int count_vilage(int sr, int sc)
{
	int cnt = 1;
	rp = wp = 0;
	input_que(sr, sc);
	
	int nr, nc;
	node nd;
	
	for(;wp > rp;)
	{
		nd = que[rp++];
		for(int i = 0; i < 4; i++)
		{
			nr = nd.r + dir[i][0];
			nc = nd.c + dir[i][1];
			
			if(nr < 0 || nr >= n)
				continue;
			if(nc < 0 || nc >= n)
				continue;
			if(visited[nr][nc])
				continue;
			if(map[nr][nc])
				continue;
			
			input_que(nr, nc);
			visited[nr][nc] = 1;
			cnt++;
		}
	}
	return cnt;
}

void get_ans()
{
	for(int i = 0 ;i < n; i++)
		for(int j = 0; j < n; j++)
			if(map[i][j] && !visited[i][j])
				ans.emplace_back(count_vilage(i, j));
	
	int vsize = ans.size();
	sort(ans.begin(), ans.end());
}

void print_ans()
{
	for(int n : ans)
		printf("%d\n", n);
}

int main()
{
	input_data();
	//print_data();
	cout << "===" << endl;
	get_ans();	
	print_ans();
	
	return 0;
}
