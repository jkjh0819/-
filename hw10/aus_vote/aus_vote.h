#ifndef __hw10__aus_vote_
#define __hw10__aus_vote_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Candidate {
	std::string name;
	int votes;
};

class AusVoteSystem {
public:
	AusVoteSystem(const vector<string>& candidate_names);

	// 후보별 선호도를 1순위부터 입력.
	// 잘못된 숫자가 있거나 선호도 수가 후보자 수와 다르면
	// 해당 입력을 무시하고 false를 리턴.
	bool AddVote(const vector<int>& vote);

	typedef vector<Candidate> RoundResult;
	// 지금까지의 투표를 바탕으로 결과를 모든 라운드에 대해 계산.
	// main() 에서는 vector<RoundResult>를 출력형식에 맞도록 출력.
	vector<RoundResult> ComputeResult() const;

private:
	vector<string> names_;
	vector<vector<int> > votes_;
};

#endif