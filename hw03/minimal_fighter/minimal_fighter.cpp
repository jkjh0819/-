//2015004257
#include "minimal_fighter.h"

MinimalFighter::MinimalFighter()
{
	this->setHp(0);
	this->mPower = 0;
	this->mStatus = Invalid;
}
MinimalFighter::MinimalFighter(int _hp, int _power)
{
	this->setHp(_hp);
	this->mPower = _power;
	if(_hp<=0)
		this->mStatus = Dead;
	else
		this->mStatus = Alive;
}
int MinimalFighter::hp() const 
{
	return this->mHp;
}
int MinimalFighter::power() const
{
	return this->mPower;
}
FighterStatus MinimalFighter::status() const
{
	return this->mStatus;
}
void MinimalFighter::setHp(int _hp)
{
	if (_hp <= 0)
	{
		this->mStatus = Dead;
	}
	this->mHp = _hp;
}
void MinimalFighter::hit(MinimalFighter *_enemy)
{
	if(this->hp()<=0||_enemy->hp()<=0)
		return;	
	this->setHp(this->hp() - _enemy->power());
	_enemy->setHp(_enemy->hp() - this->power());
}
void MinimalFighter::attack(MinimalFighter *_target)
{
	if(this->hp()<=0)
		return;
	_target->setHp(_target->hp() - this->power());
	this->mPower = 0;
}
void MinimalFighter::fight(MinimalFighter *_enemy)
{
	if(this->hp()<=0||_enemy->hp()<=0)
		return;	
	while (this->status() == Alive && _enemy->status() == Alive)
		this->hit(_enemy);
}