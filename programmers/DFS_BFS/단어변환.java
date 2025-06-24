package com.kt.aicare.common.util.programmers.DFS_BFS;
import java.util.*;

public class 단어변환 {
  int findIdxOf(String goal, String[] src) {
    for (int i = 0; i < src.length; i++) {
      if (src[i].equals(goal)) {
        return i;
      }
    }
    return -1;
  }

  boolean isConvertable(String s1, String s2) {
    char[] s1Arr = s1.toCharArray();
    char[] s2Arr = s2.toCharArray();
    int diffCnt = 0;
    for (int i = 0; i < s1Arr.length; i++) {
      if (s1Arr[i] == s2Arr[i]) continue;
      diffCnt++;
      if (diffCnt > 1) {
        return false;
      }
    }
    return true;
  }

  void updateQue(String curWord, int curStep, boolean[] used, String[] words, Deque<int[]> conversion) {
    for (int i = 0; i < words.length; i++) {
      if (used[i])    continue;
      if (!isConvertable(curWord, words[i]))  continue;
      used[i] = true;
      conversion.offerLast(new int[]{i, curStep + 1});
    }
  }

  public int solution(String begin, String target, String[] words) {
    int answer = 0;
    boolean[] used = new boolean[words.length];
    Deque<int[]> conversion = new LinkedList<>();
    final int IDX = 0;
    final int STEPS = 1;

    int targetIdx = findIdxOf(target, words);
    if (targetIdx == -1) return 0;

    updateQue(begin, 0, used, words, conversion);

    while(!conversion.isEmpty()){
      int[] current = conversion.pollFirst();
      String curWord = words[current[IDX]];
      if (current[IDX] == targetIdx) return current[STEPS];

      updateQue(curWord, current[STEPS], used, words, conversion);
    }

    return answer;
  }

}
