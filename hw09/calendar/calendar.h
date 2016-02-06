#ifndef __hw09__calendar_
#define __hw09__calendar_

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Date {
 public:
	 Date() : year_(0), month_(0), day_(0){};
	 Date(int year, int month, int day) :year_(year), month_(month), day_(day){};

  void NextDay(int n = 1);
  bool SetDate(int year, int month, int day);

  int year() const;
  int month() const;
  int day() const;

 private:
	 void nDay(); 
	 void bDay();
	 int GetDaysInMonth(int month, int year) //그 달에 몇일까지 있는지 반환하는 함수
	 {
		 if (month > 12)
			 return 0;
		 int m[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		 if (month == 2 && GetDaysInYear(year) == 366)
			 return m[1] + 1;
		 return m[month-1];
	 }
	 // 윤년을 판단하여 주어진 연도에 해당하는 날짜 수(365 또는 366)를 리턴.
  static int GetDaysInYear(int year);
  // 해당 날짜가 해당 연도의 처음(1월 1일)부터 며칠째인지를 계산.
  static int ComputeDaysFromYearStart(int year, int month, int day);

  int year_, month_, day_;
};

struct InvalidDateException {
  string input_date;
  InvalidDateException(const string& str) : input_date(str) {}
};

// yyyy.mm.dd 형식으로 입출력.
// 사용자 입력 오류시 >> operator는 InvalidDateException을 발생할 수 있음.
ostream& operator<<(ostream& os, const Date& c);
istream& operator>>(istream& is, Date& c);

#endif
