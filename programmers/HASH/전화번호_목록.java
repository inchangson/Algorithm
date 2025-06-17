package programmers.HASH;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class 전화번호_목록 {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book);
        for (int i = 0; i < phone_book.length - 1; i++) {
            String current = phone_book[i];
            String next = phone_book[i + 1];
            if (next.startsWith(current)) {
                answer = false;
                break;
            }
        }
        return answer;
    }
}

// 내 답안
// 정확성  테스트
// 테스트 1 〉	통과 (0.45ms, 68.1MB)
// 테스트 2 〉	통과 (0.30ms, 90.5MB)
// 테스트 3 〉	통과 (0.30ms, 87.8MB)
// 테스트 4 〉	통과 (0.39ms, 78.6MB)
// 테스트 5 〉	통과 (0.30ms, 72MB)
// 테스트 6 〉	통과 (0.27ms, 81.3MB)
// 테스트 7 〉	통과 (0.28ms, 82.3MB)
// 테스트 8 〉	통과 (0.30ms, 79.7MB)
// 테스트 9 〉	통과 (0.41ms, 81.4MB)
// 테스트 10 〉	통과 (0.29ms, 78.3MB)
// 테스트 11 〉	통과 (0.31ms, 76.1MB)
// 테스트 12 〉	통과 (0.29ms, 79.6MB)
// 테스트 13 〉	통과 (0.34ms, 76.1MB)
// 테스트 14 〉	통과 (3.54ms, 79.3MB)
// 테스트 15 〉	통과 (5.42ms, 89.7MB)
// 테스트 16 〉	통과 (8.19ms, 93.3MB)
// 테스트 17 〉	통과 (14.34ms, 82.8MB)
// 테스트 18 〉	통과 (10.59ms, 83.9MB)
// 테스트 19 〉	통과 (5.86ms, 79.5MB)
// 테스트 20 〉	통과 (9.71ms, 79.2MB)
// 효율성  테스트
// 테스트 1 〉	통과 (20.37ms, 59.9MB)
// 테스트 2 〉	통과 (17.15ms, 59MB)
// 테스트 3 〉	통과 (529.92ms, 246MB)
// 테스트 4 〉	통과 (437.52ms, 155MB)

// 변경 답안
// 정확성  테스트
// 테스트 1 〉	통과 (0.04ms, 80.8MB)
// 테스트 2 〉	통과 (0.04ms, 79.1MB)
// 테스트 3 〉	통과 (0.04ms, 81MB)
// 테스트 4 〉	통과 (0.06ms, 87.3MB)
// 테스트 5 〉	통과 (0.04ms, 79.6MB)
// 테스트 6 〉	통과 (0.04ms, 83.4MB)
// 테스트 7 〉	통과 (0.03ms, 76MB)
// 테스트 8 〉	통과 (0.04ms, 87.4MB)
// 테스트 9 〉	통과 (0.04ms, 89.1MB)
// 테스트 10 〉	통과 (0.05ms, 91.1MB)
// 테스트 11 〉	통과 (0.04ms, 89.8MB)
// 테스트 12 〉	통과 (0.05ms, 76.4MB)
// 테스트 13 〉	통과 (0.04ms, 83.9MB)
// 테스트 14 〉	통과 (1.65ms, 85.3MB)
// 테스트 15 〉	통과 (2.00ms, 76.3MB)
// 테스트 16 〉	통과 (2.35ms, 83.3MB)
// 테스트 17 〉	통과 (2.63ms, 73.6MB)
// 테스트 18 〉	통과 (3.04ms, 92MB)
// 테스트 19 〉	통과 (3.31ms, 85MB)
// 테스트 20 〉	통과 (5.48ms, 84.8MB)
// 효율성  테스트
// 테스트 1 〉	통과 (15.47ms, 58.9MB)
// 테스트 2 〉	통과 (15.42ms, 58.3MB)
// 테스트 3 〉	통과 (358.82ms, 99.2MB)
// 테스트 4 〉	통과 (304.56ms, 97.2MB)