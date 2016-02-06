//2015004257

#include "creative_stone.h"
#include <iostream>
#include <string>
//private functions
mSIIi CreativeStone::find(const string& name)
{
	return this->minions.find(name);
}
void CreativeStone::print()
{
	vpSII * minions_my = this->name_list();
	vpSII * minions_en = this->enemys->name_list();
	size_t idx_max = minions_my->size() > minions_en->size() ? minions_my->size() : minions_en->size();
	for (size_t idx = 0; idx < idx_max; idx++)
	{
		if (idx < minions_my->size())
			cout << minions_my->at(idx).first << " " << minions_my->at(idx).second.first << " " << minions_my->at(idx).second.second;
		if (idx < minions_en->size())
		{
			cout << " / ";
			cout << minions_en->at(idx).first << " " << minions_en->at(idx).second.first << " " << minions_en->at(idx).second.second;
		}
		cout << endl;
	}
}
vpSII * CreativeStone::name_list()
{
	vpSII * result = new vpSII;
	for (pSII minion : this->minions)
		result->push_back(minion);
	return result;
}
bool CreativeStone::isDead(const mSIIi& object)
{
	if (object->second.first <= 0)
		return true;
	return false;
}
bool CreativeStone::dead(const string& name)
{
	return this->minions.erase(name) == 0;
}
bool CreativeStone::attacked(mSIIi attacker, mSIIi target)
{
	return this->attacked(attacker, target->second.second);
}
bool CreativeStone::attacked(mSIIi target, int damage)
{
	if (target == this->minions.end())
		return 0;
	target->second.first -= damage;
	if (this->isDead(target))
		return this->dead(target->first);
	return true;
}
void CreativeStone::add(const string& name, int hp, int dmg, CreativeStone * target)
{
	size_t err = 0;
	mSIIi object = this->find(name);

	if (object == this->minions.end())
		this->minions.insert({ name,{ hp, dmg } });
	else
	{
		if (this->attacked(object, -hp))
			object->second.second += dmg;
	}
	return target->eoc(err);
}
void CreativeStone::eoc(size_t err)
{
	if (!err)
		this->print();
	else if (err == ERR_NO_TARGET)
		cout << "CANNOT FIND MINION" << endl;
}

//public functions
CreativeStone::CreativeStone() {}
CreativeStone::CreativeStone(CreativeStone * opponunt)
{
	this->enemys = opponunt;
}
CreativeStone::~CreativeStone() {}
void CreativeStone::setEnemy(CreativeStone * enemys)
{
	this->enemys = enemys;
}
void CreativeStone::add(const string& name, int hp, int dmg)
{
	return this->add(name, hp, dmg, this);
}
void CreativeStone::foeadd(const string& name, int hp, int dmg)
{
	return this->enemys->add(name, hp, dmg, this);
}
void CreativeStone::attack(const string& name, const string& opponunt)
{
	size_t err = 0;
	mSIIi attacker = this->find(name);
	if (attacker == this->minions.end())
		return this->eoc(ERR_NO_TARGET);
	mSIIi target = this->enemys->find(opponunt);
	if (target == this->enemys->minions.end())
		return this->eoc(ERR_NO_TARGET);
	int attacker_dmg = attacker->second.second;
	int target_dmg = target->second.second;
	this->enemys->attacked(target, attacker_dmg);
	this->attacked(attacker, target_dmg);
	return this->eoc(err);
}
void CreativeStone::burn(int value)
{
	size_t err = 0;
	vpSII * list = this->enemys->name_list();
	for (pSII object : *list)
		this->enemys->attacked(this->enemys->find(object.first), value);
	return this->eoc(err);
}
void CreativeStone::burn(const string& name, int value)
{
	size_t err = 0;
	if (this->enemys->find(name) == this->enemys->minions.end() || this->enemys->attacked(this->enemys->find(name), value))
		this->attacked(this->find(name), value);
	return this->eoc(err);
}
