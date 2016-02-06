//2015004257
#ifndef __hw05__simple_int_set__
#define __hw05__simple_int_set__

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

set<int> SetIntersection(const set<int>& set0, const set<int>& set1);
set<int> SetUnion(const set<int>& set0, const set<int>& set1);
set<int> SetDifference(const set<int>& set0, const set<int>& set1);

bool InputSet(istream& in, set<int>* s);
void OutputSet(const set<int>& s, ostream& out);

#endif
