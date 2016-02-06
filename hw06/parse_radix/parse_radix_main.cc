#include "parse_radix.h"

int main()
{
	while (true)
	{
		string command;
		getline(cin, command);
		vector<string> argv;
		string token;
		size_t pos;
		while (true)
		{
			pos = command.find(' ');
			token = command.substr(0, pos);
			argv.push_back(token);
			if (pos >= command.length()) break;
			else command.erase(0, pos + 1);
		}												//입력받은 값을 저장한다.
		if (argv[0] == "eval")
		{
			string print;
			if (argv[2] == "+")
			{
				int front = ParseRadix(argv[1]), back = ParseRadix(argv[3]);		//진법변환을 해준다.
				if (front == -1 || back == -1)
				{
					cout << "Error"<<endl;
					continue;
				}
				int result = front + back;				//연산을 한다.
				print = ConvertRadix(result, atoi(argv[4].c_str()));		//주어진 진법으로 변환하여 출력한다.
			}
			else if (argv[2] == "-")
			{
				int front = ParseRadix(argv[1]), back = ParseRadix(argv[3]);
				if (front == -1 || back == -1)
				{
					cout << "Error"<<endl;
					continue;
				}
				int result = front - back;
				print = ConvertRadix(result, atoi(argv[4].c_str()));
			}
			else if (argv[2] == "*")
			{
				int front = ParseRadix(argv[1]), back = ParseRadix(argv[3]);
				if (front == -1 || back == -1)
				{
					cout << "Error"<<endl;
					continue;
				}
				int result = front * back;
				print = ConvertRadix(result, atoi(argv[4].c_str()));
			}
			else if (argv[2] == "/")
			{
				int front = ParseRadix(argv[1]), back = ParseRadix(argv[3]);
				if (front == -1 || back == -1)
				{
					cout << "Error"<<endl;
					continue;
				}
				int result = front / back;
				print = ConvertRadix(result, atoi(argv[4].c_str()));
			}
			else if (argv[2] == "<")
			{
				int front = ParseRadix(argv[1]), back = ParseRadix(argv[3]);
				if (front == -1 || back == -1)
				{
					cout << "Error"<<endl;
					continue;
				}
				if (front < back)
					print = "true";
				else
					print = "false";
			}
			else if (argv[2] == ">")
			{
				int front = ParseRadix(argv[1]), back = ParseRadix(argv[3]);
				if (front == -1 || back == -1)
				{
					cout << "Error"<<endl;
					continue;
				}
				if (front > back)
					print = "true";
				else
					print = "false";
			}
			else if (argv[2] == "==")
			{
				int front = ParseRadix(argv[1]), back = ParseRadix(argv[3]);
				if (front == -1 || back == -1)
				{
					cout << "Error"<<endl;
					continue;
				}
				if (front == back)
					print = "true";
				else
					print = "false";
			}
			else
				break;
			cout << print << endl;
		}
		else if (argv[0] == "quit")
			return 0;
		else break;
	}
	return 0;
}