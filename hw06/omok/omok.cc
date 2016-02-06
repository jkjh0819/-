#include "omok.h"
#pragma once
int Omok::Put(int x, int y)
{
	if (this->isEmpty(x, y))
		return this->puut(x, y);
	else
		return NOBODY;
}
bool Omok::IsOmok()
{
	bool omok = false;
	if (this->last.first == -1 && this->last.second == -1)
		return false;
	for (int i = this->last.first - 3; i < this->last.first + 3 && !omok; i++)
		for (int j = this->last.second - 3; j < this->last.second + 3 && !omok; j++)
				for (int k = 0, t = 0; k < 4; k++, t = 0)
				{
 					for (t; t < 4; t++)	//break가 걸리지 않을 때까지 t값을 증가시킨다.
						if (i + dx[k][t] >= 0 && i + dx[k][t] < 19 && j + dy[k][t] > 0 && j + dy[k][t] < 19)  //놓여진 돌의 위치를 중심으로 5x5의 위치에서 오목인 것을 찾아낸다.
						{
							if (this->map[this->last.first][this->last.second] - this->map[i + dx[k][t]][j + dy[k][t]] &&
								this->map[this->last.first][this->last.second] - this->map[i + dx[k][t]][j + dy[k][t]])	//dx dy는 놓여진 돌의 위치로부터 x,y방향으로의 변화량을 나타낸다.
								break;
						}
						else
							break;
					if (!(t - 4)) //t값이 4가 되었을때 오목이다.
					{
						omok = true;
						break;
					}
				}
	if (omok)
	{
		this->last.first = this->turn_;
		this->last.second = -1;
		this->turn_ = NOBODY;
	}
	return omok;
}
int Omok::Turn() const
{
	return this->turn_;
}
bool Omok::puut(int x, int y)   //놓을 위치를 입력받음
{
	if (x<0 || x>18 || y<0 || y>18)
		return NOBODY;
	else
	{
		bool turn = (this->map[x][y] = this->turn_) == 1;
		this->turn_ = -this->turn_;
		this->last.first = x;
		this->last.second = y;
		return turn ? WHITE : BLACK;
	}
}
bool Omok::isEmpty(int x, int y) const  //놓을 위치에 돌이 있는지 판별
{
	if (x<0 || x>18 || y<0 || y>18)
		return false;
	return this->map[x][y] == NOBODY;
}
void Omok::doNot() const
{
	cout << "Can not be placed there." << endl;
}
void Omok::print() const
{
	string mask[3];
	mask[0] = "o";
	mask[1] = ".";
	mask[2] = "x";
	for (int i = 0; i < 19; i++, cout << endl)
		for (int j = 0; j < 19; j++)
			cout << mask[this->map[i][j] + 1] << " ";
	cout << "Winner: " << (this->last.first != BLACK ? "Black" : "White") << " player" << endl;
}
std::ostream& operator<<(std::ostream& os, Omok& omok)
{
	string name_mask[3];
	name_mask[0] = "Black";
	name_mask[1] = "NOBODY";
	name_mask[2] = "White";
	os << name_mask[omok.Turn() + 1] << ": ";
	return os;
}
std::istream& operator>>(std::istream& is, Omok& omok)
{
	int x, y; is >> x >> y;
	if (omok.Put(y, x) == NOBODY)
		omok.doNot();
	return is;
}