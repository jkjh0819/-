//2015004257
#include "draw_shape.h"

Canvas::Canvas(size_t row, size_t col)
{
	this->row_ = row;
	this->col_ = col;
}
Canvas::~Canvas()
{

}
int Canvas::AddShape(const Shape &s)
{

	if (s.type == RECTANGLE)
	{
		if (!(s.width % 2) || !(s.height % 2))
		{
			cout << "error invalid input" << endl;
			return ERROR_INVALID_INPUT;
		}
		if (s.x < 0 || s.x + s.width / 2 >= this->col_ || s.y < 0 || s.y + s.height / 2 >= this->row_
			|| s.x - s.width / 2 < 0 || s.y - s.height / 2 < 0)
		{
			cout << "error out of canvas" << endl;
			return ERROR_OUT_OF_CANVAS;
		}

	}
	else if (s.type == TRIANGLE_DOWN)
	{
		if (s.x < 0 || s.x>this->col_||s.y<0||s.y>this->row_||s.x-(s.height-1)<0||s.x+(s.height-1)>=this->col_
			||s.y-(s.height-1)<0)
		{
			cout << "error out of canvas" << endl;
			return ERROR_OUT_OF_CANVAS;
		}
	}
	else if (s.type == TRIANGLE_UP)
	{
		if (s.x < 0 || s.x>this->col_ || s.y<0 || s.y>this->row_ || s.x - (s.height - 1)<0 || 
			s.x + (s.height - 1)>=this->col_ || s.y + (s.height - 1)>=this->row_)
		{
			cout << "error out of canvas" << endl;
			return ERROR_OUT_OF_CANVAS;
		}
	}
	this->shapes_.push_back(s);
	return this->shapes_.size() - 1;
}

void Canvas::DeleteShape(int index)
{
	int ct = 0;
	for (vector<Shape>::iterator it = this->shapes_.begin(); it != this->shapes_.end(); it++, ct++)
	{
		if (ct == index)
		{
			this->shapes_.erase(it);
			break;
		}
	}
}
void Canvas::Draw(ostream& os)
{
	vector<vector<char> > map;
	vector<char> column(this->col_, '.');
	for (int i = 0; i < this->row_; i++)
		map.push_back(column);
	for (vector<Shape>::iterator it = this->shapes_.begin(); it!=this->shapes_.end();it++)
	{
		switch (it->type)
		{
		case RECTANGLE:
			for (int i = 0; i < it->height; i++)
				for (int j = 0; j < it->width; j++)
					map[i + it->x - it->height / 2][j + it->y - it->width / 2] = it->brush;
			break;
		case TRIANGLE_DOWN:
			for (int i = 0; i < it->height; i++)
				for (int j = -i ; j < i + 1; j++)
					map[it->x - i][it->y - j] = it->brush;
				break;
		case TRIANGLE_UP:
			for (int i = 0; i < it->height; i++)
				for (int j = -i; j < i + 1; j++)
					map[it->x + i][it->y - j] = it->brush;
			break;
		}
	}

	for (int i = 0; i < this->row_ + 1; i++)
	{
		for (int j = 0; j < this->col_ + 1; j++)
		{
			if (!j && i)
				os << ((i - 1) % 10);
			else if (j && !i)
				os << ((j - 1) % 10);
			else if (i == 0 && j == 0)
				os << ' ';
			else
			{
				os << map[i - 1][j - 1];
			}
		}
		os << endl;
	}
}

void Canvas::Dump(ostream& os)
{
	for (int i = 0; i < this->shapes_.size(); i++)
	{
		if (this->shapes_.at(i).type==RECTANGLE)
			os << i << " " << "rect" << " " << this->shapes_.at(i).x << " " << this->shapes_.at(i).y 
				<< " " << this->shapes_.at(i).width << " " << this->shapes_.at(i).height << ' '<< this->shapes_.at(i).brush << endl;
		else if (this->shapes_.at(i).type==TRIANGLE_DOWN)
			os << i << " " << "tri_down" << " " << this->shapes_.at(i).x << " " << this->shapes_.at(i).y
			<< " " << this->shapes_.at(i).height << " " << this->shapes_.at(i).brush << endl;
		else if (this->shapes_.at(i).type == TRIANGLE_UP)
			os << i << " " << "tri_up" << " " << this->shapes_.at(i).x << " " << this->shapes_.at(i).y
			<< " " << this->shapes_.at(i).height << " " << this->shapes_.at(i).brush << endl;
	}
}
