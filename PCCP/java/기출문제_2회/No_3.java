package com.kt.aicare.common.util.PCCP.java.기출문제_2회;
import java.util.*;

public class No_3 {
  static final int R = 0;
  static final int C = 1;

  static class State {
    int r;
    int c;
    int t;

    State(int r, int c, int t) {
      this.r = r;
      this.c = c;
      this.t = t;
    }

    @Override
    public boolean equals(Object o1) {
      State that = (State) o1;
      return this.r == that.r && this.c == that.c;
    }
    @Override
    public int hashCode() {
      return t * 1000000 + r * 1000 + c;
    }

    @Override
    public String toString() {
      return String.format("(%d %d %d)", r, c, t);
    }
  }

  int[] getPointByNo(int num, int[][] points) {
    return points[num - 1];
  }

  Deque<State> getRobotHistory(int[][] points, int[] route) {
    Deque<State> history = new LinkedList<>();
    int clock = 0;
    for (int cur = 0; cur < route.length - 1; cur++) {
      int[] from = points[route[cur] - 1];
      int[] to = points[route[cur + 1] - 1];

      int dr = from[R] < to[R] ? 1 : -1;
      for (int r = from[R]; r != to[R]; r += dr) {
        history.add(new State(r, from[C], clock++));
      }
      int dc = from[C] < to[C] ? 1 : -1;
      for (int c = from[C]; c != to[C]; c += dc) {
        history.add(new State(to[R], c, clock++));
      }

      if (cur == (route.length - 2)) {
        history.add(new State(to[R], to[C], clock));
      }
    }
    return history;
  }

  public int solution(int[][] points, int[][] routes) {
    int answer = 0;
    Deque<Deque<State>> histories = new LinkedList<>();
    Map<State, Integer> states = new HashMap<>();
    for (int[] route : routes) {
      Deque<State> history = getRobotHistory(points, route);
      for (State s : history) {
        states.put(s, states.getOrDefault(s, 0) + 1);
      }
    }

    for (Map.Entry<State, Integer> entry : states.entrySet()) {
      if (entry.getValue() > 1) {
        answer++;
      }
    }

    return answer;
  }

}
