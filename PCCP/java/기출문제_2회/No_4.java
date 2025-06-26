package com.kt.aicare.common.util.PCCP.java.기출문제_2회;
import java.util.*;

public class No_4 {

  static final int N1 = 0;
  static final int OP = 1;
  static final int N2 = 2;
  static final int ANS = 4;
  int minDigit = 2;
  int maxDigit = 9;

  int calculate(int n1, int n2, String op) {
    return op.equals("+") ? n1 + n2 : n1 - n2;
  }

  int convertTo(int num10, int digit) {
    StringBuffer sb = new StringBuffer();
    while (num10 > 0) {
      int buf = num10 % digit;
      num10 = num10 / digit;
      sb.append(buf);
    }

    int ret = 0;
    String retStr = sb.reverse().toString();
    if (!"".equals(retStr)) {
      ret = Integer.valueOf(retStr);
    }

    return ret;
  }

  int calculate(int n1, int n2, String op, int digit) {
    return convertTo(calculate(n1, n2, op), digit);
  }

  int convertTo10(String nStr, int digit) {
    System.out.print("convertTo10 START... nStr: " + nStr + "(" + digit + ")");
    int ret = 0;
    char[] chars = nStr.toCharArray();
    for (int i = 0 ; i < chars.length; i++) {
      int buf = (int)chars[i] - '0';
      if (buf >= digit) {
        ret = -1;
        break;
      }
      ret *= digit;
      ret += buf;
    }
    return ret;
  }

  void updateRange(String[] expr) {
    int ans = Integer.valueOf(expr[ANS]);
    int minLocal = 9;
    int maxLocal = 2;
    for (int cand = minDigit; cand <= maxDigit; cand++) {
      int n1 = convertTo10(expr[N1], cand);
      int n2 = convertTo10(expr[N2], cand);
      if (n1 == -1 || n2 == -1) {
        continue;
      }
      int calculated = calculate(n1, n2, expr[OP], cand);
      if (calculated == ans) {
        minLocal = Math.min(cand, minLocal);
        maxLocal = Math.max(cand, maxLocal);
      }
    }
    minDigit = Math.max(minDigit, minLocal);
    maxDigit = Math.min(maxDigit, maxLocal);
  }

  int findMax(String str) {
    int ret = 0;
    char[] chars = str.toCharArray();
    for (char ch : chars) {
      if (ch < '0' || ch > '9') {
        continue;
      }
      ret = Math.max(ret, ch - '0' + 1);
    }
    return ret;
  }

  public List<String> solution(String[] expressions) {
    List<String> answer = new ArrayList<>();
    List<String[]> todo = new ArrayList<>();
    minDigit = 2;
    maxDigit = 9;

    int cand = 0;
    for (String expr : expressions) {
      cand = Math.max(cand, findMax(expr));
      String[] current = expr.split(" ");
      if ("X".equals(current[ANS])) {
        todo.add(current);
      } else {
        updateRange(current);
      }
    }
    minDigit = Math.max(minDigit, cand);

    for (String[] expr: todo) {
      int n1 = convertTo10(expr[N1], minDigit);
      int n2 = convertTo10(expr[N2], minDigit);
      int ans = calculate(n1, n2, expr[OP], minDigit);
      String ansStr = String.valueOf(ans);
      for (int digit = minDigit + 1; digit <= maxDigit; digit++) {
        n1 = convertTo10(expr[N1], digit);
        n2 = convertTo10(expr[N2], digit);
        int calculated = calculate(n1, n2, expr[OP], digit);
        if (ans != calculated) {
          ansStr = "?";
          break;
        }
      }
      answer.add(String.format("%s %s %s = %s", expr[N1], expr[OP], expr[N2], ansStr));
    }

    return answer;
  }
}
