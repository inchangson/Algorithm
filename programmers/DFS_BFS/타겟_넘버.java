package com.kt.aicare.common.util.programmers.DFS_BFS;

public class 타겟_넘버 {
  int goal = 0;
  int cnt = 0;
  void initData(int target) {
    goal = target;
    cnt = 0;
  }

  void generateHelper(int curIdx, int cache, int[] numbers) {
    if (curIdx == numbers.length) {
      if (cache == goal) {
        cnt++;
      }
      return;
    }

    generateHelper(curIdx + 1, cache + numbers[curIdx], numbers);
    generateHelper(curIdx + 1, cache - numbers[curIdx], numbers);
  }

  public int solution(int[] numbers, int target) {
    initData(target);
    generateHelper(0, 0, numbers);
    return cnt;
  }

}
