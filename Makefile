#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -Iinc -Wall -pedantic -std=c++17

__start__: uklad_rownan


uklad_rownan: obj/main.o obj/SMacierz.o obj/LZespolona.o obj/SWektor.o obj/Dr3D_gnuplot_api.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o\
                                   obj/LZespolona.o obj/SWektor.o obj/SMacierz.o

obj/main.o: src/main.cpp inc/SMacierz.hh inc/SWektor.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/SMacierz.o: src/SMacierz.cpp inc/SMacierz.hh
	g++ ${CPPFLAGS} -o obj/SMacierz.o src/SMacierz.cpp 

obj/SWektor.o: src/SWektor.cpp inc/SWektor.hh
	g++ ${CPPFLAGS} -o obj/SWektor.o src/SWektor.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp
	
obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp
	
obj/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

clean:
	rm -f obj/*.o uklad_rownan