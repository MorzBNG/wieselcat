bin/wieselcat: main.cpp visualization.cpp visualization.h terrain.cpp terrain.h message.cpp
	g++ -std=c++11 -Wall *.cpp *.h -o bin/wieselcat

#https://github.com/mesonbuild/meson
