#include "parse_radix.h"

int ParseRadix(const string& number)
{
	int pos = number.find("_"),radix;		
	string target;
	if (pos!=string::npos)	//_뒤에있는 진법을 저장한다.
	{
		target = number.substr(0, pos);
		radix = atoi(number.substr(pos + 1).c_str());
	}
	else //_가 없을 경우 10진법
	{
		target = number.substr(0);
		radix = 10;
	}
	int result=0, square = target.size();
	for (int i = square - 1; i >= 0; i--)
	{
		char temp = target[square - (i + 1)]; //바꾸려는 숫자를 한자리씩 받는다.
		int temp_int;
		if (temp >= 'a')			//int형으로 바꾼다.
			temp_int = temp - 'a' + 10;
		else
			temp_int = temp - '0';
		if (temp_int >= radix)
			return -1;
		result += temp_int*pow(radix, i); //계산
	}
	return result;
}

string ConvertRadix(int number, int radix)
{
	list<int> qu;
	int check_negative = 0;
	if (number < 0) //음수일때 체크
	{
		check_negative = 1;
		number = -number;
	}
	while (number > 0) //진법변환
	{
		qu.push_front(number%radix);
		number = number / radix;
	}
	string result="";
	if (check_negative)
		result += '-';
	list<int>::iterator it = qu.begin();
	while (it != qu.end())
	{
		char temp; 			//int형을 char형으로 바꾸면서 string에 붙여줌.
		if (*it >= 10)
			temp = *it - 10 + 'a'; 
		else
			temp = *it + '0';
		result += temp;
		it++;
	}
	if (radix != 10)	//진법 명시
	{
		result += '_';
		result += itos(radix);
	}
	return result;
}

string itos(int number)	//itoa가 비표준이므로 그와 비슷한 역할을 하는 함수. int->string
{
	string ret="";
	list<char> save;
	while (number > 0)
	{
		int temp_int = number % 10;
		char temp = temp_int + '0';
		save.push_front(temp);
		number = number / 10;
	}
	list<char>::iterator it = save.begin();
	while (it != save.end())
	{
		ret += *it;
		it++;
	}
	return ret;
}