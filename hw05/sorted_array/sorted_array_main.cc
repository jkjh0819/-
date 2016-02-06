//2015004257
#include "sorted_array.h"
#include <iostream>
#include <string>

int main()
{
	SortedArray arr;
	while (true)
	{
		string input;
		getline(cin, input);

		string *argv = new string[input.length()]; 
		string temp;
		size_t pos;
		int index = 0;
		if (input.find(' ') == string::npos)
		{
			if (input == "ascend")
			{
				vector<int> temp = arr.GetSortedAscending();
				vector<int>::iterator it = temp.begin();
				while (it != temp.end())
				{
					cout << *it << " ";
					it++;
				}
				cout << endl;
			}
			else if (input == "descend")
			{
				vector<int> temp = arr.GetSortedDescending();
				vector<int>::iterator it = temp.begin();
				while (it != temp.end())
				{
					cout << *it << " ";
					it++;
				}
				cout << endl;
			}
			else if (input == "max")
			{
				cout << arr.GetMax() << endl;
			}
			else if (input == "min")
			{
				cout << arr.GetMin() << endl;
			}
			else if (input == "quit")
				return 0;
		}
		else
		{
			while (true)
			{
				pos = input.find(' ');
				temp = input.substr(0, pos);
				argv[index++] = temp;
				if (pos >= input.length()) break;
				else input.erase(0, pos + 1);
			}
			for (size_t t = 0; t < index; t++)
			{
				arr.AddNumber(atoi(argv[t].c_str()));
			}
		}
	}
}