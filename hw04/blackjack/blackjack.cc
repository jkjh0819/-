//2015004257

#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>

using namespace std;
int BlackJack(string list)
{
	int sum = 0, a_count = 0;
	for (char ch : list)
	{
		if (ch <= 10)
			sum += ch;
		else if (ch == 'A')
			a_count++;
		else
			sum += 10;
	}
	while (a_count--)
	{
		if (!a_count && !((sum + 11) > 21))
			sum += 11;
		else
			sum++;
	}
	if (sum > 21)
		return 0;
	else
		return sum;
}
int main(int argc, char * argv[])
{
	for (;;)
	{
		int size, csize;
		if (scanf("%d", &size))
		{
			csize = size;
			string list;
			if (size < 0)
				break;
			while (size--)
			{
				string str; cin >> str;
				if (str.size() == 1 && !atoi(str.c_str()))
					if (str[0] == 'A' || str[0] == 'K' || str[0] == 'Q' || str[0] == 'J')
						list.push_back(str[0]);
					else
						return 0;
				else
					if (atoi(str.c_str()) <= 10)
						list.push_back(atoi(str.c_str()));
			}
			if (csize != list.size())
				continue;
			int result = BlackJack(list);
			if (!result)
				cout << "Exceed" << endl;
			else if (result == 21)
				cout << "BlackJack" << endl;
			else
				cout << result << endl;
		}
		else
			break;
	}
	return 0;
}