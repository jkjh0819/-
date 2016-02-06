#include "torrent.h"


Torrent::Torrent()
{
	this->name_ = "";
	this->maxSize_ = 0;
	this->seeder_ = 0;
	this->currentSize_ = 0;
}
Torrent::Torrent(const Torrent& Torrent)
{
	this->name_ = Torrent.name_;
	this->maxSize_ = Torrent.maxSize_;
	this->seeder_ = Torrent.seeder_;
	this->currentSize_ = Torrent.currentSize_;
}
Torrent::Torrent(const string& name, int maxSize, int seeder)
{
	this->name_ = name;
	this->maxSize_ = maxSize;
	this->seeder_ = seeder;
	this->currentSize_ = 0;
}

string Torrent::name() const
{
	return this->name_;
}

int Torrent::seeder() const
{
	return this->seeder_;
}

int Torrent::maxSize() const
{
	return this->maxSize_;
}

int Torrent::currentSize() const
{
	return this->currentSize_;
}

int Torrent::download(int _second)
{
	this->currentSize_ += _second * seeder();
	return this->currentSize_;
}

istream& operator>>(istream& is, Torrent& torrent)
{
	return is;
}