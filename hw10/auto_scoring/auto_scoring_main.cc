#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>

#define MAX 10
#define LOOP 5
#define BUFFERSIZE 256

using namespace std;
void str(char * data)
{
	if (!strlen(data))
		cout << "EMPTY";
	else
		cout << "[" << data << "]";
}
int msg(int no, int line, char * ori, char * ans)
{
	cout << "No." << no << ", LINE " << line << ": ";
	str(ori);
	cout << " MUST BE ";
	str(ans);
	cout << endl;
	return -1;
}
int main(int argc, char * argv[])
{
	string pName;
	if (argc < 2)
		cin >> pName;
	else
		pName = argv[1];

	system("mkdir temp");

	for (int i = 1; i <= LOOP; i++)
	{
		string run = "./" +pName + " < " + pName + "_data/" + to_string(i) + ".in > " + "temp/" + to_string(i) + ".out";
		system(run.c_str());
	}
	int check[5]={0,};
	int total = MAX;
	for (int i = 1; i <= LOOP; i++)
	{
		fstream fs("temp/" + to_string(i) + ".out"),
				as(pName + "_data/" + to_string(i) + ".out");
		
		string target, answer;
		if (fs.is_open() && as.is_open())
		{
			char buffer[BUFFERSIZE], answer[BUFFERSIZE];
			int j = 0, chksum;
			for (;as.getline(answer, BUFFERSIZE); j++)
			{
				fs.getline(buffer, BUFFERSIZE);
				if (strcmp(buffer, answer))
					check[i-1] = msg(i, j, buffer, answer);
			}
			for (;fs.getline(buffer, BUFFERSIZE);j++)
				msg(i, j, buffer, "");
		}
	}
	for(int i=0;i<5;i++){ if(check[i]==-1) total -= 2;}
	cout << "SCORE: " << total <<endl;
	system("rm -r temp");

	return 0;
}
