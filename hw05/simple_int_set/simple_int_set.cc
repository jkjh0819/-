//2015004257
#include "simple_int_set.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

set<int> SetIntersection(const set<int>& set0, const set<int>& set1)
{
	vector<int> vec0(set0.begin(), set0.end()),
		vec1(set1.begin(), set1.end()),
		vec;
	sort(vec0.begin(), vec0.end());
	sort(vec1.begin(), vec1.end());

	int i = 0, j = 0;
	while (i < vec0.size() && j < vec1.size())
	{
		while (j < vec1.size() && vec0.at(i) > vec1.at(j))
			j++;
		if (i >= vec0.size() || j >= vec1.size())
			break;
		while (i < vec0.size() && vec0.at(i) < vec1.at(j))
			i++;
		if (i >= vec0.size() || j >= vec1.size())
			break;
		if (vec0.at(i) == vec1.at(j))
		{
			vec.push_back(vec0.at(i));
			i++; j++;
		}
	}
	set<int> result(vec.begin(), vec.end());
	return result;
}

set<int> SetUnion(const set<int>& set0, const set<int>& set1)
{
	set<int> result;
	for (set<int>::iterator it = set0.begin(); it != set0.end(); it++)
	{
		result.insert(*it);
	}
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		result.insert(*it);
	}
	return result;
}

set<int> SetDifference(const set<int>& set0, const set<int>& set1)
{
	vector<int> vec0(set0.begin(), set0.end()),
		vec1(set1.begin(), set1.end());
	set <int> result(set0.begin(), set0.end());
	sort(vec0.begin(), vec0.end());
	sort(vec1.begin(), vec1.end());

	int i = 0, j = 0;
	while (i < vec0.size() && j < vec1.size())
	{
		while (j < vec1.size() && vec0.at(i) > vec1.at(j))
			j++;
		if (i >= vec0.size() || j >= vec1.size())
			break;
		while (i < vec0.size() && vec0.at(i) < vec1.at(j))
			i++;
		if (i >= vec0.size() || j >= vec1.size())
			break;
		if (vec0.at(i) == vec1.at(j))
		{
			result.erase(vec0.at(i));
			i++; j++;
		}
	}
	return result;
}

bool InputSet(istream& in, set<int>* s)
{
	string tmp;
	in >> tmp;
	if (tmp != "{")
		return false;

	for (;;)
	{	in >> tmp;
		if (tmp.at(0) == '}')
			return true;
		else
			s->insert(atoi(tmp.c_str()));
	}
}

void OutputSet(const set<int>& s, ostream& out)
{
	out << "{ ";
	for (set<int>::iterator begin = s.begin(); begin != s.end(); begin++)
		out << *begin << " ";
	out << "}" << endl;
}