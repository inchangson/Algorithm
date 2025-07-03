package com.kt.aicare.common.util.programmers.STACK_QUEUE;
import java.util.*;

public class 주식가격 {
  public int[] solution(int[] prices) {
    int[] answer = new int[prices.length];
    Deque<int[]> memo = new LinkedList<>(); // price, second

    for (int second = 0; second < prices.length; second++) {
      int currentPrice = prices[second];
      while (!memo.isEmpty() &&
          (memo.peekLast()[0] > currentPrice || second == prices.length - 1)) {
        int[] top = memo.pollLast();
        answer[top[1]] = second - top[1];
      }
      memo.offerLast(new int[]{currentPrice, second});
    }

    return answer;
  }

}
