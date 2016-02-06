#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#pragma once

#define BLACK -1
#define NOBODY 0
#define WHITE 1
#define GROUND_SIZE 19

using namespace std;
class Omok {
public:
  Omok() : width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(BLACK) {
    this->last.first = -1;
    this->last.second = -1;
    vector<char> column(GROUND_SIZE, 0);
    for (int i = 0; i < GROUND_SIZE; i++)
      this->map.push_back(column);

    vector<int> temp;
    temp.push_back(-2);
    temp.push_back(-1);
    temp.push_back(1);
    temp.push_back(2);
    this->dx.push_back(temp);
    this->dx.push_back(temp);
    this->dx.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    this->dx.push_back(temp);
    this->dy.push_back(temp);
    temp.clear();
    temp.push_back(-2);
    temp.push_back(-1);
    temp.push_back(1);
    temp.push_back(2);
    this->dy.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(1);
    temp.push_back(-1);
    temp.push_back(-2);
    this->dy.push_back(temp);
    temp.clear();
    temp.push_back(-2);
    temp.push_back(-1);
    temp.push_back(1);
    temp.push_back(2);
    this->dy.push_back(temp);
  }
  int Put(int x, int y);
  bool IsOmok();
  int Turn() const;
  vector< vector<char> > map;
  pair<int, int> last;
  void doNot() const;
  void print() const;
private:
  int width_, height_;
  vector<vector<int> > dx, dy;
  int turn_;
  bool isEmpty(int x, int y) const;
  bool puut(int x, int y);
};


// 오목 판 출력
std::ostream& operator<<(std::ostream& os, Omok& omok);
std::istream& operator>>(std::istream& os, Omok& omok);
