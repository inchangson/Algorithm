package com.kt.aicare.common.util.programmers.DFS_BFS;
import java.util.*;

public class 아이템줍기 {
  int MX = 50 * 2 + 1;
  int ROAD = 1; int AIR = 0; int WATER = 2; int VISITED = -1;
  int X = 0; int Y = 1; int T = 2;
  int[][] board;
  int[] dx = {0, 1, 0, -1};
  int[] dy = {1, 0, -1, 0};

  void drawRectangle(int[] rectangle) {
    int x1 = rectangle[0] * 2; int y1 = rectangle[1] * 2;
    int x2 = rectangle[2] * 2; int y2 = rectangle[3] * 2;

    for (int y = y1; y <= y2; y++) {
      for (int x = x1; x <= x2; x++) {
        if (y == y1 || y == y2 || x == x1 || x == x2) {
          if (board[y][x] == WATER) continue;
          board[y][x] = ROAD;
        } else {
          board[y][x] = WATER;
        }
      }
    }
  }

  void seeInfo(int[] arr) {
    System.out.println(String.format("x: %d y: %d t: %d", arr[X], arr[Y], arr[T]));
  }

  void updatePath(Deque<int[]> paths, int x, int y, int t) {
    paths.offerLast(new int[]{x, y, t});
    board[y][x] = VISITED;
  }

  boolean canGo(int x, int y) {
    if (x < 0 || x >= MX) return false;
    if (y < 0 || y >= MX) return false;
    if (board[y][x] != ROAD)  return false;
    return true;
  }

  public int solution(int[][] rectangles, int characterX, int characterY, int itemX, int itemY) {
    characterX *= 2; characterY *= 2; itemX *= 2; itemY *= 2;
    board = new int[MX][MX];

    // draw
    for (int[] rectangle : rectangles) {
      drawRectangle(rectangle);
    }

    // bfs
    Deque<int[]> paths = new LinkedList<>();

    updatePath(paths, characterX, characterY, 0);
    while (!paths.isEmpty()) {
      int[] current = paths.pollFirst();
      if (current[X] == itemX && current[Y] == itemY) {
        return current[T] / 2;
      }
      for (int d = 0; d < 4; d++) {
        int nxtX = current[X] + dx[d];
        int nxtY = current[Y] + dy[d];
        if (!canGo(nxtX, nxtY)) continue;
        updatePath(paths, nxtX, nxtY, current[T] + 1);
      }
    }

    return 0;
  }

}
