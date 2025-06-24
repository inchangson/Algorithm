package com.kt.aicare.common.util.PCCP.java.모의고사_1회;
import java.util.*;

public class No_2 {
  int typeCnt, stuCnt;
  boolean[] checked;
  void init(int[][] ability) {
    stuCnt = ability.length;
    typeCnt = ability[0].length;
    checked = new boolean[stuCnt];
  }

  int findBest(int typeIdx, int[][] ability) {
    if (typeIdx == typeCnt) {
      return 0;
    }

    int ret = 0;
    for (int stuIdx = 0; stuIdx < stuCnt; stuIdx++) {
      if (checked[stuIdx]) continue;
      checked[stuIdx] = true;
      ret = Math.max(ret,
          ability[stuIdx][typeIdx] + findBest(typeIdx + 1, ability));
      checked[stuIdx] = false;
    }
    return ret;
  }


  public int solution(int[][] ability) {
    init(ability);
    return findBest(0, ability);
  }

}
