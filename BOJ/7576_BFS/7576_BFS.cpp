#include <iostream>
#include <vector>
#define MX_SZ 1000
#include <cstdio>
using namespace std;

int box[MX_SZ][MX_SZ];
int width, height;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

typedef struct STOMATO
{
	int r, c, d;
}tomato;

tomato que[MX_SZ * MX_SZ];

int wp, rp;
int cnt;

void input_que(int r, int c, int d)
{
	que[wp].r = r;
	que[wp].c = c;
	que[wp++].d = d;
}

void input_data()
{
	cin >> width >> height;
	//wp = rp = cnt = 0;	
	for(int r = 0; r < height; ++r)
	{
		for(int c = 0; c < width; ++c)
		{
			scanf("%d", &box[r][c]);
			if(box[r][c] == 1)
			{
				input_que(r, c, 0);
			}
			else if(box[r][c] == 0)
			{
				++cnt;
			}
		}
	}
}

int solve()
{
	if(cnt == 0)	return 0;
	int nr, nc;
	while(wp > rp)
	{
		tomato node = que[rp++];
		
		for(int i = 0 ; i < 4; ++i)
		{
			nr = node.r + dir[i][0];
			nc = node.c + dir[i][1];
			
			if(nr < 0 || nr >= height || nc < 0 || nc >= width)
				continue;
			if(box[nr][nc] == 0)
			{
				box[nr][nc] = 1;
				input_que(nr, nc, node.d + 1);
				--cnt;
				if(cnt == 0)
					return node.d + 1;
			}
		}		
	}
	return -1;
}

int main()
{
	input_data();
	cout << solve() << endl;
	return 0;
}
