//2015004257
#include <iostream>
#include <string>
#include "creative_stone.h"

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
	CreativeStone my, your;
	my.setEnemy(&your);
	your.setEnemy(&my);
	
	vector<pair<string, int>> command_list = { {":add", 1 }, { ":foeadd", 2 }, { ":attack", 3 }, { ":burn", 4 }, { ":quit", 0 }};

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
						my.add(arg[0], atoi(arg[1].c_str()), atoi(arg[2].c_str()));
						break;
					case 2:
						my.foeadd(arg[0], atoi(arg[1].c_str()), atoi(arg[2].c_str()));
						break;
					case 3:
						my.attack(arg[0], arg[1]);
						break;
					case 4:
						if (arg.size() > 1)
							my.burn(arg[0], atoi(arg[1].c_str()));
						else
							my.burn(atoi(arg[0].c_str()));
						break;
				}
				break;
			}
	}


	return 0;
}
