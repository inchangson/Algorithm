package com.kt.aicare.common.util.programmers.GRAPH;
import java.util.*;

public class 가장_먼_노드 {

  final int NODE = 0;
  final int LENG = 1;
  final int EMPTY = -1;
  int nodeCnt = 0;
  List<Set<Integer>> relation = new ArrayList<>();
  List<Integer> visited = new ArrayList<>();

  void initData(int n, int[][] edge) {
    nodeCnt = n;
    relation = new ArrayList<>();
    visited = new ArrayList<>();
    for (int i = 0; i < nodeCnt + 1; i++) {
      relation.add(new HashSet<>());
      visited.add(EMPTY);
    }
    for (int[] e : edge) {
      int nodeA = e[0];
      int nodeB = e[1];
      relation.get(nodeA).add(nodeB);
      relation.get(nodeB).add(nodeA);
    }
  }

  void getResult() {
    Deque<int[]> paths = new LinkedList<>();
    Map<Integer, Integer> cache = new HashMap<>();
    paths.offerLast(new int[]{1, 0});
    visited.set(1, 0);
    while(!paths.isEmpty()) {
      int[] current = paths.pollFirst();
      for (Integer nextNode : relation.get(current[NODE])) {
        if (visited.get(nextNode) != EMPTY)
          continue;
        paths.offerLast(new int[]{nextNode, current[LENG] + 1});
        visited.set(nextNode, current[LENG] + 1);
      }
    }
  }

  public int solution(int n, int[][] edge) {
    initData(n, edge);
    getResult();
    int answer = 0;
    int mx = 0;
    for (int v : visited) {
      mx = Math.max(mx, v);
    }

    for (int v : visited) {
      if (v == mx) {
        answer++;
      }
    }


    return answer;
  }
}
