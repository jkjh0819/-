//2015004257
#include <iostream>
#include <stdio.h>
#include <string>
#pragma warning(disable: 4996)

using namespace std;

struct Save{
	int divisor; int square;
};

string primeFactorization(unsigned int _number)
{
	string ret;
	if(_number==1)
	{
		ret = "1^1";
		return ret;
	}
	for (int divisor = 2; _number > 1; divisor++)
	{
		char t_string[256];
		Save save;
		if (_number%divisor == 0)
		{
			if (!ret.empty())
				ret.append(" x ");
			save.divisor = divisor;
			save.square = 0;
			while (_number%divisor == 0)
			{
				save.square++;
				_number = _number / divisor;
			}
			sprintf(t_string, "%d^%d", save.divisor, save.square);
			ret.append(t_string);
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	if (argc < 1) return -1;
	unsigned int number;
	sscanf(argv[1], "%u", &number);
	cout << primeFactorization(number) << endl;
	return 0;
}
