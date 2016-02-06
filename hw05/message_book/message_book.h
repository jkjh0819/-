//2015004257
#ifndef __hw05__message_book__
#define __hw05__message_book__

#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
class MessageBook {

public:
	MessageBook();
	~MessageBook();
	void AddMessage(int number, const string& message);
	void DeleteMessage(int number);
	vector<int> GetNumbers() const;
	const string& GetMessage(int number) const;

private:
	map<int, string> messages_;
};

#endif