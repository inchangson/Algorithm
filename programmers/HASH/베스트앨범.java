package com.kt.aicare.common.util.programmers.HASH;
import java.util.*;
import java.util.stream.*;

public class 베스트앨범 {

    public List<Integer> solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();

        Map<String, Integer> genreMap = new HashMap<>();
        Map<String, List<int[]>> songMap = new HashMap<>();

        for (int no = 0; no < genres.length; no++) {
            String g = genres[no];
            int p = plays[no];
            genreMap.put(g, genreMap.getOrDefault(g, 0) + p);
            if (!songMap.containsKey(g)) {
                songMap.put(g, new ArrayList<int[]>());
            }
            songMap.get(g).add(new int[]{no, p});
        }

        List<Map.Entry<String, Integer>> genreList = genreMap.entrySet()
            .stream()
            .sorted((e1, e2) -> e2.getValue().compareTo(e1.getValue()))
            .collect(Collectors.toList());

        for (Map.Entry<String, Integer> genre : genreList) {
            List<int[]> target = songMap.get(genre.getKey());
            if (target.size() == 1) {
                answer.add(target.get(0)[0]);
                continue;
            }
            target.sort((o1, o2) -> {return o2[1] - o1[1];});
            answer.add(target.get(0)[0]);
            answer.add(target.get(1)[0]);
        }
        return answer;
    }
}
