#include "calendar.h"

void Date::NextDay(int n) 
{
	if (n < 0) //음수이면 뒤로가는 함수 호출 
	{
		while (n++)
			this->bDay();
	}
	else{ //아닐경우 앞으로 가는 함수 호출 
		while (n--)
			this->nDay();
	}
}
bool Date::SetDate(int year, int month, int day)
{
	if (month < 1 || month>12)
		return false;
	if (GetDaysInMonth(month, year) < day || !(day)) //날짜가 올바르지 않은경우
		return false;
	year_ = year; month_ = month; day_ = day;
	return true;
}

int Date::year() const { return year_; }
int Date::month() const { return month_; }
int Date::day() const {	return day_; }

void Date::nDay() //날짜가 앞으로 가는 함수 
{
	this->day_++;
	if (this->day_ > this->GetDaysInMonth(this->month_,this->year_))
	{
		this->month_++;
		this->day_ = 1;
	}
	if (this->month_ > 12)
	{
		this->month_ = 1;
		this->year_++;
	}
}

void Date::bDay()//날짜가 뒤로 가는 함수 
{
	this->day_--;
	if (this->day_ < 1 )
	{
		this->month_--;
		if (this->month_ < 1)
		{
			this->month_ = 12;
			this->year_--;
		}
		this->day_ = this->GetDaysInMonth(this->month_, this->year_);
	}	
}

  // 윤년을 판단하여 주어진 연도에 해당하는 날짜 수(365 또는 366)를 리턴.
int Date::GetDaysInYear(int year)
{
	if (!(year % 4))
	{
		if (!(year % 100) && year % 400) return 365;
		else return 366;
	} 
	else return 365; 
}
  // 해당 날짜가 해당 연도의 처음(1월 1일)부터 며칠째인지를 계산.
int Date::ComputeDaysFromYearStart(int year, int month, int day)
{
	int date = 0, temp_year = year, temp_month = 1, temp_day = 1;
	int m[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (GetDaysInYear(year) == 366) m[1]++;
	while (temp_month != month && temp_day != day)
	{
		temp_day++;
		if (temp_day > m[month])
		{
			temp_month++;
			temp_day = 1;
		}
		date++;
	}
	return date;
}


// yyyy.mm.dd 형식으로 입출력.
// 사용자 입력 오류시 >> operator는 InvalidDateException을 발생할 수 있음.
ostream& operator<<(ostream& os, const Date& c)
{
	os << c.year() << "." << c.month() << "." << c.day();
	return os;
}
istream& operator>>(istream& is, Date& c)
{
	string str;
	is >> str;
	int first = str.find_first_of('.');
	int last = str.find_last_of('.');
	if (!c.SetDate(atoi(str.substr(0, first).c_str()),
		atoi(str.substr(first + 1, last - first - 1).c_str()),
		atoi(str.substr(last + 1, str.size()).c_str())))
	{
		throw InvalidDateException(str);
		return is;
	}
	else
		return is;
}
