#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void getToken(const string& str, vector<string>& tokens, const string& delimiters)
{
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
} //입력값을 잘라서 반환하는 함수 

int toInt(string str)
{
	if (str.at(0) == '^')
		str = str.substr(1, str.size());
	else if (str.size() == 1 && str.at(0) == '-')
		return -1;
	return atoi(str.c_str());
}

int main()
{
	while (true)
	{
		string command;
		cin >> command;
		if (command == "quit") break;
		else
		{
			vector<string> argv;
			map<int, int> poly; //지수, 계수 
			getToken(command, argv, "+");
			for (int i = 0; i < argv.size();i++)
			{
				if (argv[i].find('x') != string::npos)
				{
					vector<string> temp;
					getToken(argv[i], temp, "x");

					if (temp.empty())
						poly.insert({ 1, 1 });
					else if (temp.size() == 1)
						if (temp.back().at(0) == '^')
							poly.insert({ toInt(temp.back()), 1 });
						else
							poly.insert({ 1, toInt(temp.back()) });
					else
						poly.insert({ toInt(temp.at(1)), toInt(temp.at(0)) });
				}
			}
			int sum = 0, c = 0; cin >> c;
			for (map<int, int>::iterator iter = poly.begin(); iter != poly.end(); iter++)
				sum += pow(c, iter->first - 1) * iter->second * iter->first;

			cout << sum << endl;
		}
	}
	return 0;
}
