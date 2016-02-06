//2015004257
#include <iostream>

int check = 0;
using namespace std;

int fibo(int num, int print)

{

	if (num == 0)
		return 0;
	else if (num == 1)

	{
		if (check <= print)

		{
			cout << 1 << ' ';
			check = num;
		}
		return 1;
	}
	else
	{
		int ret = fibo(num - 1, num-1) + fibo(num - 2, num-2);
		if (check <= print)
		{
			cout << ret << ' ';
			check = num;
		}
		return ret;
	}
	return 0;
}


int main()
{
	int num;
	cin >> num;
	if (num < 0)
		return 0;
	else
		fibo(num,num);
	return 0;
}