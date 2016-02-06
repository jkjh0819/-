//2015004257

#include "reply_admin.h"
#include <algorithm>

int ReplyAdmin::getChatCount()
{
	for (int t = 0; t < NUM_OF_CHAT; t++)
		if (this->chats[t].empty())
			return t;
}	
ReplyAdmin::ReplyAdmin()
{
	this->chats = new string[NUM_OF_CHAT];
	this->addChat("Hello, Reply Administrator!");
	this->addChat("I will be a good programmer.");
	this->addChat("This class is awesome.");
	this->addChat("Professor Lim is wise.");
	this->addChat("Two TAs are kind and helpful.");
	this->addChat("I think male TA looks cool.");
}
ReplyAdmin::~ReplyAdmin()
{
	delete[] this->chats;
}
bool ReplyAdmin::addChat(string _chat)
{
	if (this->getChatCount() > NUM_OF_CHAT)
		return false;
	this->chats[this->getChatCount()] = _chat;
	return true;
}
bool ReplyAdmin::removeChat(int _index)
{
	int size = this->getChatCount();
	if (_index > size)
		return false;
	for (int t = _index; t < size; t++)
		if (t + 1 >= NUM_OF_CHAT)
			this->chats[t].clear();
		else
			this->chats[t] = this->chats[t + 1];
	return true;
}              
bool ReplyAdmin::removeChat(int *_indices, int _count)
{
	if (!_count)
		return false;
	bool chk = true;
	std::sort(_indices, _indices + _count);
	for (int t = 0; t < _count; t++)
		chk |= this->removeChat(_indices[t] - t);
	return chk;
}
bool ReplyAdmin::removeChat(int _start, int _end)
{
	int * indices = new int[_end - _start];
	for (int t = _start; t <= _end; t++)
		indices[t - _start] = t;
	return this->removeChat(indices, _end - _start + 1);
}
void ReplyAdmin::printChat()
{
	int point = 0;
	while (this->chats[point].size())
		std::cout << point - 1 << " " << this->chats[point++] << std::endl;
}