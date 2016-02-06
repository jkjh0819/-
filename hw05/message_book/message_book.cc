//2015004257
#include "message_book.h"
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>


MessageBook::MessageBook(){
}
MessageBook::~MessageBook(){
}
void MessageBook::AddMessage(int number, const string& message)
{
	map<int, string>::iterator it = this->messages_.find(number);
	if (it != this->messages_.end())
	{
		it->second = message;
	}
	else
		this->messages_.insert(make_pair(number, message));
}
void MessageBook::DeleteMessage(int number)
{
	if (this->messages_.find(number) != this->messages_.end())
		this->messages_.erase(number);
}
vector<int> MessageBook::GetNumbers() const
{
	vector<int> result;
	map<int, string> temp = this->messages_;
	for (map<int, string>::iterator it = temp.begin(); it != temp.end();it++)
		result.push_back(it->first);
	return result;
}
const string& MessageBook::GetMessage(int number) const
{
	return this->messages_.find(number)->second;
}