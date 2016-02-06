//2015004257
#include "simple_int_set.h"
#include <algorithm>
#include <iostream>

SimpleIntSet::SimpleIntSet(int * _elements, int _count)
{
	this->mElements = new int[_count];
	this->mElementCount = _count;
	for (size_t t = 0; t < _count; t++)
		this->mElements[t] = _elements[t];
	this->sortElements();
}

SimpleIntSet::~SimpleIntSet()
{
	free(this->mElements);
}

void SimpleIntSet::sortElements()
{
	std::sort(this->mElements, this->mElements + this->mElementCount);
}

int * SimpleIntSet::elements() const
{
	return this->mElements;
}

int SimpleIntSet::elementCount() const
{
	return this->mElementCount;
}

SimpleIntSet * SimpleIntSet::unionSet(SimpleIntSet& _operand)
{
	int * temp = new int[this->elementCount() + _operand.mElementCount];
	for (size_t t = 0; t < this->elementCount() + _operand.mElementCount; t++)
	{
		if (t < this->elementCount())
			temp[t] = this->mElements[t];

		else
			temp[t] = _operand.mElements[t - this->mElementCount];
	}
	std::sort(temp, temp + this->mElementCount + _operand.mElementCount);
	int * end = std::unique(temp, temp + this->mElementCount + _operand.mElementCount);
	this->mElementCount= end - temp;
	this->mElements = (int*)realloc(this->mElements, sizeof(int) * this->mElementCount);
	for (size_t t = 0; t < this->mElementCount; t++)
		this->mElements[t] = temp[t];

	return this;
}

SimpleIntSet * SimpleIntSet::differenceSet(SimpleIntSet& _operand)
{
	int * temp = new int[this->elementCount() + _operand.mElementCount];
	int index = 0;
	for (size_t i = 0, j=0 ; i < this->elementCount();)
	{
		if (this->mElements[i] < _operand.mElements[j] || j>_operand.mElementCount)
			temp[index++] = mElements[i++];
		else if (this->mElements[i] == _operand.mElements[j])
		{
			i++;
			j++;
		}
		else if (this->mElements[i] > _operand.mElements[j])
			j++;
	}
	this->mElementCount = index;
	this->mElements = (int*)realloc(this->mElements, sizeof(int) * this->mElementCount);
	for (size_t i = 0; i < this->mElementCount; i++)
		this->mElements[i] = temp[i];
	return this;
}

SimpleIntSet * SimpleIntSet::intersectSet(SimpleIntSet& _operand)
{
	int * temp = new int[this->elementCount() + _operand.mElementCount];
	int index = 0;
	for (size_t i = 0, j = 0; j < _operand.mElementCount;)
	{
		if (this->mElements[i] < _operand.mElements[j])
			i++;
		else if (this->mElements[i] == _operand.mElements[j])
		{
			temp[index++] = mElements[i++];
			j++;
		}
		else if (this->mElements[i] > _operand.mElements[j])
			j++;
	}
	this->mElementCount = index;
	this->mElements = (int*)realloc(this->mElements, sizeof(int) * this->mElementCount);
	for (size_t i = 0; i < this->mElementCount; i++)
		this->mElements[i] = temp[i];
	return this;
}

void SimpleIntSet::printSet()
{
	std::cout << '{' << ' ';
	for (int i = 0; i < this->elementCount(); i++)
	{
		std::cout << this->mElements[i] << ' ';
	}
	std::cout << '}' << std::endl;
}