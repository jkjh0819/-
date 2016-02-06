#include "world_clock.h"

WorldClock::WorldClock()
{
	time_ = 0;
}
WorldClock::WorldClock(int hour, int minute, int second)
{
	time_ = hour * 3600 + minute * 60 + second;
}

void WorldClock::Tick(int seconds) 
{
	time_ += seconds;
	if (time_ >= 86400) //하루는 86400초
		time_ -= 86400;
	if (time_ < 0)
	{
		time_ = 86400 + time_;
	}
}
  // 잘못된 값 입력시 false 리턴하고 원래 시간은 바뀌지 않음.
bool WorldClock::SetTime(int hour, int minute, int second)
{
	if (hour >= 24 || hour < 0 || minute < 0 || minute >= 60 || second < 0 || second >= 60)
		return false;
	else
	{
		time_ = hour * 3600 + minute * 60 + second;
		return true;
	}
}

bool WorldClock::LoadTimezoneFromFile(const string& file_path)
{
	ifstream file;
	file.open(file_path);
	while (!file.eof()){
		string area;
		int time;
		file >> area >> time;
		if (area == "")
			break;
		timezone_.insert(make_pair(area, time));
	}
	file.close();
	return true;
}
void WorldClock::SaveTimezoneToFile(const string& file_path)
{
	ofstream SaveFile;
	SaveFile.open(file_path, ios::trunc);
	for (map<string, int>::iterator it = timezone_.begin(); it != timezone_.end(); it++)
	{
		SaveFile << it->first << ' ' << it->second << endl;
	}
	SaveFile.close();
}

void WorldClock::AddTimezoneInfo(const string& city, int diff)
{
	timezone_.insert(make_pair(city, diff));
	SaveTimezoneToFile("timezone.txt");
}

  // 잘못된 값 입력시 false 리턴하고 원래 시간은 바뀌지 않음.
bool WorldClock::SetTimezone(const string& timezone)
{
	map<string,int>::iterator it = timezone_.find(timezone);
	if (it == timezone_.end())
		return false;
	else
	{
		time_difference_ = it->second;
		return true;
	}
}

int WorldClock::hour() const
{
	return time_ / 3600;
}
int WorldClock::minute() const
{
	return (time_ % 3600) / 60;
}
int WorldClock::second() const
{
	return (time_ % 3600) % 60;
}

// hh:mm:ss 형식으로 입출력. 표준시가 아닌 경우 (+xx)/(-xx) 형식으로 시차를 표시.
ostream& operator<<(ostream& os, const WorldClock& c)
{
	if (c.time_difference() != 0)
	{
		int temp_hour = c.time_difference() + c.hour();
		if (temp_hour >= 24)
		{
			temp_hour = temp_hour - 24;
		}
		os << temp_hour << ":" << c.minute() << ":" << c.second() << " (+" << c.time_difference() << ")";
	}
	else
	{
		os << c.hour() << ':' << c.minute() << ':' << c.second();
	}
	return os;
}

// hh:mm:ss 로 입력받음.
// 사용자 입력 오류시 >> operator는 InvalidDateException을 발생할 수 있음.
istream& operator>>(istream& is, WorldClock& c)
{
	string time;
	is >> time;
	string hour = time.substr(0, time.find_first_of(':'));
	string minute = time.substr(time.find_first_of(':') + 1, time.find_last_of(':'));
	string second = time.substr(time.find_last_of(':')+1);
	if (!c.SetTime(atoi(hour.c_str()), atoi(minute.c_str()), atoi(second.c_str())))
	{
		throw InvalidTimeException(time.c_str());
		return is;
	}
	else
		return is;

}


