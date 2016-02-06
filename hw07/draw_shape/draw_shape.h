#ifndef __hw07_draw_shape__
#define __hw07_draw_shape__

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Canvas {
public:
	Canvas(size_t row, size_t col);
	~Canvas();
		// Canvas ũ�⸦ w x h �� �����Ѵ�. �׷��� ������ �����Ѵ�.
	void Resize(size_t w, size_t h);
		// (x,y) ��ġ�� ch ���ڸ� �׸���. ���� ���� x,y �� �����Ѵ�.
	bool Draw(int x, int y, char brush);
		// �׷��� ������ ��� ����� ('.'���� �ʱ�ȭ)
	void Clear();
private:
	// �׷��� ����� ������ �� �ֵ��� �����͸���� ���� (resize ���ɿ� ����)
	vector<char> canvas;
	int row_, col_;
	friend ostream& operator<<(ostream& os, const Canvas& c);
};

class Shape {
public:
	Shape() : start_x(0), start_y(0), height(0), brush_('.'){};
	Shape(int start_x_, int start_y_, int height_, char brush_) : 
		start_x(start_x_), start_y(start_y_), height(height_), brush_(brush_){};
	virtual ~Shape();
	virtual void Draw(Canvas* canvas) const = 0;
	virtual string type() const = 0;	//�� Ÿ�Ժ��� ������ ������ϹǷ� pure virtual
	virtual int x(){ return start_x; } //ª�� ���̶� ������ٰ� ����µ� �ű�°� ��������? ���� x,y��ǥ,����,����,���ڹ�ȯ�̿���.
	virtual int y(){ return start_y; }
	virtual int h(){ return height; }
	virtual int w(){ return 0; }
	virtual char brush(){ return brush_; }
protected:
	int start_x,start_y, height;
	char brush_;
};

class Rectangle : public Shape {
public:
	Rectangle() : Shape(){};
	Rectangle(int start_x_, int start_y_, int width_, int height_, char brush_)
		: Shape(start_x_, start_y_, height_, brush_) {	width = width_;	};
	~Rectangle();
	void Draw(Canvas* canvas) const;
	int w() { return width; }
	string type() const { return "rect"; }
private:
	int width;
};
class UpTriangle : public Shape {
public:
	UpTriangle() : Shape(){};
	UpTriangle(int start_x_, int start_y_, int height_, char brush_)
		: Shape(start_x_, start_y_, height_, brush_){};
	~UpTriangle();
	void Draw(Canvas* canvas) const;
	string type() const { return "tri_up"; }
};

class DownTriangle : public Shape {
public:
	DownTriangle() : Shape(){};
	DownTriangle(int start_x_, int start_y_, int height_, char brush_)
		: Shape(start_x_, start_y_, height_, brush_){};
	~DownTriangle();
	void Draw(Canvas* canvas) const;
	string type() const { return "tri_down"; }
};

class Diamond : public Shape { 
public:
	Diamond() : Shape(){};
	Diamond(int start_x_, int start_y_, int height_, char brush_)
		: Shape(start_x_, start_y_, height_, brush_){};
	~Diamond();
	void Draw(Canvas* canvas) const;
	string type() const { return "diamond"; }
};

istream& operator>>(istream& is, Rectangle& r);
istream& operator>>(istream& is, UpTriangle& t);
istream& operator>>(istream& is, DownTriangle& d);
istream& operator>>(istream& is, Diamond& dm);

#endif