#ifndef __hw06__RatedTorrent__
#define __hw06__RatedTorrent__

#include "torrent.h"
#include <string>

using namespace std;

//rated 된 torrent들과 관련된 함수 및 변수.

class RatedTorrent : public Torrent {
public:
	RatedTorrent();
	RatedTorrent(const Torrent& torrent);
	RatedTorrent(const string& name, int maxSize, int seeder, int rating);
	
	int seeder() const;  // seeder의 수
	int maxSize() const; // 다운로드가 완료됐을 때의 토렌트 파일의 크기
	int currentSize() const;
	int download(int _second); // _second만큼 다운로드된 이후 용량 return
	void setRate(int rating);
	// ‘torrent(***)' 처럼 평가 점수를 원래 이름에 추가하여 리턴 (최고점은 5점)
	string name() const;
	
	// 필요시 함수 추가 구현 가능

private:
	string name_;
	int rating_, maxSize_, seeder_, currentSize_;
};

istream& operator>>(istream& is, RatedTorrent& ratedTorrent);

#endif