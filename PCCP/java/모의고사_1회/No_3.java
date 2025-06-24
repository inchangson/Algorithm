package com.kt.aicare.common.util.PCCP.java.모의고사_1회;
import java.util.*;

public class No_3 {
  int myPower(int n, int p) {
    int ret = 1;
    while(p-- > 0) {
      ret *= n;
    }
    return ret;
  }

  String findGene(int n, int p) {
    if (n == 1) {
      return "Rr";
    }

    if (n == 2) {
      if (p == 1) return "RR";
      if (p == 4) return "rr";
      return "Rr";
    }

    int step = myPower(4, n - 2);
    if (p <= step) return "RR";
    if (p <= 2*step) return findGene(n - 1, p - step);
    if (p <= 3*step) return findGene(n - 1, p - 2 * step);
    return "rr";
  }


  public List<String> solution(int[][] queries) {
    List<String> answer = new ArrayList<>();
    for (int[] q : queries) {
      answer.add(findGene(q[0], q[1]));
    }
    return answer;
  }

}
