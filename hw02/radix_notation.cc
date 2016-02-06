//2015004257
#include <stdio.h>
#include <iostream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;

string RadixNotation(unsigned int number, unsigned int radix)
{
	string ret, tmp;
	int remain;
	char t_string[256];
	while (number>0)
	{
		remain = number%radix;
		number = number / radix;
		if (remain > 9)
		{
			sprintf(t_string, "%c", remain - 10 + 'a');
			tmp.append(t_string);
		}
		else
		{
			sprintf(t_string, "%d", remain);
			tmp.append(t_string);
		}
	}
	for (int i = 0; i < tmp.length(); i++)
	{
		ret = ret + tmp[(tmp.length() - 1) - i];
	}
	return ret;
}

int main(int argc, char** argv) {
	if (argc < 2) return -1;
	unsigned int radix;
	sscanf(argv[1], "%u", &radix);
	if (radix < 2 || radix > 36) return -1;
	for (int i = 2; i < argc; ++i) {
		unsigned int number;
		sscanf(argv[i], "%u", &number);
		cout << RadixNotation(number, radix) << endl;
	}
	return 0;
}
