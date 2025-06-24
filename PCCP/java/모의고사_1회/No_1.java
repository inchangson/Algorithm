package com.kt.aicare.common.util.PCCP.java.모의고사_1회;
import java.util.*;

public class No_1 {
  public String solution(String input_string) {
    char[] chars = input_string.toCharArray();
    Set<Character> memo = new HashSet<>();
    Set<Character> alone = new TreeSet<>();
    char pre = ' ';
    for (int i = 0; i < chars.length; i++) {
      char c = chars[i];
      if (pre == c) continue;
      if (memo.contains(c)) alone.add(c);
      else memo.add(c);
      pre = c;
    }

    if (alone.size() == 0)  return "N";
    Iterator<Character> iter = alone.iterator();
    StringBuffer sb = new StringBuffer();
    for (int i = 0; iter.hasNext(); i++) {
      sb.append(iter.next());
    }
    return sb.toString();
  }

}
