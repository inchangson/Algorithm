package com.kt.aicare.common.util.programmers.GRAPH;
import java.util.*;
public class 순위 {
  static final int WIN = 1;
  static final int LOSE = -1;
  static final int NA = 0;
  int[][] board = new int[0][0];
  int boxerCnt;

  void printBoard() {
    System.out.printf("=============\n");
    for (int i = 1; i <= boxerCnt; i++) {
      for (int j = 1; j <= boxerCnt; j++) {
        System.out.printf("%2d", board[i][j]);
      }
      System.out.println();
    }
  }

  void initData(int n, int[][] results) {
    boxerCnt = n;
    board = new int[n + 1][n + 1];
    for (int[] result : results) {
      int w = result[0];
      int l = result[1];
      board[w][l] = WIN;
      board[l][w] = LOSE;
    }
    // printBoard();
  }


  int getAnswer() {
    int ret = 0;
    for (int i = 1; i <= boxerCnt; i++) {
      long cnt = Arrays.stream(board[i])
          .filter(elem -> elem != NA)
          .count();
      if (cnt == (boxerCnt - 1)) {
        ret++;
      }
    }
    return ret;
  }

  public int solution(int n, int[][] results) {
    initData(n, results);

    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (board[i][k] == WIN && board[k][j] == WIN) {
            board[i][j] = WIN;
          }
          if (board[i][k] == LOSE && board[k][j] == LOSE) {
            board[i][j] = LOSE;
          }
        }
      }
    }
    // printBoard();
    return getAnswer();
  }
}
