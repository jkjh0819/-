//2015004257
#include "minesweeper.h"


//private functions
void Minesweeper::eoc(int flag)
{
	if (this->end)
		cout << "DEAD(" << this->chk_cnt << ")" << endl;
	else

	if (flag)
		this->print();
}
bool Minesweeper::isIn(int x, int y)
{
	if (this->map.empty() || this->map.size()-2 < x || this->map.at(0).size()-2 < y)
		return false;
	return true;
}
bool Minesweeper::cMine(int x, int y)
{
	int dx[] = { 0,1,1,1,0,-1,-1,-1 },
		dy[] = { 1,1,0,-1,-1,-1,0,1 };

	if (!isIn(x, y))
		return false;

	if (this->map[x][y] == MINE)
	{
		this->map[x][y] = 0;
		for (int k = 0; k < 8; k++)
			if (this->map[x+dx[k]][y+dy[k]] == MINE)
				this->map[x][y]++;

		for (int k = 0; k < 8; k++)
			if (this->map[x+dx[k]][y+dy[k]] != MINE)
				this->map[x + dx[k]][y + dy[k]]--;
	}
	else
	{
		this->map[x][y] = MINE;
		for (int k = 0; k < 8; k++)
			if (this->map[x + dx[k]][y + dy[k]] != MINE)
				this->map[x + dx[k]][y + dy[k]]++;
	}
	return true;
}
bool Minesweeper::touched(int x, int y)
{
	if (!isIn(x, y))
		return false;

	this->chk_cnt++;
	if (this->map[x][y] == MINE)
		this->end = true;
	else if (!this->checked[x - 1][y - 1])
		this->checked[x - 1][y - 1] = true;
	if (this->chk_cnt == this->checked.size() * this->checked.at(0).size() - this->m_cnt)
		this->end = true;
	return true;
}
bool Minesweeper::initilize(const VVC& map)
{
	if (map.empty())
		return false;
	this->map.clear();
	VC column(map.at(0).size() + 2, 0);
	for (int i = 0; i <= map.size() + 1; i++)
		this->map.push_back(column);
	this->m_cnt = 0;
	return true;
}
bool Minesweeper::playInit()
{
	if (this->map.empty())
		return false;
	this->checked.clear();
	VB column(this->map.at(0).size(), 0);
	for (int i = 0; i < this->map.size(); i++)
		this->checked.push_back(column);
	this->chk_cnt = 0;
	return true;
}
void Minesweeper::print()
{
	if (map.empty())
		return;
	for (int i = 1; i < this->map.size() - 1; i++)
	{
		for (int j = 1; j < this->map.at(0).size() - 1; j++)
			if (this->played)
				cout << (!this->checked[i - 1][j - 1] ? '_' : (char)(this->map[i][j] + '0'));
			else
				cout << (this->map[i][j] == MINE ? '*' : (char)(this->map[i][j] + '0'));
		cout << endl;
	}
}

//public functions 
Minesweeper::Minesweeper() { this->played = false; this->end = false; }
Minesweeper::~Minesweeper() { }
void Minesweeper::set(const VVC& map)
{
	size_t err = 0;
	int dx[] = { 0,1,1,1,0,-1,-1,-1 },
		dy[] = { 1,1,0,-1,-1,-1,0,1 };
	if (!this->initilize(map))
		return ;
	for (int i = 0; i < map.size(); i++)
		for (int j = 0; j < map.at(0).size(); j++)
			if (map[i][j] == '*')
			{
				this->cMine(i + 1, j + 1);
				this->m_cnt++;
			}
	this->played = false;
	return this->eoc(!err);
}
void Minesweeper::toggle(int x, int y)
{
	if (!this->played)
		return this->eoc(this->cMine(x + 1, y + 1));
	return;
}
void Minesweeper::touch(int x, int y)
{
	if (this->played)
		return this->eoc(this->touched(x + 1, y + 1));
	return;
}
void Minesweeper::play(void)
{
	this->played = true;
	this->playInit();
	this->eoc(true);
}
