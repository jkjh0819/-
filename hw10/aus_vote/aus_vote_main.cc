#include "aus_vote.h"

int main()
{
	int can_num, vote_num;
	vector<string> can_name;
	cin >> can_num;
	for (int i = 0; i < can_num; i++)
	{
		string name;
		cin >> name;
		can_name.push_back(name);
	}
	AusVoteSystem system(can_name);
	cin >> vote_num;
	for (int i = 0; i < vote_num; i++)
	{
		vector<int> votes;
		for (int j = 0; j < can_num; j++)
		{
			int temp;
			cin >> temp;
			votes.push_back(temp);
		}
		system.AddVote(votes);
	}
	typedef vector<Candidate> RoundResult;
	vector<RoundResult> result = system.ComputeResult();
	for (int i = 0; i <= result.size(); i++)
	{
		if (i == result.size())
		{
			if (result[i - 1].empty())
				cout << "Winner: " << endl;
			else
			{
				vector<Candidate>::iterator it = result[i - 1].begin();
				cout << "Winner: " << it->name << endl;
			}
		}
		else
		{
			if (result[i].size())
			{
				cout << "Round " << i + 1 << ": ";
				for (vector<Candidate>::iterator it = result[i].begin(); it != result[i].end(); it++)
				{
					cout << it->name << " " << it->votes << " ";
				}
				cout << endl;
			}

		}
	}
	return 0;
}