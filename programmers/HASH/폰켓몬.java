package programmers.HASH;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

public class 폰켓몬 {
    public int solution(int[] nums) {
        return Arrays.stream(nums)
                .boxed()
                .collect(
                    Collectors.collectingAndThen(
                        Collectors.toSet(),
                        phonekemons 
                        -> Integer.min(phonekemons.size(), 
                                       nums.length / 2)));
    }
}
// 내 답안
// 정확성 테스트
// 테스트 1 〉	통과 (0.05ms, 70.9MB)
// 테스트 2 〉	통과 (0.05ms, 73.2MB)
// 테스트 3 〉	통과 (0.06ms, 73.6MB)
// 테스트 4 〉	통과 (0.09ms, 88.5MB)
// 테스트 5 〉	통과 (0.11ms, 81MB)
// 테스트 6 〉	통과 (0.12ms, 77.6MB)
// 테스트 7 〉	통과 (0.23ms, 86MB)
// 테스트 8 〉	통과 (0.26ms, 78.4MB)
// 테스트 9 〉	통과 (0.29ms, 77.8MB)
// 테스트 10 〉	통과 (0.42ms, 92.5MB)
// 테스트 11 〉	통과 (0.17ms, 84MB)
// 테스트 12 〉	통과 (0.36ms, 91.7MB)
// 테스트 13 〉	통과 (0.50ms, 88.7MB)
// 테스트 14 〉	통과 (0.58ms, 87MB)
// 테스트 15 〉	통과 (1.00ms, 87.3MB)
// 테스트 16 〉	통과 (6.26ms, 76.3MB)
// 테스트 17 〉	통과 (6.24ms, 89.5MB)
// 테스트 18 〉	통과 (3.18ms, 88.1MB)
// 테스트 19 〉	통과 (4.40ms, 75.1MB)
// 테스트 20 〉	통과 (4.27ms, 79MB)

// 변경 답안
// 테스트 1 〉	통과 (2.55ms, 93.9MB)
// 테스트 2 〉	통과 (2.83ms, 87.8MB)
// 테스트 3 〉	통과 (1.80ms, 73.9MB)
// 테스트 4 〉	통과 (1.83ms, 72.1MB)
// 테스트 5 〉	통과 (2.01ms, 97.7MB)
// 테스트 6 〉	통과 (2.77ms, 74.3MB)
// 테스트 7 〉	통과 (2.05ms, 75.7MB)
// 테스트 8 〉	통과 (2.22ms, 77.4MB)
// 테스트 9 〉	통과 (3.62ms, 92.3MB)
// 테스트 10 〉	통과 (3.28ms, 77.7MB)
// 테스트 11 〉	통과 (2.37ms, 75.5MB)
// 테스트 12 〉	통과 (2.56ms, 80.6MB)
// 테스트 13 〉	통과 (3.23ms, 86MB)
// 테스트 14 〉	통과 (2.54ms, 86MB)
// 테스트 15 〉	통과 (2.76ms, 89.7MB)
// 테스트 16 〉	통과 (7.00ms, 97.2MB)
// 테스트 17 〉	통과 (10.36ms, 77.1MB)
// 테스트 18 〉	통과 (7.72ms, 84.3MB)
// 테스트 19 〉	통과 (5.95ms, 76.1MB)
// 테스트 20 〉	통과 (5.49ms, 84.7MB)