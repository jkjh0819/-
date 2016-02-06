//2015004257
#ifndef __hw05__sorted_array__
#define __hw05__sorted_array__

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class SortedArray {
public:
	SortedArray();
	~SortedArray();

	void AddNumber(int num);
	vector<int> GetSortedAscending() const;
	vector<int> GetSortedDescending() const;
	int GetMax() const;
	int GetMin() const;

private:
	vector<int> numbers_;
};

#endif