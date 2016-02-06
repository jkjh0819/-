//2015004257
#ifndef __hw05__draw_shape__
#define __hw05__draw_shape__

#include <ostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

enum { RECTANGLE, TRIANGLE_UP, TRIANGLE_DOWN };
enum { ERROR_OUT_OF_CANVAS = -1, ERROR_INVALID_INPUT = -2 };

struct Shape {
	int type;
	int x, y;
	int width, height;
	char brush;  
};

class Canvas {
public:
	Canvas(size_t row, size_t col);
	~Canvas();
	int AddShape(const Shape &s); 
	void DeleteShape(int index);
	void Draw(ostream& os);
	void Dump(ostream& os);

private:
	size_t row_, col_;
	vector<Shape> shapes_;
};

#endif