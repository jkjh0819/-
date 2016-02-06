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

	// �ĺ��� ��ȣ���� 1�������� �Է�.
	// �߸��� ���ڰ� �ְų� ��ȣ�� ���� �ĺ��� ���� �ٸ���
	// �ش� �Է��� �����ϰ� false�� ����.
	bool AddVote(const vector<int>& vote);

	typedef vector<Candidate> RoundResult;
	// ���ݱ����� ��ǥ�� �������� ����� ��� ���忡 ���� ���.
	// main() ������ vector<RoundResult>�� ������Ŀ� �µ��� ���.
	vector<RoundResult> ComputeResult() const;

private:
	vector<string> names_;
	vector<vector<int> > votes_;
};

#endif