#include "aus_vote.h"

AusVoteSystem::AusVoteSystem(const vector<string>& candidate_names)
{
	for (vector<string>::const_iterator it = candidate_names.begin(); it != candidate_names.end(); it++)
	{
		this->names_.push_back(*it);
	}
}

bool AusVoteSystem::AddVote(const vector<int>& vote)
{

	if (vote.size() != names_.size())
		return false;
	for (vector<int>::const_iterator it = vote.begin(); it != vote.end(); it++)
	{
		if (*it <= 0 || *it > names_.size())
			return false;
	}
	votes_.push_back(vote);
	return true;
}

typedef vector<Candidate> RoundResult;
vector<RoundResult> AusVoteSystem::ComputeResult() const
{
	vector<RoundResult> ret;
	vector<int> exc;

	while (true)
	{
		int * votes = new int[names_.size()];
		for (int i = 0; i < names_.size(); i++)
		{
			votes[i] = 0;
		}
		for (vector<vector<int> >::const_iterator it = votes_.begin(); it != votes_.end(); it++)
		{
			for (vector<int>::const_iterator v_it = (*it).begin(); v_it != (*it).end(); v_it++)
			{
				if (find(exc.begin(), exc.end(), *v_it) == exc.end())
				{
					votes[(*v_it) - 1]++;
					break;
				}
			}
		}
		vector<Candidate> each_r;
		int max_vote = 0;
		int min_vote = votes_.size();
		for (int i = 1; i <= names_.size(); i++)
		{
			if (find(exc.begin(), exc.end(), i) == exc.end())
			{
				each_r.push_back({ names_[i - 1], votes[i - 1] });
				if (votes[i - 1] > max_vote)
					max_vote = votes[i - 1];

				if (min_vote > votes[i - 1])
					min_vote = votes[i - 1];
			}
		}
		for (int i = 1; i <= names_.size(); i++)
		{
			if (votes[i - 1] == min_vote)
				exc.push_back(i);
		}
		ret.push_back(each_r);
		if (each_r.size() == 1 || max_vote > votes_.size()/2 || each_r.empty())
			break;
		delete[] votes;
	}

	return ret;
}
