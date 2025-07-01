package com.kt.aicare.common.util.programmers.HASH;
import java.util.*;

public class 베스트앨범 {
    Map<String, Integer> genreMap = new HashMap<>();
    Map<String, List<int[]>> songMap = new HashMap<>();

    void initData(String[] genres, int[] plays) {
        genreMap = new HashMap<>();
        songMap = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            genreMap.put(genres[i], genreMap.getOrDefault(genres[i], 0) + plays[i]);
            songMap.computeIfAbsent(genres[i], k -> new ArrayList<>()).add(new int[]{i, plays[i]});
        }
        songMap.forEach((k, v) -> v.sort((o1, o2) -> o2[1] - o1[1]));
    }

    public List<Integer> solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();

        initData(genres, plays);

        genreMap.entrySet().stream()
            .sorted((a, b) -> b.getValue() - a.getValue())
            .forEach(entry -> {
                List<int[]> songs = songMap.get(entry.getKey());
                answer.add(songs.get(0)[0]);
                if (songs.size() > 1) answer.add(songs.get(1)[0]);
            });

        return answer;
    }
}
