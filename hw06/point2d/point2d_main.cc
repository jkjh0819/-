#include "point2d.h"


int main()
{
	string command, cmd;
	map<string, Point> vectors;
	while (true)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "set")
		{
			string name;
			int x, y;
			cin >> name >> x >> y;
			vectors.insert(make_pair(name, Point(x,y)));
		}
		else if (cmd == "eval")
		{
			string left_, right_, oper;	
			Point left, right;
			cin >> left_ >> oper >> right_;
			if (oper == "+")
			{
				if (isdigit(left_[0]))	//입력값이 숫자일 때
				{
					int num = atoi(left_.c_str());
					left = Point(num);
				}
				else					//입력값이 문자일 때 저장되어있지 않다면 error
				{
					map<string, Point>::iterator iter_front = vectors.find(left_);
					if (iter_front == vectors.end())
					{
						cout << "input error"<<endl;
						continue;
					}
					else
						left = iter_front->second;
				}

				if (isdigit(right_[0]))	//위와 같은방식
				{
					int num = atoi(right_.c_str());
					right = Point(num);
				}
				else
				{
					map<string, Point>::iterator iter_back = vectors.find(right_);
					if (iter_back == vectors.end())
					{
						cout << "input error" << endl;
						continue;
					}
					else
						right = iter_back->second;
				}
				Point result;
				result = left + right;			//연산
				cout << "(" << result.x_ << ", "<< result.y_ << ")"<<endl; //출력
			}
			else if (oper == "-")
			{
				if (isdigit(left_[0]))
				{
					int num = atoi(left_.c_str());
					left = Point(num);
				}
				else
				{
					map<string, Point>::iterator iter_front = vectors.find(left_);
					if (iter_front == vectors.end())
					{
						cout << "input error" << endl;
						continue;
					}
					else
						left = iter_front->second;
				}

				if (isdigit(right_[0]))
				{
					int num = atoi(right_.c_str());
					right = Point(num);
				}
				else
				{
					map<string, Point>::iterator iter_back = vectors.find(right_);
					if (iter_back == vectors.end())
					{
						cout << "input error" << endl;
						continue;
					}
					else
						right = iter_back->second;
				}
				Point result;
				result = left - right;
				cout << "(" << result.x_ << ", " << result.y_ << ")"<<endl;
			}
			else if (oper == "*")
			{
				if (isdigit(left_[0]))
				{
					int num = atoi(left_.c_str());
					left = Point(num);
				}
				else
				{
					map<string, Point>::iterator iter_front = vectors.find(left_);
					if (iter_front == vectors.end())
					{
						cout << "input error" << endl;
						continue;
					}
					else
						left = iter_front->second;
				}

				if (isdigit(right_[0]))
				{
					int num = atoi(right_.c_str());
					right = Point(num);
				}
				else
				{
					map<string, Point>::iterator iter_back = vectors.find(right_);
					if (iter_back == vectors.end())
					{
						cout << "input error" << endl;
						continue;
					}
					else
						right = iter_back->second;
				}
				Point result;
				result = left * right;
				cout << "(" << result.x_ << ", " << result.y_ << ")"<<endl;
			}
			else
				break;

		}
		else if (cmd == "quit")
		{
			return 0;
		}
		else
			break;
	}
	return 0;
}