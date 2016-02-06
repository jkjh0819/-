#ifndef __hw08__sorted_array__
#define __hw08__sorted_array__
#include <algorithm>
#include <iostream>
#include <string>
#define ARRAY_ALLOC_SIZE 32
using namespace std;


template <typename T>
class SortedArray {
public:
	SortedArray(){}
	SortedArray(const SortedArray& a)
	{
		this->alloc(a.size());
		for (size_t i = 0; i < a.size(); i++)
			this->values_[i] = a.values_[i];
		this->sort();
	}
	SortedArray(size_t size)
	{
		this->alloc(size);
	}
	~SortedArray() {}

	SortedArray& operator=(const SortedArray<T>& a){
		this->alloc(a.size());
		for (int i = 0; i < a.size(); i++)
			this->values_[i] = a.values_[i];
		return *this;
	}

	size_t size() const { 
		return this->size_; 
	}
	const T& operator()(int idx) const{
		return this->values_[idx];
	}

	void Reserve(int size){
		this->realloc(size);
	}
	void Add(const T& value)
	{
		this->alloc(++this->size_);
		this->values_[this->size_ - 1] = value;
		this->sort();
	}

	int Find(const T& value)
	{
		return this->find(0, this->size_ - 1, value);
	}

private:
	T* values_ = nullptr;
	int size_ = 0, alloc_ = 0;
	int find(size_t start, size_t end, const T& value)
	{

		if (value == this->values_[start])
			return start;
		else if (value == this->values_[end])
			return end;
		else if (start == end)
			return -1;

		size_t mid = (start + end) / 2;
		if (value == this->values_[mid])
			return mid;

		if (start == mid || end == mid)
			return -1;

		if (this->values_[mid] < value)
			return this->find(mid, end, value);
		else
			return this->find(start, mid, value);
	}

	void sort()
	{
		std::sort(this->values_, this->values_ + this->size_);
	}

	void alloc(size_t size)
	{
		this->size_ = size;
		this->alloc();
	}
	void alloc()
	{
		if (this->size_ > this->alloc_ || this->size_ < this->alloc_ - ARRAY_ALLOC_SIZE)
			this->realloc(0);
	}
	void realloc(size_t value)
	{
		if (value)
			this->alloc_ = value;

		bool oper = this->size_ > this->alloc_;
		size_t less = (oper ? this->alloc_ : this->size_);

		T* temp = new T[less];

		for (size_t i = 0; i < less; i++)
			temp[i] = this->values_[i];

		delete[] this->values_;

		if (value)
			this->alloc_ = value;
		else
			while (oper ? (this->size_ > this->alloc_) : (this->size_ < this->alloc_))
				this->alloc_ += ARRAY_ALLOC_SIZE * (oper ? 1 : -1);

		this->values_ = new T[this->alloc_];

		for (size_t i = 0; i < less; i++)
			this->values_[i] = temp[i];

		delete[] temp;
	}
};

template <typename T>
istream& operator>>(istream& is, SortedArray<T>& a)
{
	int size; is >> size;
	while (size--)
	{
		T temp; is >> temp;
		a.Add(temp);
	}
	return is;
}
template <typename T>
ostream& operator<<(ostream& os, const SortedArray<T>& a)
{
	int size = a.size();
	while (size--)
	{
		os << a(a.size() - size - 1) << " ";
	}
	return os;
}

#endif