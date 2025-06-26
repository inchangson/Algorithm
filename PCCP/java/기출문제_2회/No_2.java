package com.kt.aicare.common.util.PCCP.java.기출문제_2회;

public class No_2 {
  int getPrev(int cur, int[] times) {
    if (cur == 0) return 0;
    else return times[cur - 1];
  }

  boolean canSolve(int level, int[] diffs, int[] times, long limit) {
    long clock = 0;
    for (int curIdx = 0; curIdx < diffs.length; curIdx++) {
      if (diffs[curIdx] > level) {
        int cnt = diffs[curIdx] - level;
        clock += (times[curIdx] + getPrev(curIdx, times)) * cnt;
      }
      clock += times[curIdx];

      if (clock > limit) {
        return false;
      }
    }
    return true;
  }

  public int solution(int[] diffs, int[] times, long limit) {
    int answer = 0;
    int left = 1; // level lowest
    int right = 100001; // level highest
    int mid = 0;

    while(left < right) {
      mid = (left + right) / 2;
      if (canSolve(mid, diffs, times, limit)) {
        right = mid;
        answer = mid;
      } else {
        left = mid + 1;
      }
    }

    return answer;
  }

}
