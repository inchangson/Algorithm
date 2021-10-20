#include <cstdio>
#include <iostream>
#include <queue>

constexpr int MP_SZ = 4;
constexpr int DIR_CNT = 8;
constexpr int dir[DIR_CNT][2] = {{0, 1}, {-1, 1}, 
								{-1, 0}, {-1, -1}, 
								{0, -1}, {1, -1},
								{1, 0}, {1, 1}};
constexpr int FISH_CNT = 16;
constexpr int SHARK = 16;

typedef struct node{
	int r, c, d;
}node;

int map[MP_SZ][MP_SZ][2];
node fish_pos[FISH_CNT + 1];
int ans;
queue<node> q;

void enqueue(int r, int c, int d){
	q.push({r, c, d});
}

void input_data(){
	node tmp;
	for(int r = 0; r < MP_SZ; ++r){
		for(int c = 0; c < MP_SZ; ++c){
			scanf("%d %d", &map[r][c][0], &map[r][c][1]);
			--map[r][c][1];
			tmp.r = r;
			tmp.c = c;
			tmp.d = map[r][c][1];
			fish_pos[map[r][c][0]] = tmp;
		}
	}
}

void print_data(){
	node tmp;
	for(int r = 0; r < MP_SZ; ++r){
		for(int c = 0; c < MP_SZ; ++c){
			printf("[%2d / %2d]", map[r][c][0], map[r][c][1]);
		}
		printf("\n");
	}
}

void solve(){
	
}

int main(){
	input_data();
	//print_data();
	solve();
	printf("%d\n", ans);
	return 0;
}
