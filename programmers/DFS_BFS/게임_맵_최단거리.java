package com.kt.aicare.common.util.programmers.DFS_BFS;
import java.util.*;

public class 게임_맵_최단거리 {
  int[] dr = {1, 0, -1, 0};
  int[] dc = {0, -1, 0, 1};
  int[][] board;
  int n;
  int m;
  Position target;

  static class Position {
    int r;
    int c;
    int d;

    Position(int r, int c, int d) {
      this.r = r;
      this.c = c;
      this.d = d;
    }

    @Override
    public String toString() {
      return String.format("r: %d c: %d d: %d", r, c, d);
    }

    public boolean isSameLocation(Position p) {
      return this.r == p.r && this.c == p.c;
    }
  }

  void initData(int[][] maps) {
    n = maps.length;
    m = maps[0].length;
    board = new int[n][m];
    for (int i = 0; i < n; i++) {
      board[i] = maps[i].clone();
    }
    target = new Position(n - 1, m - 1, 0);
  }

  boolean canGo(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m ) {
      return false;
    }

    if (board[r][c] != 1) {
      return false;
    }

    return true;
  }


  public int solution(int[][] maps) {
    int answer = -1;
    initData(maps);
    Deque<Position> q = new LinkedList<>();
    q.offerLast(new Position(0, 0, 1));
    board[0][0] = -1;
    while (!q.isEmpty()) {
      Position cur = q.pollFirst();// current
      board[cur.r][cur.c] = -1;
      if (cur.isSameLocation(target)) {
        return cur.d;
      }
      for (int d = 0; d < 4; d++) {
        int nr = cur.r + dr[d];
        int nc = cur.c + dc[d];
        if (canGo(nr, nc)) {
          q.offerLast(new Position(nr, nc, cur.d + 1));
          board[nr][nc] = -1;
        }
      }
    }
    return answer;
  }

}
