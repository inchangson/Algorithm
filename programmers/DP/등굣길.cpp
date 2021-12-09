#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <limits>

#include <iostream>

using namespace std;

constexpr int DIR_CNT = 2;
constexpr int DIR[DIR_CNT][2] = {{1, 0}, {0, 1}};
constexpr int MX_SZ = 101;
constexpr int MOD = 1000000007;

//land : 0, puddle : 1, visited = -1
int g_map[MX_SZ][MX_SZ];
int g_routes[MX_SZ][MX_SZ];

int sr, sc, er, ec;
int cur_min_time;

typedef struct node{
    int r, c;
}node;

queue<node> q;

void enqueue(int r, int c){
    q.push({r, c});
    g_map[r][c] = -1;
    int cnt = 0;
    for(int idx = 0; idx < DIR_CNT; ++idx){
        cnt = (cnt + g_routes[r - DIR[idx][0]][c - DIR[idx][1]]) % MOD;
    }
    g_routes[r][c] = (g_routes[r][c] + cnt) % MOD;
}

void make_map(int m, int n, const vector<vector<int>> & puddles){
    memset(g_map, 0, sizeof(g_map));
    memset(g_routes, 0, sizeof(g_routes));
    for(int idx = 0; idx < puddles.size(); ++idx){
        g_map[puddles[idx][0]][puddles[idx][1]] = 1;
    }
    sr = 1;
    sc = 1;
    er = m;
    ec = n;
    cur_min_time = m * n;
}

bool is_possible_route(int r, int c){
    if(r >= 1 && r <= er && c >= 1 && c <= ec && !g_map[r][c])
        return true;
    return false;
}

int get_shortest_cnt(){
    int cr, cc, nr, nc;
    g_routes[sr][sc] = 1;
    enqueue(sr, sc);
    
    while(!q.empty()){
        cr = q.front().r;
        cc = q.front().c;
        q.pop();
        if(cr == er && cc == ec)    break;
        for(int idx = 0; idx < DIR_CNT; ++idx){
            nr = cr + DIR[idx][0];
            nc = cc + DIR[idx][1];
            if(is_possible_route(nr, nc)){
                enqueue(nr, nc);
            }
        }
    }
    return g_routes[er][ec];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    make_map(m, n, puddles);
    answer = get_shortest_cnt();
    return answer;
}
