#include "draw_shape.h"

Canvas::Canvas(size_t row, size_t col)
{
	row_ = row;
	col_ = col;
	canvas.resize(row*col);
}
// Canvas ũ�⸦ w x h �� �����Ѵ�. �׷��� ������ �����Ѵ�.
void Canvas::Resize(size_t w, size_t h)
{
	canvas.resize(w*h);
	row_ = w;
	col_ = h;
}

Canvas::~Canvas()
{}

// (x,y) ��ġ�� ch ���ڸ� �׸���. ���� ���� x,y �� �����Ѵ�.
bool Canvas::Draw(int x, int y, char brush)
{
	if (x >= 0 && y >= 0 && x < row_ && y < col_)
	{
		canvas[x + y*row_] = brush;
		return true;
	}
	else
		return false;
}
// �׷��� ������ ��� ����� ('.'���� �ʱ�ȭ)
void Canvas::Clear()
{
	for (int i = 0; i < row_*col_; i++)
		canvas[i] = '.';
}

ostream& operator<<(ostream& os, const Canvas& c)
{
	for (int i = 0; i < c.col_ + 1; i++)
	{
		for (int j = 0; j < c.row_ + 1; j++)
		{
			if (!j && i)					//canvas �ε��� ���
				os << ((i - 1) % 10);
			else if (j && !i)
				os << ((j - 1) % 10);
			else if (i == 0 && j == 0)
				os << ' ';
			else if (c.canvas[(j-1) + (i-1)*c.row_] == 0)
				os << '.';
			else
				os << c.canvas[(j-1) + (i-1)*c.row_];
		}
		cout << endl;
	}
	return os;
}

Shape::~Shape()
{}

Rectangle::~Rectangle()
{}
void Rectangle::Draw(Canvas* canvas) const
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			canvas->Draw(start_x + j, start_y + i, brush_);
	}
}

UpTriangle::~UpTriangle()
{}

void UpTriangle::Draw(Canvas* canvas) const
{
	for (int i = 0; i < height; i++)
		for (int j = -i; j < i + 1; j++)
			canvas->Draw(start_x + j, start_y + i, brush_);
}

DownTriangle::~DownTriangle()
{}
void DownTriangle::Draw(Canvas* canvas) const
{
	for (int i = 0; i < height; i++)
		for (int j = -i; j < i + 1; j++)
			canvas->Draw(start_x + j, start_y - i, brush_);
}

Diamond::~Diamond()
{}
void Diamond::Draw(Canvas* canvas) const
{
	for (int i = 0; i < height; i++)
		for (int j = -i; j < i + 1; j++)
			canvas->Draw(start_x + j, start_y + i, brush_);

	for (int i = -height; i < height+1; i++)
		canvas->Draw(start_x + i, start_y + height, brush_);

	for (int i = 0; i < height; i++)
		for (int j = -i; j < i + 1; j++)
			canvas->Draw(start_x + j, start_y+(2*height) - i, brush_);
}

istream& operator>>(istream& is, Rectangle& r)
{
	int start_x, start_y, width, height;
	char brush;
	is >> start_x >> start_y >> width >> height >> brush;
	Rectangle temp(start_x, start_y, width, height, brush);
	r = temp;
	return is;
}
istream& operator>>(istream& is, UpTriangle& t)
{
	int start_x, start_y, height;
	char brush;
	is >> start_x >> start_y >> height >> brush;
	UpTriangle temp(start_x, start_y, height, brush);
	t = temp;
	return is;	
}
istream& operator>>(istream& is, DownTriangle& d)
{
	int start_x, start_y, height;
	char brush;
	is >> start_x >> start_y >> height >> brush;
	DownTriangle temp(start_x, start_y, height, brush);
	d = temp;
	return is;
}
istream& operator>>(istream& is, Diamond& dm)
{
	int start_x, start_y, height;
	char brush;
	is >> start_x >> start_y >> height >> brush;
	Diamond temp(start_x, start_y, height, brush);
	dm = temp;
	return is;
}
