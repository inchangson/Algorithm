package com.kt.aicare.common.util.PCCP.java.모의고사_1회;
import java.util.*;

public class No_4 {
  final int SCORE = 0;
  final int START = 1;
  final int EXEC = 2;
  PriorityQueue<int[]> scheduler;

  void initData(int[][] program) {
    scheduler = new PriorityQueue<int[]>((o1, o2) -> {
      if(o1[SCORE] != o2[SCORE]) return o1[SCORE] - o2[SCORE];
      return o1[START] - o2[START];
    });
    Arrays.sort(program, (o1, o2) -> o1[START] - o2[START]);
  }

  void printProgram(int[] p) {
    System.out.println(String.format("score %d start %d exec %d", p[SCORE], p[START], p[EXEC]));
  }

  void printProgram(int[][] program) {
    for (int[] p : program) {
      printProgram(p);
    }
  }

  int offerSuitable(int cur, int rp, int[][] program) {
    for (int idx = rp; idx < program.length; idx++ ) {
      if (program[idx][START] > cur) return idx;
      scheduler.offer(program[idx]);
      // System.out.print("offer.. ");
      // printProgram(program[idx]);
    }
    return program.length;
  }

  public long[] solution(int[][] program) {
    long[] answer = new long[11];

    initData(program);

    int rp = 0;
    int doneCnt = 0;
    int curTime = 0;
    while (doneCnt != program.length) {
      // System.out.println("curTime" + curTime);
      rp = offerSuitable(curTime, rp, program);
      if (scheduler.isEmpty()) {
        curTime++;
        continue;
      }
      int[] curProcess = scheduler.poll();
      // System.out.print("process.. ");
      // printProgram(curProcess);
      int waitTime = curTime - curProcess[START];
      // System.out.println("wait.. " + waitTime);
      answer[curProcess[SCORE]] += waitTime;
      curTime = curTime + curProcess[EXEC];
      doneCnt++;
    }

    answer[0] = curTime;

    return answer;
  }

}
