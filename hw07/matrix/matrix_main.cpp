#include <map>
#include <string>
#include "matrix.h"
using namespace std;

bool ParseMatrix(const map<string, Matrix>& matrices, const string& str, Matrix* mat)
{
	bool negate = false, transpose = false;
	string name = str;
		switch (str.length())
		{
			case 1: break;
			case 2: if (str[0] == '-')
					{
						negate = true;
						name = name.substr(1);
					}
					else if (str[1] == '\'')
					{
						transpose = true;
						name = name.substr(0, 1);
					}
					else
						break;
					break;
			case 3: if (str[0] == '-')
					{
						negate = true;
						name = name.substr(1);
					}
					if (str[2] == '\'')
					{
						transpose = true;
						name = name.substr(1, 2);
					}
					break;
		}
		map<string, Matrix>::const_iterator it = matrices.find(name);
		if (it == matrices.end()) return false;
		*mat = negate ? -it->second : it->second;
		if (transpose) *mat = mat-> Transpose();
		return true;
}
int main() {
	map<string, Matrix> matrices;
		string cmd;
		while (cmd != "quit") {
			cin >> cmd;
				if (cmd == "matrix") {
					string name;
						Matrix mat;
						cin >> name >> mat;
						matrices[name] = mat;
						cout << name << ":" << endl << mat;
				}
				else if (cmd == "list") {
					for (map<string, Matrix>::const_iterator it = matrices.begin();
						it != matrices.end(); ++it) {
						cout << it->first << " "<< it->second.rows() << " " << it->second.cols() << endl;
					}
				}
				else if (cmd == "print") {
					string str;
						cin >> str;
						Matrix mat;
						if (ParseMatrix(matrices, str, &mat)) cout << mat;
						else cout << atoi(str.c_str()) << endl;
				}
				else if (cmd == "eval") {
					string lhs, op, rhs;
						cin >> lhs >> op >> rhs;
						Matrix lmat, rmat;
						bool left = ParseMatrix(matrices, lhs, &lmat);
						bool right = ParseMatrix(matrices, rhs, &rmat);
						int lval = left ? 0 : atoi(lhs.c_str());
						int rval = right ? 0 : atoi(rhs.c_str());
						if (left && right) {
							if (op == "+") cout << (lmat + rmat);
							else if (op == "-") cout << (lmat - rmat);
							else if (op == "*") cout << (lmat * rmat);
							else cout << "Invalid operator " << op << endl;
						}
						else if (left) {
							if (op == "+") cout << (lmat + rval);
							else if (op == "-") cout << (lmat - rval);
							else if (op == "*") cout << (lmat * rval);
							else cout << "Invalid operator " << op << endl;
						}
						else if (right) {
							if (op == "+") cout << (lval + rmat);
							else if (op == "-") cout << (lval - rmat);
							else if (op == "*") cout << (lval * rmat);
							else cout << "Invalid operator " << op << endl;
						}
						else {
							if (op == "+") cout << (lval + rval) << endl;
							else if (op == "-") cout << (lval - rval) << endl;
							else if (op == "*") cout << (lval * rval) << endl;
							else cout << "Invalid operator " << op << endl;
						}
				}
		}
	return 0;
}