//2015004257
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

#define MINE -1

#define VB vector<bool>
#define VVB vector<VB>
#define VVBi VVB::iterator

#define VC vector<char>
#define VVC vector<VC>
#define VVCi VVC::iterator

using namespace std;
class Minesweeper {
private:
	VVC map;
	VVB checked;
	bool end;
	size_t chk_cnt;
	size_t m_cnt;
	void eoc(int);
	bool played;
	bool isIn(int, int);
	bool initilize(const VVC&);
	bool playInit();
	bool cMine(int, int);
	bool touched(int, int);
	void print();
public:
	Minesweeper();
	~Minesweeper();

	void set(const VVC&);
	void toggle(int, int);
	void touch(int, int);
	void play(void);
};
