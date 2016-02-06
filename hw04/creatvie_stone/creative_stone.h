//2015004257

#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <string>

#pragma once

#define ERR_NO_TARGET	1
#define ERR_DUP_NAME	2
#define ERR_WRONG_ARG	4
#define ERR_ETC			8

#define pII pair<int, int> 
#define pSII pair<string, pII>
#define mSII map<string, pII>
#define mSIIi mSII::iterator
#define vpSII vector<pSII>

using namespace std;

class CreativeStone {
private:
	mSII minions;
	CreativeStone * enemys;

	mSIIi find(const string&);
	vpSII * name_list();

	bool attacked(mSIIi, mSIIi);
	bool attacked(mSIIi, int);
	bool isDead(const mSIIi&);
	bool dead(const string&);
	void add(const string&, int, int, CreativeStone *);

	void print();
	void eoc(size_t);
public:
	CreativeStone();
	CreativeStone(CreativeStone *);
	~CreativeStone();

	void setEnemy(CreativeStone *);
	void add(const string&, int, int);
	void foeadd(const string&, int, int);
	void attack(const string&, const string&);
	void burn(int);
	void burn(const string&, int);
};
