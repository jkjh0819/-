all : rated_torrent.o torrent.o torrent_client.o torrent_main.o
	g++ -o torrent rated_torrent.o torrent.o torrent_client.o torrent_main.o

torrent_main.o : torrent_main.cc
	g++ -c torrent_main.cc

rated_torrent.o : rated_torrent.cc
	g++ -c rated_torrent.cc

torrent_client.o : torrent_client.cc
	g++ -c torrent_client.cc

torrent.o : torrent.cc
	g++ -c torrent.cc