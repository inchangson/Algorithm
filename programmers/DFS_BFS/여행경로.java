package com.kt.aicare.common.util.programmers.DFS_BFS;
import java.util.*;

public class 여행경로 {
  LinkedList<String[]> flights;
  LinkedList<String> answer;
  int FROM = 0; int TO = 1;

  void initData(String[][] tickets) {
    flights = new LinkedList<>();
    for (String[] ticket : tickets) flights.add(ticket);
    answer = new LinkedList<>();
  }

  void updateAnswer(LinkedList<String> cache) {
    if (answer.isEmpty()) {
      answer = new LinkedList<>(cache);
      return;
    }
    for (int i = 0; i < cache.size(); i++) {
      int cmpRslt = answer.get(i).compareTo(cache.get(i));

      if (cmpRslt == 0) continue;
      if (cmpRslt > 0) {
        answer = new LinkedList<>(cache);
      }
      return;
    }
  }

  void getPlan(LinkedList<String> cache) {
    if (flights.isEmpty()) {
      updateAnswer(cache);
      return;
    }
    String current = cache.peekLast();
    for (int nxt = 0; nxt < flights.size(); nxt++) {
      String[] flight = flights.get(nxt);
      if (!flight[FROM].equals(current)) continue;
      cache.offerLast(flight[TO]);
      flights.remove(nxt);
      getPlan(cache);
      flights.add(nxt, flight);
      cache.pollLast();
    }
  }

  public String[] solution(String[][] tickets) {
    initData(tickets);
    LinkedList<String> cache = new LinkedList<>();
    cache.offerLast("ICN");
    getPlan(cache);
    return answer.toArray(new String[0]);
  }

}
