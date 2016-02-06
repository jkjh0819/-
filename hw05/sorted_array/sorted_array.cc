//2015004257
#include "sorted_array.h"
#include <iostream>
#include <algorithm>
#include <functional>

SortedArray::SortedArray(){};

SortedArray::~SortedArray(){};

void SortedArray::AddNumber(int num)
{
	this->numbers_.push_back(num);
}

vector<int> SortedArray::GetSortedAscending() const
{
	vector<int> temp = this->numbers_;
	sort(temp.begin(), temp.end());
	return temp;
}

vector<int> SortedArray::GetSortedDescending() const
{
	vector<int> temp = this->numbers_;
	sort(temp.begin(), temp.end(),greater<int>());
	return temp;
}

int SortedArray::GetMax() const
{
	vector<int> temp = this->GetSortedDescending();
	vector<int>::iterator max = temp.begin();
	return *max;
}
int SortedArray::GetMin() const
{
	vector<int> temp = this->GetSortedAscending();
	vector<int>::iterator min = temp.begin();
	return *min;
}
