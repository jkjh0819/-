#include "calendar.h"

int main()
{
	Date date;
	while (true)
	{
		string command;
		cin >> command;
		try{
			if (command == "quit") break;
			else if (command == "next_day")
			{
				date.NextDay();
				cout << date << endl;
			}
			else if (command == "set")
			{
				cin >> date;
				cout << date << endl;
			}
			else if (command == "next")
			{
				int day;
				cin >> day;
				date.NextDay(day);
				cout << date << endl;
			}
			else
				break;
		}
		catch (InvalidDateException& e) {
			cout << "Invalid date: " << e.input_date << endl;
		}

	}
	return 0;
}
