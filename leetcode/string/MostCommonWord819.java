package leetcode.string;

import java.util.*;

public class MostCommonWord819 {
	private String mostCommonWord(String paragraph, String[] banned) {
		Set<String> bannedSet = Set.of(banned);
		String[] words = paragraph.toLowerCase().split("[^a-zA-Z]+");
		Map<String, Integer> countInfo = new HashMap<>();
		for (String word: words) {
			if (!bannedSet.contains(word)) {
				countInfo.put(word, countInfo.getOrDefault(word, 0) + 1);
			}
    	}

		List<String> keyList = new ArrayList<>(countInfo.keySet());
		keyList.sort((k1, k2) -> {
			return countInfo.get(k2).compareTo(countInfo.get(k1));
		});

		return keyList.getFirst();
  	}
    
	public static void main(String[] args) {
		List<String[]> bannedList = Arrays.asList(new String[] { "hit" }, new String[] { "" });
		List<String> paragraphList = Arrays.asList("Bob hit a ball, the hit BALL flew far after it was hit.","a.");
		List<String> expectedList = Arrays.asList("ball", "a");

		MostCommonWord819 lc819 = new MostCommonWord819();

		for (int i = 0; i < bannedList.size(); i++) {
			System.out.println();
			String[] banned = bannedList.get(i);
			String paragraph = paragraphList.get(i);
			String expected = expectedList.get(i);
			String actual = lc819.mostCommonWord(paragraph, banned);
			System.out.println("expected = " + expected);
			System.out.println("actual = " + actual); 
			System.out.println();
		}
	}
}
