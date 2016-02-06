#ifndef __hw06__Torrent__
#define __hw06__Torrent__

#include <string>

using namespace std;

//rated 되지 않은 torrent들과 관련되 함수 및 변수.

class Torrent {
public:
	Torrent();
	Torrent(const Torrent& Torrent);
	Torrent(const string& name, int maxSize, int seeder);

	string name() const;  // 토렌트 파일의 이름
	int seeder() const;  // seeder의 수
	int maxSize() const; // 다운로드가 완료됐을 때의 토렌트 파일의 크기
	int currentSize() const;
	int download(int _second); // _second만큼 다운로드된 이후 용량 return
	
	// 다운로드에 대한 자세한 설명은 아래 참조

	// 필요시 함수 추가 구현 가능

private:
	string name_;
	int maxSize_, seeder_, currentSize_;// 멤버변수를 정의.	
};

istream& operator>>(istream& is, Torrent& torrent);

#endif