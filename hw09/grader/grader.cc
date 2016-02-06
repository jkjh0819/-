#include "grader.h"


string SubjectPassFail::GetGrade(int score) const
{

	return score >= pass_score_ ? "P" : "F";
}

string SubjectGrade::GetGrade(int score) const
{
	if (score >= cutA_)
		return "A";
	else if (score >= cutB_)
		return "B";
	else if (score >= cutC_)
		return "C";
	else if (score >= cutD_)
		return "D";
	else
		return "F";
}
