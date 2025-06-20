package com.kt.aicare.common.util.programmers.STACK_QUEUE;
import java.util.*;

public class 기능개발 {

  // p : progress, s: speed
  private int getCurEndDay(int p, int s) {
    int left = (100 - p);
    if (left % s == 0) return left / s;
    return (left / s) + 1;
  }

  public int[] solution(int[] progresses, int[] speeds) {
    int[] answer = {};
    int N = speeds.length;
    LinkedList<Integer> deque = new LinkedList<>();

    int preEndDay = 0;
    for (int i = 0; i < N; i++) {
      int curEndDay = getCurEndDay(progresses[i], speeds[i]);
      if (preEndDay >= curEndDay) {
        Integer cache = deque.pollLast();
//        assert cache != null;
        deque.addLast(cache + 1);
      } else {
        deque.addLast(1);
        preEndDay = curEndDay;
      }
    }

    return deque.stream().mapToInt(Integer::valueOf).toArray();
  }
}
