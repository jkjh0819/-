#ifndef __hw09_world_clock_
#define __hw09_world_clock_

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <fstream>

using namespace std;

class WorldClock {
 public:
  WorldClock();
  WorldClock(int hour, int minute, int second);

  void Tick(int seconds = 1);
  // 잘못된 값 입력시 false 리턴하고 원래 시간은 바뀌지 않음.
  bool SetTime(int hour, int minute, int second);

  bool LoadTimezoneFromFile(const string& file_path); 
  void SaveTimezoneToFile(const string& file_path); 
  void AddTimezoneInfo(const string& city, int diff);

  // 잘못된 값 입력시 false 리턴하고 원래 시간은 바뀌지 않음.
  bool SetTimezone(const string& timezone);

  int hour() const;
  int minute() const;
  int second() const;
  int time_difference() const { return time_difference_; }

 private:
  // 여기에 시각 관련 멤버 변수 정의. (GMT 시간을 사용)
	 int time_;
  // Timezone 관련 정보는 아래 변수에 저장. 시차는 시간 단위로만 계산.
  int time_difference_;
  map<string, int> timezone_;
};

struct InvalidTimeException {
  string input_time;
  InvalidTimeException(const string& str) : input_time(str) {}
};

// hh:mm:ss 형식으로 입출력. 표준시가 아닌 경우 (+xx)/(-xx) 형식으로 시차를 표시.
ostream& operator<<(ostream& os, const WorldClock& c);

// hh:mm:ss 로 입력받음.
// 사용자 입력 오류시 >> operator는 InvalidDateException을 발생할 수 있음.
istream& operator>>(istream& is, WorldClock& c);

//* 필요시 private 멤버 변수 및 함수 추가 가능. friend는 사용금지.

#endif

