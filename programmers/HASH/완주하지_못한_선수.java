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
        
        for (String k : result.keySet()) {
            answer = k;
        }
        
        return answer;
    }
    
    private static void incrementMap(String k, Map<String, Integer> m) {
        if (m.containsKey(k)) {
            m.put(k, m.get(k) + 1);
        } else {
            m.put(k, 1);
        }
    }
    
    private static void decrementMap(String k, Map<String, Integer> m) {
        int prev = m.get(k);
        // assert prev <= 0
        if (prev == 1) {
            m.remove(k);
        } else {
            m.put(k, prev - 1);
        }
    }
}
