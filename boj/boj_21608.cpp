//boj 21608
//2021-09-30 15:00 ~ 16:59
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MX_N = 20;
const int FRI_CNT = 4;
const int DIR_CNT = 4;
const int MX_N2 = 400;

const int SCORE_F = 100000;
const int SCORE_E = 10000;
const int SCORE_R = 100;
const int SCORE_C = 1;

const int dir[DIR_CNT][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int n;
int n2;
int classroom[MX_N][MX_N];

int stu_list[MX_N2];
int fri_list[MX_N2 + 1][FRI_CNT];

int stu_seat_table[MX_N2 + 1][2];

struct Seat 
{
	int r, c, f_cnt, e_cnt;
	bool operator < (const Seat& s) const {
		int this_score = f_cnt * SCORE_F + e_cnt * SCORE_E + (MX_N - r) * SCORE_R + (MX_N - c);
		int s_score = s.f_cnt * SCORE_F + s.e_cnt * SCORE_E + (MX_N - s.r) * SCORE_R + (MX_N - s.c);
		return this_score < s_score;
	}
};

void init_data() 
{
	n = n2 = 0;
	memset(classroom, 0, sizeof(classroom));
	memset(stu_list, 0, sizeof(stu_list));
	memset(fri_list, 0, sizeof(fri_list));
	memset(stu_seat_table, -1, sizeof(stu_seat_table));
}

void input_data() 
{
	scanf("%d", &n);
	n2 = n * n;
	for (int stu = 0; stu < n2; ++stu) {
		scanf("%d", &stu_list[stu]);
		for (int fri = 0; fri < 4; ++fri) {
			scanf("%d", &fri_list[stu_list[stu]][fri]);
		}
	}
}

void print_data() 
{
	printf("n : %d sz : %d \n", n, n2);

	printf("stu_list : ");
	for (int idx = 0; idx < n2; ++idx) {
		printf("%2d", stu_list[idx]);
	}
	printf("\n");

	printf("<fri_list>");
	for (int stu = 1; stu <= n2; ++stu) {
		printf("[%2d] -> ", stu);
		for (int fri = 0; fri < 4; ++fri) {
			printf("%3d", fri_list[stu][fri]);
		}
		printf("\n");
	}
}

void print_room() 
{
	printf("\n");
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			printf("%3d", classroom[r][c]);
		}
		printf("\n");
	}
}

bool is_friend(const int& stu, const int& classmate)
{
	for (int fri = 0; fri < FRI_CNT; ++fri) {
		if (fri_list[stu][fri] == classmate)
			return true;
	}
	return false;
}

void enqueue(const int& stu, const int& r, const int& c, priority_queue<Seat>& cand_seats)
{
	int nr, nc;
	int e_cnt = 0;
	int f_cnt = 0;
	for (int idx = 0; idx < DIR_CNT; ++idx) {
		nr = r + dir[idx][0];
		nc = c + dir[idx][1];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n)
			continue;
		if (classroom[nr][nc] == 0)
			++e_cnt;
		else if (is_friend(stu, classroom[nr][nc]))
			++f_cnt;
	}
	Seat s = { r, c, f_cnt, e_cnt };
	cand_seats.push(s);
}

bool seat_around_friends(const int & stu) 
{
	int pivot, r, c, nr, nc;
	priority_queue<Seat> cand_seats;
	for (int fri = 0; fri < FRI_CNT; ++fri) {
		pivot = fri_list[stu][fri];
		r = stu_seat_table[pivot][0];
		c = stu_seat_table[pivot][1];
		if (r == -1)	continue;

		for (int idx = 0; idx < DIR_CNT; ++idx) {
			nr = r + dir[idx][0];
			nc = c + dir[idx][1];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n)
				continue;
			if (classroom[nr][nc])
				continue;
			enqueue(stu, nr, nc, cand_seats);
		}
	}

	if (cand_seats.empty())
		return false;

	r = cand_seats.top().r;
	c = cand_seats.top().c;

	classroom[r][c] = stu;
	stu_seat_table[stu][0] = r;
	stu_seat_table[stu][1] = c;
	return true;
}

void take_seat(const int& stu) 
{
	if (seat_around_friends(stu))
		return;

	int r, c;
	priority_queue<Seat> cand_seats;
	for (r = 0; r < n; ++r) {
		for (c = 0; c < n; ++c) {
			if (classroom[r][c])
				continue;
			enqueue(stu, r, c, cand_seats);
		}
	}

	r = cand_seats.top().r;
	c = cand_seats.top().c;
	classroom[r][c] = stu;
	stu_seat_table[stu][0] = r;
	stu_seat_table[stu][1] = c;
}

void solve() 
{
	for (int idx = 0; idx < n2; ++idx) {
		take_seat(stu_list[idx]);
	}
}

int calc_score()
{
	int ret = 0;
	int cmp, cnt;
	int stu, fri;
	int mr, mc, fr, fc;
	for (int m_idx = 0; m_idx < n2; ++m_idx) {
		cnt = 0;
		stu = stu_list[m_idx];
		mr = stu_seat_table[stu][0];
		mc = stu_seat_table[stu][1];
		for (int f_idx = 0; f_idx < FRI_CNT; ++f_idx) {
			fri = fri_list[stu][f_idx];
			fr = stu_seat_table[fri][0];
			fc = stu_seat_table[fri][1];

			cmp = (mr - fr) * (mr - fr) + (mc - fc) * (mc - fc);
			if (cmp == 1)	++cnt;
		}

		switch (cnt) {
		case 1:	ret += 1; break;
		case 2:	ret += 10; break;
		case 3:	ret += 100; break;
		case 4:	ret += 1000; break;
		default: break;
		}
	}

	return ret;
}

int main()
{
	init_data();
	input_data();
	//print_data();
	solve();
	printf("%d\n", calc_score());
	return 0;
}
