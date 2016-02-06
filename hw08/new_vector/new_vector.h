#include <vector>
#include <iostream>
using namespace std;

class NewVector{
private:
	vector<char> vc;
	vector<int> vi;
	vector<double> vd;
	vector<size_t> va;
public:
	NewVector(){}
	void add(int value)
	{
		vi.push_back(value);
		va.push_back(0); //int는 index 0
	}
	void add(char value)
	{
		vc.push_back(value);
		va.push_back(1); //char는 index 1
	}
	void add(double value)
	{
		vd.push_back(value);
		va.push_back(2);//double 은 index 2
	}
	ostream& operator<<(ostream& out)
	{
		size_t i[3] = { 0, };
		for (size_t k = 0; k < this->va.size(); k++)
		{
			size_t nIdx = this->va[k];
			i[nIdx]++;
			switch (nIdx)
			{
			case 0:
				out << this->vi[i[nIdx]-1];
				break;
			case 1:
				out << this->vc[i[nIdx] - 1];
				break;
			case 2:
				out << this->vd[i[nIdx] - 1];
				break;
			}
			out << " ";
		}
		return out;
	}
	~NewVector(){}
};
