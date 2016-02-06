//2015004257
#include <iostream>

using namespace std;

struct Point{
	int x, y;
};

int main()
{
	Point * location = new Point[256];
	int count = 0, min_x = 0, min_y = 0;
	while (min_x >= 0 && min_y >= 0)
	{
		cin >> location[count].x >> location[count].y;
		if (location[count].x < 0 || location[count].y < 0)
			return 0;
		else
		{
			if (location[count].x > min_x)
			{
				min_x = location[count].x;
			}
			if (location[count].y > min_y)
			{
				min_y = location[count].y;
			}
			count++;
			for (int y = 0; y <= min_y; y++)
			{
				for (int x = 0; x <= min_x; x++)
				{
					int count_check = count;
					while (count_check-- > 0)
					{
						if (location[count_check].x == x && location[count_check].y == y)
							break;
					}
					if (count_check >= 0)
						cout << '*';
					else
						cout << '.';
				}
				cout << endl;
			}
		}
	}
	delete[] location;
}
