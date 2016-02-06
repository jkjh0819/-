#include <iostream>
#include "omok.h"

using namespace std;
int main(int argc, char * argv[])
{
	Omok omok;
	while (!omok.IsOmok())
	{
		cout << omok;
		cin >> omok;
	}
	omok.print();
	return 0;
}