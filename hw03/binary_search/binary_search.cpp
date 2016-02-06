//2015004257

#include "binary_search.h"
#include <algorithm>

void BinarySearch::sortArray()
{
	std::sort(this->mArray, this->mArray + this->mArrayCount);
}
BinarySearch::BinarySearch()
{
	this->mArray = nullptr;
}
BinarySearch::BinarySearch(int *_array, int _arrayCount)
{
	this->mArrayCount = _arrayCount;
	this->mArray = new int[_arrayCount];
	for (int t = 0; t < _arrayCount; t++)
		this->mArray[t] = _array[t];
	this->sortArray();
}
BinarySearch::~BinarySearch()
{
	delete[] this->mArray;
}
int BinarySearch::getIndex(int _element)
{
	int start = 0, end = this->mArrayCount-1;
	int mid = (start + end) / 2;
	while (true)
	{
		if (_element<this->mArray[start] || _element>this->mArray[end])
			return -1;
		if (this->mArray[mid] > _element)
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else if (this->mArray[mid] < _element)
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
		else
			return mid;
	}
}
