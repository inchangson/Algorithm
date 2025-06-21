package com.kt.aicare.common.util.programmers.SORTING;
import java.util.*;
import java.util.stream.Collectors;

public class 가장_큰_수 {
  int[] getSortedArray(int[] src) {
    List<Integer> ret = Arrays.stream(src)
        .boxed().sorted((a, b) -> {
          String s1 = String.valueOf(a) + String.valueOf(b);
          String s2 = String.valueOf(b) + String.valueOf(a);
          return s2.compareTo(s1);
        }).collect(Collectors.toList());

    return ret.stream().mapToInt(Integer::valueOf).toArray();
  }
  public String solution(int[] numbers) {
    int[] sorted = getSortedArray(numbers);
    StringBuffer sb = new StringBuffer();

    if (sorted[0] == 0) {
      sb.append(0);
    } else {
      for (int s : sorted) {
        sb.append(s);
      }
    }

    return sb.toString();
  }

}
// 내 답안
//테스트 1 〉	통과 (260.92ms, 180MB)
//테스트 2 〉	통과 (155.54ms, 126MB)
//테스트 3 〉	통과 (265.39ms, 236MB)
//테스트 4 〉	통과 (18.72ms, 98.3MB)
//테스트 5 〉	통과 (222.59ms, 150MB)
//테스트 6 〉	통과 (163.42ms, 138MB)
//테스트 7 〉	통과 (6.37ms, 87MB)
//테스트 8 〉	통과 (6.53ms, 72.2MB)
//테스트 9 〉	통과 (5.11ms, 72.1MB)
//테스트 10 〉	통과 (4.88ms, 72.7MB)
//테스트 11 〉	통과 (5.22ms, 86.2MB)
//테스트 12 〉	통과 (8.03ms, 79.6MB)
//테스트 13 〉	통과 (4.60ms, 72.8MB)
//테스트 14 〉	통과 (4.68ms, 74.2MB)
//테스트 15 〉	통과 (4.70ms, 87.5MB)

// 수정 답안 (sorted() 사용)
//테스트 1 〉	통과 (230.31ms, 191MB)
//테스트 2 〉	통과 (130.11ms, 138MB)
//테스트 3 〉	통과 (290.27ms, 212MB)
//테스트 4 〉	통과 (21.23ms, 94.6MB)
//테스트 5 〉	통과 (195.77ms, 178MB)
//테스트 6 〉	통과 (150.91ms, 156MB)
//테스트 7 〉	통과 (5.65ms, 83.8MB)
//테스트 8 〉	통과 (5.15ms, 88.2MB)
//테스트 9 〉	통과 (5.02ms, 76.2MB)
//테스트 10 〉	통과 (5.36ms, 86MB)
//테스트 11 〉	통과 (4.89ms, 71.4MB)
//테스트 12 〉	통과 (6.16ms, 89MB)
//테스트 13 〉	통과 (4.57ms, 73.1MB)
//테스트 14 〉	통과 (5.00ms, 72.9MB)
//테스트 15 〉	통과 (4.77ms, 76.6MB)

// 수정답안 (Integer[] 사용)
//테스트 1 〉	통과 (391.28ms, 188MB)
//테스트 2 〉	통과 (244.87ms, 126MB)
//테스트 3 〉	통과 (374.52ms, 222MB)
//테스트 4 〉	통과 (20.33ms, 100MB)
//테스트 5 〉	통과 (252.66ms, 168MB)
//테스트 6 〉	통과 (172.96ms, 140MB)
//테스트 7 〉	통과 (4.79ms, 82.9MB)
//테스트 8 〉	통과 (4.94ms, 87.7MB)
//테스트 9 〉	통과 (6.43ms, 71.8MB)
//테스트 10 〉	통과 (4.77ms, 91.1MB)
//테스트 11 〉	통과 (4.72ms, 84.1MB)
//테스트 12 〉	통과 (4.65ms, 73.8MB)
//테스트 13 〉	통과 (5.97ms, 85.7MB)
//테스트 14 〉	통과 (4.37ms, 73.8MB)
//테스트 15 〉	통과 (4.35ms, 82.6MB)