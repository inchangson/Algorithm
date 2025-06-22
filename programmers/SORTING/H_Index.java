package com.kt.aicare.common.util.programmers.SORTING;
import java.util.*;
import java.util.stream.*;

public class H_Index {
  public int solution(int[] citations) {
    int answer = 0;
    List<Integer> sorted = Arrays.stream(citations)
        .boxed()
        .sorted((a, b) -> (a < b)? 1 : -1)
        .collect(Collectors.toList());

    for (int cand = 0; cand < sorted.size(); cand++) {
      if (sorted.get(cand) >= (cand + 1)) {
        answer = cand + 1;
      }
    }

    return answer;
  }

}
