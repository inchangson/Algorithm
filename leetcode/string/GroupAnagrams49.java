package leetcode.string;

import java.util.*;
/**
 * GroupAnagrams49
 */
public class GroupAnagrams49 {

    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagramsMap = new HashMap<>();

        for (String s : strs) {
            char[] c = s.toCharArray();
            Arrays.sort(c);
            String sorted = new String(c);
    
            anagramsMap.computeIfAbsent(sorted, k -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(anagramsMap.values());
    }


    public static void main(String[] args) {
        GroupAnagrams49 g = new GroupAnagrams49();

        List<String[]> inputList = List.of(
            new String[] {"eat","tea","tan","ate","nat","bat"},
            new String[] {""},
            new String[] {"a"}
        );

        List<List<List<String>>> expectList = List.of(
            List.of(
                List.of("bat"),
                List.of("nat", "tan"),
                List.of("ate", "eat", "tea")
            ),
            List.of(List.of("")),
            List.of(List.of("a"))
        );

        for (int i = 0; i < inputList.size(); i++) {
            List<List<String>> actual = g.groupAnagrams(inputList.get(i));

            System.out.println("the order of elements in actual and expected could be different. only check the content");
            System.out.println("expected: " + expectList.get(i));
            System.out.println("actual: " + actual);
        }
    }
}