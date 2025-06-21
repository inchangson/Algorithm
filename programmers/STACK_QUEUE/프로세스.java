package com.kt.aicare.common.util.programmers.STACK_QUEUE;
import java.util.*;

public class 프로세스 {
  Deque<Integer> getToGoes(int[] priorities) {
    Deque<Integer> ret = new LinkedList<>();
    int[] sorted = Arrays.copyOf(priorities, priorities.length);
    Arrays.sort(sorted);
    for (int s : sorted) {
      ret.offerFirst(s);
    }
    return ret;
  }

  Deque<List<Integer>> getProcesses(int[] priorities, int location) {
    Deque<List<Integer>> ret = new LinkedList<>();
    for (int i = 0; i < priorities.length; i++) {
      int p = priorities[i];
      if (location == i) {
        ret.offerLast(List.of(p, 1));
      } else {
        ret.offerLast(List.of(p, 0));
      }
    }
    return ret;
  }

  public int solution(int[] priorities, int location) {
    Deque<Integer> togoes = getToGoes(priorities);
    Deque<List<Integer>> processes = getProcesses(priorities, location);
    final int VALUE = 0;
    final int IS_TARGET = 1;

    int cnt = 0;
    while(!processes.isEmpty()) {
      List<Integer> cur = processes.pollFirst();
      int higheset = togoes.peekFirst();

      if (cur.get(VALUE) != higheset) {
        processes.offerLast(cur);
        continue;
      }

      cnt++;
      togoes.pollFirst();

      if (cur.get(IS_TARGET) == 1) {
        return cnt;
      }
    }


    return cnt;
  }

}
