//2015004257

#include "draw_shape.h"

int main()
{
	int width, height;
	cin >> width >> height;
	Canvas canv(width, height);
	canv.Draw(cout);
	while (true)
	{
		string command;
		cin >> command;
		if (command == "quit") return 0;
		else if (command == "add")
		{
			Shape sp;
			string choose_shape;
			cin >> choose_shape >> sp.x >> sp.y;
			if (choose_shape == "rect")
			{
				sp.type = RECTANGLE;
				cin >> sp.width >> sp.height >> sp.brush;
			}
			else if (choose_shape == "tri_up")
			{
				sp.type = TRIANGLE_UP;
				cin >> sp.height >> sp.brush;
				sp.width = 0;
			}

			else if (choose_shape == "tri_down")
			{
				sp.type = TRIANGLE_DOWN;
				cin >> sp.height >> sp.brush;
				sp.width = 0;
			}
			canv.AddShape(sp);

		}
		else if (command == "draw")
			canv.Draw(cout);
		else if (command == "delete")
		{
			int index;
			cin >> index;
			canv.DeleteShape(index);
		}
		else if (command == "dump")
			canv.Dump(cout);
		else break;
	}
	return 0;
}