//2015004257

#ifndef __hw03__binary_search__
#define __hw03__binary_search__

class BinarySearch
{
private:
	int *mArray;
	int mArrayCount;

	void sortArray(); 

public:
	BinarySearch();
	BinarySearch(int *_array, int _arrayCount);
	~BinarySearch();
	int getIndex(int _element); 
};

#endif