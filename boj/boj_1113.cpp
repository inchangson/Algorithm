#include <stdio.h>

#define MX 50
int ans;
int n, m;
char pool[MX][MX];
char visited[MX][MX];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input_data(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%s", &pool[i]);
	}
}

void print_data(){
	printf("\nprint\n");
	printf("%d %d\n",  n,  m);
	for(int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			printf("%2c", pool[i][j]);
		}
		printf("\n");
	}
}

bool check_area(int r, int c, int* wall_size){
	int nr, nc, cnt = 0;
	for(int idx = 0; idx < 4; ++idx){
		nr = r + dir[idx][0];
		nc = c + dir[idx][1];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m){
			continue;
		}
		if(pool[nr][nc] > pool[r][c]){
			cnt++;
		}
	}
	return (cnt >= 2);
}

int get_pool_size(int r, int c, int wall){
	int nr, nc, cnt = 0;
	for(int idx = 0; idx < 4; ++idx){
		nr = r + dir[idx][0];
		nc = c + dir[idx][1];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m){
			cnt++;
			continue;
		}
		if(pool[nr][nc] > pool[r][c]){
			cnt++;
		}
	}
	return (cnt >= 2);
	
}

void solve(){
	int i, j, tmp, wall;	
	ans = -1;
	for(i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			if(visited[i][j])	continue;
			if(check_area(i, j, &wall) == false)	continue;
			tmp = get_pool_size(i, j, wall);
			if(tmp > ans){
				ans = tmp;
			}
		}
	}
}

int main(){
	input_data();	
	//print_data();
	solve();
	print("%d\n", ans);
	return 0;
}
