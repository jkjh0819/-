//2015004257
#include <iostream>
#include <stdlib.h>
using namespace std;
void sort(int * num, int size)
{
	int i, j, temp;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (num[i]>num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
}


int main()
{
	int size, i;
	cin >> size;
	int * num = new int[size];
	for (i = 0; i < size; i++)
	{
		cin >> num[i];
	}
	sort(num, size);
	for (i = 0; i < size; i++)
	{
		cout << num[i] << " ";
	}
	delete[] num;
}