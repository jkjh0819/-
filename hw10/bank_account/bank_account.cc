#include "bank_account.h"


void Account::Deposit(unsigned int amount)
{
	balance_ = amount;
}
bool Account::Withdraw(unsigned int amount)
{
		balance_ -= amount;
		return true;
}

unsigned int Account::ComputeExpectedBalance(unsigned int n_years_later) const
{
	return balance_ + balance_*(interest_rate()*n_years_later);
}

unsigned int SavingAccount::ComputeExpectedBalance(unsigned int n_years_later) const
{
	return balance_*pow(1 + interest_rate(), n_years_later);
}

Account* CreateAccount(const string& type, const string& name, unsigned int balance, double interest_rate)
{
	if (type == "checking")
		return new Account(name, balance, interest_rate);
	else
		return new SavingAccount(name, balance, interest_rate);
}

bool SaveAccounts(const vector<Account*>& accounts, const string& filename)
{
	ofstream SaveFile;
	SaveFile.open(filename, ios::trunc);
	for (vector<Account*>::const_iterator it = accounts.begin(); it != accounts.end();it++)
	{
		SaveFile << (*it)->name() << "\t" << (*it)->type() << "\t" << (*it)->balance() 
			<< "\t" << (*it)->interest_rate() << endl;
	}
	SaveFile.close();
	return true;
}
bool LoadAccounts(const string& filename, vector<Account*>* accounts)
{
	ifstream file;
	file.open(filename);
	while (!file.eof()){
		string name, type;
		int balance;
		double interest;
		file >> name >> type >> balance >> interest;
		if (name == "") break;
		else (*accounts).push_back(CreateAccount(type, name, balance, interest));
	}
	file.close();
	return true;
}
