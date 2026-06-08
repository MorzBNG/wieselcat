CXX = g++

bin/wieselcat: main.cpp visualization.cpp visualization.h terrain.cpp terrain.h message.cpp message.h
	$(CXX) -std=c++11 -Wall -Wextra $^ -o $@
