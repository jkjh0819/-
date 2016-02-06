#include "rated_torrent.h"


RatedTorrent::RatedTorrent()
{
	this->name_ = "";
	this->maxSize_ = 0;
	this->seeder_ = 0;
	this->currentSize_ = 0;
	this->rating_ = 0;
}

RatedTorrent::RatedTorrent(const Torrent& torrent)
{
	this->name_ = torrent.name();
	this->maxSize_ = torrent.maxSize();
	this->seeder_ = torrent.seeder();
	this->currentSize_ = torrent.currentSize();
	this->rating_ = 0;
}
RatedTorrent::RatedTorrent(const string& name, int maxSize, int seeder, int rating)
{
	this->name_ = name;
	this->maxSize_ = maxSize;
	this->seeder_ = seeder;
	this->currentSize_ = 0;
	this->rating_ = rating;
}

string RatedTorrent::name() const //rating을 추가한 이름을 반환.
{
	string rate="(";
	for (int i = 0; i < this->rating_; i++)
		rate += "*";
	rate += ")";
	string ratedName = this->name_ + rate;
	return ratedName;
}

void RatedTorrent::setRate(int rating)
{
	this->rating_ = rating;
}


istream& operator>>(istream& is, RatedTorrent& ratedTorrent) //못짜고 했음..
{
	return is;
}

int RatedTorrent::seeder() const
{
	return this->seeder_;
}

int RatedTorrent::maxSize() const
{
	return this->maxSize_;
}

int RatedTorrent::currentSize() const
{
	return this->currentSize_;
}

int RatedTorrent::download(int _second)
{
	this->currentSize_ += _second * seeder();
	return this->currentSize_;
}