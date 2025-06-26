package com.kt.aicare.common.util.PCCP.java.기출문제_2회;

public class No_1 {
  static class Cursor {
    int min; int sec;
    int endMin; int endSec;
    int opStartMin; int opStartSec;
    int opEndMin; int opEndSec;

    int[] parseToIntArr(String time) {
      String[] splited = time.split(":");
      return new int[]{Integer.valueOf(splited[0]), Integer.valueOf(splited[1])};
    }

    Cursor(String video_len, String pos, String op_start, String op_end) {
      final int M = 0; final int S = 1;
      int[] current = parseToIntArr(pos);
      int[] videoEnd = parseToIntArr(video_len);
      int[] openingStart = parseToIntArr(op_start);
      int[] openingEnd = parseToIntArr(op_end);
      min = current[M];               sec = current[S];
      endMin = videoEnd[M];           endSec = videoEnd[S];
      opStartMin = openingStart[M];   opStartSec = openingStart[S];
      opEndMin = openingEnd[M];       opEndSec = openingEnd[S];

      if (isOpeningRange()) {
        min = opEndMin;
        sec = opEndSec;
      }
    }

    boolean isOpeningRange() {
      if (opStartMin > min || opEndMin < min) {
        return false;
      }
      if (opStartMin == min && opStartSec > sec) {
        return false;
      }
      if (opEndMin == min && opEndSec < sec) {
        return false;
      }
      return true;
    }

    void prev() {
      sec = sec - 10;
      if (sec < 0) {
        if (min <= 0) {
          min = 0;
          sec = 0;
          return;
        }
        min--;
        sec += 60;
      }
      if(min == 0 && sec < 10) {
        min = 0; sec = 0;
      }
      if (isOpeningRange()) {
        min = opEndMin;
        sec = opEndSec;
      }
    }

    void next() {
      sec += 10;
      if (min == endMin && sec >= endSec) {
        sec = endSec;
        return;
      }

      if (sec > 59) {
        min++;
        sec -= 60;
      }
      if (min == endMin && (endSec - sec) < 10 ) {
        min = endMin;
        sec = endSec;
      }
      if (isOpeningRange()) {
        min = opEndMin;
        sec = opEndSec;
      }
    }

    String getPosStr() {
      return String.format("%02d:%02d", min, sec);
    }
  }

  public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
    String answer = pos;
    Cursor cursor = new Cursor(video_len, pos, op_start, op_end);
    for (String command : commands) {
      // System.out.print("before: " + cursor.getPosStr());
      if ("prev".equals(command)) cursor.prev();
      else cursor.next();
      // System.out.print(" -> after : " + cursor.getPosStr());
      System.out.println();
    }
    return cursor.getPosStr();
  }

}
