package com.kt.aicare.common.util.programmers.SORTING;

import java.util.*;

public class K번쨰큰수 {
  final int FROM = 0;
  final int TO = 1;
  final int TARGET = 2;
  public int[] solution(int[] array, int[][] commands) {
    List<Integer> answer = new ArrayList<>();
    for (int[] command : commands) {
      int[] cur = Arrays.copyOfRange(array,
          command[FROM] - 1,
          command[TO]);

      Arrays.sort(cur);
      answer.add(cur[(command[TARGET] - 1)]);
    }
    return answer.stream().mapToInt(Integer::valueOf).toArray();
  }

}
