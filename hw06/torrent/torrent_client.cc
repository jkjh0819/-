#include "torrent_client.h"

TorrentClient::TorrentClient()
{}

void TorrentClient::AddTorrent(const Torrent& torrent)
{
	this->torrents_.push_back(torrent);
}

void TorrentClient::Download(int second) //존재하는 모든 토렌트들의 download(int)함수를 호출시킴.
{
	vector<Torrent>::iterator it = this->torrents_.begin();
	while (it != this->torrents_.end())
	{
		int after_down = it->download(second);
		if (after_down >= it->maxSize())
		{
			it = this->torrents_.erase(FindTorrent(it->name()));
			continue;
		}
		it++;
	}
	vector<RatedTorrent>::iterator it_r = this->ratedTorrents_.begin();
	while (it_r != this->ratedTorrents_.end())
	{
		int after_down = it_r->download(second);
		if (after_down >= it_r->maxSize())
		{
			it_r = this->ratedTorrents_.erase(FindTorrent_r(it_r->name().substr(0,it_r->name().find_first_of('('))));
			continue;
		}
		it_r++;
	}
}

void TorrentClient::DeleteTorrent(const string& name) //토렌트를 찾아 있으면 지우고 없다면 invalid. 이 때 torrent와 rated torrent가 나뉘어져있어 따로찾음
{
	int chk = 0;
	vector<Torrent>::iterator it = this->FindTorrent(name);
	if (it != this->torrents_.end())
	{
		this->torrents_.erase(it);
	}
	else
		chk++;
	vector<RatedTorrent>::iterator it_r = this->FindTorrent_r(name);
	if (it_r != this->ratedTorrents_.end())
	{
		this->ratedTorrents_.erase(it_r);
	}
	else chk++;
	if (chk == 2)
		cout << "invalid operation." << endl;
}

void TorrentClient::AddRatedTorrent(const RatedTorrent& ratedTorrent)
{
	this->ratedTorrents_.push_back(ratedTorrent);
}

void TorrentClient::Rate(const string& name, int rating)
{
	vector<Torrent>::iterator it = this->FindTorrent(name);
	RatedTorrent temp(*it);
	temp.setRate(rating);
	this->ratedTorrents_.push_back(temp);
	this->torrents_.erase(it);
}

vector<Torrent>::iterator TorrentClient::FindTorrent(const string& name)
{
	vector<Torrent>::iterator it = this->torrents_.begin();
	while (it != this->torrents_.end())
	{
		if (it->name() == name)
		{
			return it;
		}
		it++;
	}
	return it;
}

vector<RatedTorrent>::iterator TorrentClient::FindTorrent_r(const string& name)
{
	vector<RatedTorrent>::iterator it = this->ratedTorrents_.begin();
	while (it != this->ratedTorrents_.end())
	{
		if (it->name().substr(0,(it->name().find_first_of('('))) == name)
		{
			return it;
		}
		it++;
	}
	return it;
}

void TorrentClient::Print()
{
	for (vector<RatedTorrent>::iterator it=this->ratedTorrents_.begin(); it != this->ratedTorrents_.end(); it++)
	{
		cout << it->currentSize() << "/" << it->maxSize() << " " << it->name() << endl;
	}
	for (vector<Torrent>::iterator it=this->torrents_.begin(); it != this->torrents_.end(); it++)
	{
		cout << it->currentSize() << "/" << it->maxSize() << " " << it->name() << endl;
	}
}