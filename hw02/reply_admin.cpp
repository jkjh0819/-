//2015004257
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

const int NUM_OF_CHAT = 200;
size_t list_count = 0;

int getChatCount(string *_chatList)
{
	int i;
	for (i = 0; i<NUM_OF_CHAT; ++i)
	{
		string s = _chatList[i];
		if (s.empty() == true) break;
	}
	return i;
}

void printChat(string *_chatList)
{
	int count = getChatCount(_chatList);
	for (int i = 0; i<count; ++i)
	{
		cout << i << " " << _chatList[i] << endl;
	}
}

bool addChat(string *_chatList, string _chat)
{
	if (list_count < NUM_OF_CHAT)
	{
		_chatList[list_count++] = _chat;
		_chatList[list_count] = "";
		return true;
	}
	return false;
}
bool removeChat(string *_chatList, int _index)
{
	for (size_t index = _index + 1; index < list_count - 1; index++)
	{
		_chatList[index] = _chatList[index + 1];
	}
	_chatList[list_count--] = "";
	return true;
}
bool removeChat(string *_chatList)
{
	for (size_t index = 0; index < list_count; index++)
		if (_chatList[index] == "")
		{
			for (size_t t = index; t < list_count - 1; t++)
				_chatList[t] = _chatList[t + 1];
			list_count--;
			index--;
		}
	_chatList[list_count] = "";
	return true;
}

int main(void)
{
	string* chats = new string[NUM_OF_CHAT];

	addChat(chats, "Hello, Reply Administrator!");
	addChat(chats, "I will be a good programmer.");
	addChat(chats, "This class is awesome.");
	addChat(chats, "Professor Lim is wise.");
	addChat(chats, "Two TAs are kind and helpful.");
	addChat(chats, "I think male TA looks cool.");
	while (true)
	{
		string command;
		getline(cin, command);
		if (command.substr(0, strlen("#quit")) == "#quit")
			break;
		else if (command.substr(0, strlen("#remove")) == "#remove")
		{
			string target = command.substr(strlen("#remove") + 1) + ",";
			size_t checkTarget = 0, check = 0;
			while ((checkTarget = target.find_first_of(',')) != target.npos)
			{
				string temp = target.substr(0, checkTarget);
				size_t seriesTarget = 0;
				for (size_t i = 0; i < temp.size(); i++)
				{
					if ((temp.at(i) < '0' || temp.at(i) > '9') && temp.at(i) != '-') {
						check++;
						break;
					}
				}
				if (check)
					break;
				if ((seriesTarget = temp.find('-')) == temp.npos)
					chats[atoi(temp.c_str())] = "";
				else
					for (size_t token = atoi(temp.substr(0, seriesTarget).c_str()); token <= atoi(temp.substr(seriesTarget + 1).c_str()); token++)
						chats[token] = "";
				target = target.substr(checkTarget + 1);
			}
			if (!check) {
				removeChat(chats);
				printChat(chats);
			}
		}
		else if (command.find_first_of('#') != command.npos)
			continue;
		else if (addChat(chats, command)) printChat(chats);
	}

	delete[] chats;

	return 0;
}