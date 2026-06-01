bin/wieselcat: main.cpp visualization.cpp visualization.h terrain.cpp terrain.h message.cpp message.h
	g++ -std=c++11 -Wall *.cpp *.h -o bin/wieselcat
