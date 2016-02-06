//2015004257
#include "message_book.h"
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

int main()
{
	MessageBook book;

	while (true)
	{
		string command;
		cin >> command;
		if (command == "quit") return 0;
		else if (command == "add")
		{
			int number;
			string message;
			cin >> number;
			getline(cin, message);
			message = message.substr(1);
			book.AddMessage(number, message);
		}
		else if (command == "print")
		{
			int number;
			cin >> number;
			vector<int> key = book.GetNumbers();
			vector<int>::iterator find = key.begin();
			while(find != key.end())
			{
				if (*find == number)
					break;
				find++;
			}
			if (find != key.end())
				cout << book.GetMessage(number) << endl;
			else
				cout << endl;
		}
		else if (command == "delete")
		{
			int number;
			cin >> number;
			book.DeleteMessage(number);
		}
		else if (command == "list")
		{
			vector<int> index = book.GetNumbers();
			for (vector<int>::iterator it = index.begin(); it != index.end(); it++)
				cout << *it << ": " << book.GetMessage(*it) << endl;
		}
		else break;
	}
	return 0;
}