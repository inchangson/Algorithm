package com.kt.aicare.common.util.programmers.STACK_QUEUE;
import java.util.*;

public class 같은_숫자는_싫어 {
  public int[] solution(int []arr) {
    List<Integer> ret = new ArrayList<>();

    int pre = -1;
    for (int i = 0; i < arr.length; i++) {
      if (pre == arr[i]) continue;
      ret.add(arr[i]);
      pre = arr[i];
    }
    return ret.stream().mapToInt(Integer::intValue).toArray();
  }
}
