package programmers.HASH;

import java.util.HashMap;
import java.util.Map;

public class 완주하지_못한_선수  {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> result = new HashMap<>();
        
        for (String p : participant) {
            incrementMap(p, result);
        }
        
        for (String c : completion) {
            decrementMap(c, result);
        }
        
        for (Map.Entry<String, Integer> kV : result.entrySet()) {
            if (kV.getValue() > 0)
                answer = kV.getKey();
        }
        
        return answer;
    }
    
    private static void incrementMap(String k, Map<String, Integer> m) {
        m.put(k, m.getOrDefault(k, 0) + 1);
    }
    
    private static void decrementMap(String k, Map<String, Integer> m) {
        m.put(k, m.get(k) - 1);
    }
}
// 내 답안
// 채점을 시작합니다.
// 정확성  테스트
// 테스트 1 〉	통과 (0.07ms, 76.4MB)
// 테스트 2 〉	통과 (0.09ms, 94.9MB)
// 테스트 3 〉	통과 (0.45ms, 80.6MB)
// 테스트 4 〉	통과 (0.71ms, 75.9MB)
// 테스트 5 〉	통과 (0.80ms, 88.3MB)
// 테스트 6 〉	통과 (0.04ms, 82.3MB)
// 테스트 7 〉	통과 (0.10ms, 80.1MB)
// 효율성  테스트
// 테스트 1 〉	통과 (30.30ms, 84.8MB)
// 테스트 2 〉	통과 (53.92ms, 89.5MB)
// 테스트 3 〉	통과 (104.25ms, 97MB)
// 테스트 4 〉	통과 (59.63ms, 96.6MB)
// 테스트 5 〉	통과 (63.80ms, 102MB)

// 변경 답안
// 정확성  테스트
// 테스트 1 〉	통과 (0.06ms, 85.1MB)
// 테스트 2 〉	통과 (0.08ms, 74MB)
// 테스트 3 〉	통과 (0.63ms, 88.7MB)
// 테스트 4 〉	통과 (1.19ms, 75.9MB)
// 테스트 5 〉	통과 (1.49ms, 78.5MB)
// 테스트 6 〉	통과 (0.04ms, 74.2MB)
// 테스트 7 〉	통과 (0.05ms, 71.1MB)
// 효율성  테스트
// 테스트 1 〉	통과 (49.10ms, 99.7MB)
// 테스트 2 〉	통과 (69.39ms, 89.8MB)
// 테스트 3 〉	통과 (65.03ms, 96.4MB)
// 테스트 4 〉	통과 (71.99ms, 113MB)
// 테스트 5 〉	통과 (76.07ms, 97.8MB)
