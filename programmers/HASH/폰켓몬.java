package programmers.HASH;

import java.util.HashSet;
import java.util.Set;

public class 폰켓몬 {
    public int solution(int[] nums) {
        int answer = 0;
        Set<Integer> pokes = new HashSet<>();
        for (int n : nums) {
            pokes.add(n);
        }
        answer = Math.min(pokes.size(), nums.length/2);
        return answer;
    }
}
