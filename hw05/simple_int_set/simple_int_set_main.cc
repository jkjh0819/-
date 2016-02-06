//2015004257

#include "simple_int_set.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	while (true)
	{
		char op;
		set<int> a, b;
		if (!InputSet(cin, &a)) break;
		cin >> op;
      	if(!InputSet(cin, &b)) break;
		if (op == '+')
			OutputSet(SetUnion(a, b), cout);
		else if (op == '-')
			OutputSet(SetDifference(a, b), cout);
		else if (op == '*')
			OutputSet(SetIntersection(a, b), cout);
		else break;
	}
	return 0;
}