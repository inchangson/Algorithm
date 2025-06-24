package com.kt.aicare.common.util.programmers.HEAP;
import java.util.*;

public class 디스크_컨트롤러 {
  void printQueue(PriorityQueue<int[]> pq) {
    Deque<int[]> cache = new LinkedList<>();
    while(!pq.isEmpty()) cache.offerLast(pq.poll());
    System.out.println("printQueue");
    for (int[] c : cache) {
      System.out.println(String.format("%d %d %d", c[0], c[1], c[2]));
    }
    while(!pq.isEmpty()) pq.offer(cache.pollFirst());
  }

  PriorityQueue<int[]> getJobsQueue(int[][] jobs) {
    PriorityQueue<int[]> ret = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
    for (int no = 0; no < jobs.length; no++) {
      ret.offer(new int[]{no, jobs[no][0], jobs[no][1]});
    }
    return ret;
  }

  void updateJobs(int curTime, PriorityQueue<int[]> j, PriorityQueue<int[]> s) {
    while (!j.isEmpty()) {
      if (curTime < j.peek()[1]) {
        return;
      }
      s.offer(j.poll());
    }
  }

  public int solution(int[][] jobs) {
    int totalReturnTime = 0;
    // no, start, work
    PriorityQueue<int[]> scheduler = new PriorityQueue<>((o1, o2) -> {
      if (o1[2] != o2[2]) return o1[2] - o2[2];
      if (o1[1] != o2[1]) return o1[1] - o2[1];
      return o1[0] - o2[0];
    }
    );
    PriorityQueue<int[]> jobsQueue = getJobsQueue(jobs);
    // printQueue(jobsQueue);
    int curEndTime = 0;
    for (int t = 0; t < (500 * 1000 + 1); t++) {
      updateJobs(t, jobsQueue, scheduler);
      if (scheduler.isEmpty()) continue;
      if (curEndTime > t) continue;
      // System.out.println("updated scheduler at.." + t);
      // printQueue(scheduler);
      int[] curJob = scheduler.poll();
      curEndTime = t + curJob[2];
      totalReturnTime += (curEndTime - curJob[1]);
      // System.out.println(String.format("%d %d %d", curJob[0], curJob[1], curJob[2]));

    }
    return totalReturnTime / jobs.length;
  }

}
