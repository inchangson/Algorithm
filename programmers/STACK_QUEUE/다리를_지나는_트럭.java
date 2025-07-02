package com.kt.aicare.common.util.programmers.STACK_QUEUE;
import java.util.*;

public class 다리를_지나는_트럭 {
  final static int W = 0;// weight
  final static int T = 1;// time(들어온 시간)

  static class Bridge {
    int totalWeight;
    int weightLimit;
    int length;
    Deque<int[]> queue;

    Bridge(int weightLimit, int length) {
      this.totalWeight = 0;
      this.queue = new LinkedList<>();
      this.weightLimit = weightLimit;
      this.length = length;
    }

    boolean addTruck(int truckWeight, int curTime) {
      if ((totalWeight + truckWeight) > weightLimit) {
        return false;
      }

      this.queue.offerLast(new int[]{truckWeight, curTime});
      this.totalWeight += truckWeight;
      return true;
    }

    boolean removeTruck(int curTime) {
      if (this.queue.isEmpty()) {
        return false;
      }
      int[] cur = this.queue.peek();
      if ((curTime - cur[T]) < length) {
        return false;
      }
      totalWeight -= cur[W];
      this.queue.pollFirst();
      return true;
    }

    boolean isEmpty() {
      return this.queue.isEmpty();
    }

    public String toString() {
      StringBuffer sb = new StringBuffer();
      sb.append("[");
      for (int[] elem : this.queue) {
        sb.append(String.format("(%d, %d), ", elem[W], elem[T]));
      }
      sb.append("]");
      return sb.toString();
    }
  }

  public int solution(int bridge_length, int weight, int[] truck_weights) {
    int timer = 0;

    Deque<Integer> readyQueue = new LinkedList<>();
    Bridge bridge = new Bridge(weight, bridge_length);

    for (int truckWeight : truck_weights) {
      readyQueue.offerLast(truckWeight);
    }

    while(!readyQueue.isEmpty() ||
        !bridge.isEmpty()) {
      bridge.removeTruck(timer);
      if (!readyQueue.isEmpty()) {
        int curWeight = readyQueue.peekFirst();
        if (bridge.addTruck(curWeight, timer)) {
          readyQueue.pollFirst();
        }
      }
      timer++;
    }

    return timer;
  }

}
