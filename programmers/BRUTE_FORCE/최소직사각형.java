package com.kt.aicare.common.util.programmers.BRUTE_FORCE;

public class 최소직사각형 {

  static class Card {
    int w;
    int h;
    Card(int w, int h) {
      this.w = w;
      this.h = h;
    }

    int getArea() {
      return w * h;
    }
  }

  Card getCard(Card answer, int w, int h) {
    w = Math.max(answer.w, w);
    h = Math.max(answer.h, h);
    return new Card(w, h);
  }

  Card getSmaller(Card card1, Card card2) {
    int area1 = card1.getArea();
    int area2 = card2.getArea();
    if (area1 < area2) {
      return card1;
    } else {
      return card2;
    }
  }

  public int solution(int[][] sizes) {
    Card answer = new Card(0, 0);
    for(int[] size : sizes) {
      Card cand1 = getCard(answer, size[0], size[1]);
      Card cand2 = getCard(answer, size[1], size[0]);
      answer = getSmaller(cand1, cand2);
    }
    return answer.getArea();
  }
}
