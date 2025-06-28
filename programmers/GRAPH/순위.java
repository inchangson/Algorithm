package com.kt.aicare.common.util.programmers.GRAPH;
import java.util.*;
public class 순위 {
  static final int WIN = 1;
  static final int LOSE = -1;
  static final int NA = 0;
  int[][] board = new int[0][0];
  int boxerCnt;

  void printBoard() {
    for (int i = 1; i <= boxerCnt; i++) {
      for (int j = 1; j <= boxerCnt; j++) {
        System.out.print(String.format("%2d", board[i][j]));
      }
      System.out.println();
    }
  }

  void initData(int n, int[][] results) {
    boxerCnt = n;
    board = new int[n + 1][n + 1];
    // printBoard();
  }

  int getAnswer() {
    int ret = 0;
    for (int i = 1; i <= boxerCnt; i++) {
      long cnt = Arrays.stream(board[i])
          .filter(elem -> elem != NA)
          .count();
      if (cnt == (boxerCnt - 1)) {
        // System.out.println("i" + i);
        ret++;
      }
    }
    return ret;
  }

  void updateWinner(int target, int current, boolean[] checked) {
    board[target][current] = WIN;
    checked[current] = true;
    for (int next = 1; next <= boxerCnt; next++) {
      if (checked[next])  continue;
      if (board[current][next] == WIN)
        updateWinner(target, next, checked);
    }
  }

  void updateLoser(int target, int current, boolean[] checked) {
    board[target][current] = LOSE;
    checked[current] = true;
    for (int next = 1; next <= boxerCnt; next++) {
      if (checked[next])  continue;
      if (board[current][next] == LOSE)
        updateLoser(target, next, checked);
    }
  }

  void updateBoard(int[][] results) {
    for (int[] result : results) {
      int winner = result[0];
      int loser = result[1];
      boolean[] winnerCheck = new boolean[boxerCnt + 1];
      updateWinner(winner, loser, winnerCheck);
      boolean[] loserCheck = new boolean[boxerCnt + 1];
      updateLoser(loser, winner, loserCheck);
    }
  }

  public int solution(int n, int[][] results) {
    initData(n, results);

    updateBoard(results);
    updateBoard(results);
    // printBoard();

    return getAnswer();
  }

}
