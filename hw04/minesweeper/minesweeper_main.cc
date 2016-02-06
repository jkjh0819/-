//2015004257
#include <iostream>
#include <string>
#include "minesweeper.h"

function<vector<string>(string)> getArgs = [](string input)
{
	input = input.substr(1);
	int pointer = 0;
	vector<string> result;
	while ((pointer = input.find_first_of(' ')) + 1)
	{
		result.push_back(input.substr(0, pointer));
		input = input.substr(++pointer);
	}
	return result;
};

bool if_match(string& input, const string& comp)
{
	if (input.size() < comp.size() || input.substr(0, comp.size()) != comp.c_str())
		return false;
	input = input.substr(comp.size()) + ' ';
	return true;
}
int main()
{
	Minesweeper mine;

	vector<pair<string, int>> command_list = { { ":set", 1 },{ ":toggle", 2 },{ ":play", 3 },{ ":touch", 4 },{ ":quit", 0 } };

	for (;;)
	{
		string input;
		getline(cin, input);
		for (pair<string, int> command : command_list)
			if (if_match(input, command.first))
			{
				vector<string> arg = getArgs(input);
				switch (command.second)
				{
				case 0:
					return 0;
				case 1:
				{
					int height = atoi(arg[1].c_str());
					int width = atoi(arg[0].c_str());
					VVC map;
					char ch;
					bool chk = true;
					for (int i = 0; i < height; i++)
					{
						string str;
						cin >> str;
						VC column(str.begin(), str.end());
						if (str.size() == width)
							map.push_back(column);
						else
							chk = false;
					}
					if(chk)
						mine.set(map);
					break;
				}
				case 2:
					mine.toggle(atoi(arg[1].c_str()), atoi(arg[0].c_str()));
					break;
				case 3:
					mine.play();
					break;
				case 4:
					mine.touch(atoi(arg[1].c_str()), atoi(arg[0].c_str()));
					break;
				}
				break;
			}
	}


	return 0;
}
