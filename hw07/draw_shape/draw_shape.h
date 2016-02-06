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
		// Canvas 크기를 w x h 로 변경한다. 그려진 내용은 보존한다.
	void Resize(size_t w, size_t h);
		// (x,y) 위치에 ch 문자를 그린다. 범위 밖의 x,y 는 무시한다.
	bool Draw(int x, int y, char brush);
		// 그려진 내용을 모두 지운다 ('.'으로 초기화)
	void Clear();
private:
	// 그려진 모양을 저장할 수 있도록 데이터멤버를 정의 (resize 가능에 주의)
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
	virtual string type() const = 0;	//각 타입별로 리턴을 해줘야하므로 pure virtual
	virtual int x(){ return start_x; } //짧은 줄이라 헤더에다가 해줬는데 옮기는게 나은가요? 각각 x,y좌표,높이,넓이,문자반환이에요.
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