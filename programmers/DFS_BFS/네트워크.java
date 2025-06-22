package com.kt.aicare.common.util.programmers.DFS_BFS;

public class 네트워크 {
  boolean[] visited = new boolean[200];
  int NODE_CNT = 0;

  void initData(int nodeCnt) {
    NODE_CNT = nodeCnt;
    for (int i = 0; i < NODE_CNT; i++) {
      visited[i] = false;
    }
  }

  void conquer(int curNode, int[][] computers) {
    visited[curNode] = true;
    for (int nextNode = 0; nextNode < NODE_CNT; nextNode++) {
      if (!visited[nextNode] && computers[curNode][nextNode] == 1) {
        conquer(nextNode, computers);
      }
    }
  }

  public int solution(int n, int[][] computers) {
    int answer = 0;
    initData(n);
    for (int curNode = 0; curNode < NODE_CNT; curNode++) {
      if (!visited[curNode]) {
        conquer(curNode, computers);
        answer++;
      }
    }
    return answer;
  }

}
