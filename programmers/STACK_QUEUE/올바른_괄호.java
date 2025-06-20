package com.kt.aicare.common.util.programmers.STACK_QUEUE;

public class 올바른_괄호 {
  boolean solution(String s) {
    // parenthesis array
    char[] pArr = s.toCharArray();

    int curSum = 0;
    for(char p : pArr) {
      int curVal = p == '(' ? 1 : -1;
      curSum += curVal;
      if (curSum < 0) {
        return false;
      }
    }

    return curSum == 0;
  }
}
