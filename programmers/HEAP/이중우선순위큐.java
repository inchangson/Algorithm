package com.kt.aicare.common.util.programmers.HEAP;
import java.util.*;

public class 이중우선순위큐 {
  public int[] solution(String[] operations) {
    int[] answer = new int[2];
    PriorityQueue<Integer> maxValues = new PriorityQueue<>((n1, n2) -> (n2 - n1));
    PriorityQueue<Integer> minValues = new PriorityQueue<>((n1, n2) -> (n1 - n2));

    for (String operation : operations) {
      String[] splited = operation.split(" ");
      String option = splited[0];
      int value = Integer.parseInt(splited[1]);

      if ("I".equals(option)) {
        minValues.offer(value);
        maxValues.offer(value);
        continue;
      }

      if (maxValues.isEmpty() || minValues.isEmpty()) {
        continue;
      }

      Integer target;
      if (value == 1) {// 최댓값 삭제
        target = maxValues.poll();
      } else {// 최솟값 삭제
        target = minValues.poll();
      }
      maxValues.remove(target);
      minValues.remove(target);
    }

    if (!maxValues.isEmpty() && !minValues.isEmpty()) {
      answer[0] = maxValues.poll();
      answer[1] = minValues.poll();
    }

    return answer;
  }

}
