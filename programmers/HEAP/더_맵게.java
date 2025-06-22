package com.kt.aicare.common.util.programmers.HEAP;
import java.util.*;

public class 더_맵게 {
  void offerAll(int[] elems, PriorityQueue<Integer> target) {
    for (int elem : elems) {
      target.offer(elem);
    }
  }

  void mixFoods(PriorityQueue<Integer> container) {
    if (container.size() < 2) {
      return;
    }
    int food1 = container.poll();
    int food2 = container.poll();

    container.offer(food1 + food2 * 2);
  }

  public int solution(int[] scoville, int K) {
    PriorityQueue<Integer> pq = new PriorityQueue<>();
    offerAll(scoville, pq);

    for(int cnt = 0; cnt < scoville.length; cnt++) {
      if (pq.peek() >= K) {
        return cnt;
      }
      mixFoods(pq);
    }

    return -1;
  }

}
