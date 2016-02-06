//2015004257

#include "reply_admin.h"
#include <algorithm>
#include <list>
#include <functional>

ReplyAdmin::ReplyAdmin()
{
	addChat("Hello, Reply Administrator!");
	addChat("I will be a good programmer.");
	addChat("This class is awesome.");
	addChat("Professor Lim is wise.");
	addChat("Two TAs are kind and helpful.");
	addChat("I think male TA looks cool.");
}

bool ReplyAdmin::addChat(string _chat)
{
	this->chats.push_back(_chat);
	return true;
}
bool ReplyAdmin::removeChat(int _index)
{
	list<string>::iterator target_chat = this->chats.begin();
	if (_index > this->chats.size())
	{
		return false;
	}
	else
	{
		advance(target_chat, _index);
		this->chats.erase(target_chat);
		return true;
	}
}

bool ReplyAdmin::removeChat(list<int> _indices)
{
	_indices.sort(greater<int>());
	list<string>::iterator target = this->chats.begin();
	size_t count = 0;
	while (!_indices.empty())
	{
		if (_indices.back() == count)
		{
			target = this->chats.erase(target);
			_indices.pop_back();
			count++;
		}
		else if (_indices.back() > this->chats.size())
			return 0;
		else 
		{
			count++; target++;
		}
	}
	return true;
}
bool ReplyAdmin::removeChat(int _start, int _end)
{
	if (_start < 0)
		_start = 0;
	if (_end >= this->chats.size())
		_end = this->chats.size() - 1;
	int count = _end - _start, chk = 0;
	list<string>::iterator target = this->chats.begin();
	advance(target, _start);
	while (chk++ <= count)
	{
		target = this->chats.erase(target);
	}
	return true;
}
void ReplyAdmin::printChat()
{
	size_t count = 0;
	for (list<string>::iterator it = this->chats.begin(); it != this->chats.end(); it++)
		cout << count++ << " " << (*it) << endl;
}