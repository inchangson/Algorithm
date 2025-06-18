package programmers.HASH;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class 의상 {
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String, Integer> closet = new HashMap<>();
        for (int i = 0; i < clothes.length; i++) {
            String type = clothes[i][1];
            closet.put(type, closet.getOrDefault(type, 0) + 1);
        }
        
        List<Integer> cnts = new ArrayList<>(closet.values());
        
        for (int cnt : cnts) {
            answer *= cnt + 1;
        }
        
        return answer - 1;
    }
    
}
