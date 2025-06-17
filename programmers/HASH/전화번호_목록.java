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
        List<String> phoneBook = new ArrayList<>(
            Arrays.asList(phone_book));
        Set<String> memo = new HashSet<>();
        
        phoneBook.sort(Comparator.naturalOrder());

        for (String num : phoneBook) {
            for (int curSz = 1; curSz <= num.length(); curSz++) {
                String cand = num.substring(0, curSz);
                if (memo.contains(cand)) {
                    return false;
                }
            }
            memo.add(num);
        }
        
        return answer;
    }
}
