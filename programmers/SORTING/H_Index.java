package com.kt.aicare.common.util.programmers.SORTING;
import java.util.*;
import java.util.stream.*;

public class H_Index {
  public int solution(int[] citations) {
    int answer = 0;
    Arrays.sort(citations);

    for (int i = citations.length - 1; i >= 0; i--) {
      int cand = citations.length - i;
      if (citations[i] >= cand) {
        answer = cand;
      }
    }

    return answer;
  }
}
