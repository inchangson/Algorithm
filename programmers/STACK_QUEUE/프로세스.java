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

  Deque<Integer> getProcesses(int[] priorities) {
    Deque<Integer> ret = new LinkedList<>();
    for (int p : priorities) {
      ret.offerLast(p);
    }
    return ret;
  }

  int calcLoc(int location, int sz) {
    return location == 0 ? sz - 1 : location - 1;
  }

  public int solution(int[] priorities, int location) {
    Deque<Integer> togoes = getToGoes(priorities);
    Deque<Integer> processes = getProcesses(priorities);

    int cnt = 0;
    while (!processes.isEmpty()) {
      int cur = processes.pollFirst();
      int higheset = togoes.peekFirst();
      if (cur != higheset) {
        processes.offerLast(cur);
        location = calcLoc(location, processes.size());
        continue;
      }

      cnt++;
      togoes.pollFirst();

      if (location == 0) {
        return cnt;
      }
      location = calcLoc(location, processes.size());
    }

    return cnt;
  }

}
