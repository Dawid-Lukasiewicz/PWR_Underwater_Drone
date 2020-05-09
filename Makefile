#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -Iinc -Wall -pedantic -std=c++17

__start__: dron


dron: obj/main.o obj/SWektor.o obj/SMacierz.o obj/Rectangle.o obj/Dr3D_gnuplot_api.o obj/Templates.o
	g++ -o dron obj/main.o obj/SWektor.o obj/SMacierz.o obj/Rectangle.o obj/Dr3D_gnuplot_api.o\
                                   	obj/Templates.o -lpthread

obj/main.o: src/main.cpp inc/SMacierz.hh inc/SWektor.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/SWektor.o: src/SWektor.cpp inc/SWektor.hh
	g++ ${CPPFLAGS} -o obj/SWektor.o src/SWektor.cpp

obj/SMacierz.o: src/SMacierz.cpp inc/SMacierz.hh
	g++ ${CPPFLAGS} -o obj/SMacierz.o src/SMacierz.cpp 

obj/Rectangle.o: src/Rectangle.cpp inc/Figure.hh
	g++ ${CPPFLAGS} -o obj/Rectangle.o src/Rectangle.cpp
	
obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/Templates.o: src/Templates.cpp src/SMacierz.cpp inc/SMacierz.hh src/SWektor.cpp inc/SWektor.hh
	g++ ${CPPFLAGS} -o obj/Templates.o src/Templates.cpp

clean:
	rm -f obj/*.o uklad_rownan