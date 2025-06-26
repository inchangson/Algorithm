package com.kt.aicare.common.util.PCCP.java.기출문제_2회;

public class No_1 {
  int cursor;
  int endTime;
  int openingStart;
  int openingEnd;

  String convertToMinSec(int input) {
    return String.format("%02d:%02d", input / 60, input % 60);
  }

  int convertToSec(String input) {
    String[] splited = input.split(":");
    return Integer.parseInt(splited[0]) * 60 + Integer.parseInt(splited[1]);
  }

  void initData(String video_len, String pos, String op_start, String op_end) {
    endTime = convertToSec(video_len);
    cursor = convertToSec(pos);
    openingStart = convertToSec(op_start);
    openingEnd = convertToSec(op_end);
    // System.out.println(String.format("%s -> %ds -> %s", video_len, endTime, convertToMinSec(endTime)));
  }

  void checkOpening() {
    if (cursor < openingStart || cursor > openingEnd) {
      return;
    }
    cursor = openingEnd;
  }

  void prev() {
    cursor -= 10;
    if (cursor < 10) {
      cursor = 0;
    }
    checkOpening();
  }

  void next() {
    cursor += 10;
    if (cursor > (endTime - 10)) {
      cursor = endTime;
    }
    checkOpening();
  }

  // 시간 문제는 sec로 바꾸어 계산하는 게 편리하다.
  public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
    String answer = "";
    initData(video_len, pos, op_start, op_end);

    checkOpening();
    for (String comm : commands) {
      if (comm.equals("prev")) {
        prev();
      } else {
        next();
      }
    }
    return convertToMinSec(cursor);
  }
}
