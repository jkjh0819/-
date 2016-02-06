//2015004257
#include <iostream>
#include <stdlib.h>
using namespace std;

void set_mat(int ** mat, int size)
{
	int x = 0, y, i;
	y = size / 2;
	for (i = 1; i <= size*size; i++)
	{
		mat[x][y] = i;
		if (i%size == 0)
			x = x + 1;
		else
		{
			x = x - 1;
			y = y + 1;
		}
		if (x<0)
			x = size - 1;
		if (y>size - 1)
			y = 0;
	}
}



int main()
{
	int size;
	cin >> size;
	int ** mat = new int *[size];
	for (int i = 0; i < size; i++)
	{
		mat[i] = new int[size];
	}
	set_mat(mat, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << " " << mat[i][j];
		cout << endl;
	}
	delete[] mat;
}