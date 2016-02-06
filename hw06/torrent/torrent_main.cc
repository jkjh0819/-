//상속을 이해를 못한 상태로 상속이 되었음에도 부모와 같은 변수와 함수를 재선언해서 코드를 짬.
//다음주에 contest이후 다시 짤 예정.

#include "torrent_client.h"
#include "rated_torrent.h"
#include "torrent.h"

int main()
{
	TorrentClient client;
	while (true)
	{
		string command;
		getline(cin, command);
		string *argv = new string[command.length()];
		string token;
		size_t pos;
		int argc = 0;
		while (true)
		{
			pos = command.find(' ');
			token = command.substr(0, pos);
			argv[argc++] = token;

			if (pos >= command.length()) break;
			else command.erase(0, pos + 1);
		}
		if (argv[0] == "add")
		{
			Torrent torrent(argv[1], atoi(argv[2].c_str()), atoi(argv[3].c_str()));
			client.AddTorrent(torrent);
		}
		else if (argv[0] == "add_rate")
		{
			RatedTorrent rated(argv[1], atoi(argv[2].c_str()), atoi(argv[3].c_str()), atoi(argv[4].c_str()));
			client.AddRatedTorrent(rated);
		}
		else if (argv[0] == "delete")
		{
			client.DeleteTorrent(argv[1]);
		}
		else if (argv[0] == "print")
		{
			client.Print();
		}
		else if (argv[0] == "download")
		{
			client.Download(atoi(argv[1].c_str()));
		}
		else if (argv[0] == "rate")
		{
			client.Rate(argv[1], atoi(argv[2].c_str()));
		}
		else if (argv[0] == "quit")
			return 0;
		else
			break;
	}
	return 0;
}

