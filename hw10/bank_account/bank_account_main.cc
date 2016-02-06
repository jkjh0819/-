#include "bank_account.h"

int main()
{
	vector<Account*> list;
	while (true)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "quit") break;
		else if (cmd == "add")
		{
			string name, kind;
			int balance;
			double rate;
			cin >> name >> kind >> balance >> rate;
			list.push_back(CreateAccount(kind, name, balance, rate));
		}
		else if (cmd == "after")
		{
			int years;
			cin >> years;
			for (vector<Account*>::iterator it = list.begin(); it != list.end(); it++)
			{
				int temp = (*it)->ComputeExpectedBalance(years);
				cout << (*it)->name() << "\t" << (*it)->type() << "\t" << temp
					<< "\t" << (*it)->interest_rate() << endl;
			}
		}
		else if (cmd == "delete")
		{
			string name;
			cin >> name;
			for (vector<Account*>::iterator it = list.begin(); it != list.end(); it++)
			{
				if ((*it)->name() == name)
				{
					it = list.erase(it);
					break;
				}
			}
		}
		else if (cmd == "show")
		{
			for (vector<Account*>::iterator it = list.begin(); it != list.end(); it++)
			{
				cout << (*it)->name() << "\t" << (*it)->type() << "\t" << (*it)->balance()
					<< "\t" << (*it)->interest_rate() << endl;
			}
		}
		else if (cmd == "save")
		{
			string filename;
			cin >> filename;
			SaveAccounts(list, filename);
		}
		else if (cmd == "load")
		{
			string filename;
			cin >> filename;
			LoadAccounts(filename, &list);
		}
		else break;
	}
	return 0;
}