#ifndef __hw06__torrent_client__
#define __hw06__torrent_client__

#include "torrent.h"
#include "rated_torrent.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class TorrentClient {
public:
	TorrentClient();
	void AddTorrent(const Torrent& torrent); //torrent를 추가
	void Download(int second); //download명령을 받는 함수
	void DeleteTorrent(const string& name); 
	void Rate(const string& name, int rating);
	void AddRatedTorrent(const RatedTorrent& ratedTorrent); //rated된 torrent를 추가
	vector<Torrent>::iterator FindTorrent(const string& name); //torrent가 존재하는지 찾는 함수.
	vector<RatedTorrent>::iterator FindTorrent_r(const string& name); //rated torrent가 존재하는지 찾는 함수.
	void Print();
	// 필요한 함수 자유롭게 구현
private:
	vector<Torrent> torrents_;  // 토렌트를 저장하는 벡터
	vector<RatedTorrent> ratedTorrents_;  // 평가된 토렌트를 저장하는 벡터
	// 그 외 필요한 변수를 추가
};

#endif