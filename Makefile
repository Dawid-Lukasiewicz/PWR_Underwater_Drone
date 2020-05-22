#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -Iinc -Wall -pedantic -std=c++17

__start__: dron


dron: obj/main.o obj/LZespolona.o obj/SWektor.o obj/MatrixRot.o obj/Rectangle.o obj/SixPrism.o obj/Rotator.o\
									obj/Drone.o obj/Surface.o obj/Dr3D_gnuplot_api.o obj/Templates.o
	g++ -o dron obj/main.o obj/LZespolona.o obj/SWektor.o obj/MatrixRot.o obj/Rectangle.o obj/SixPrism.o obj/Rotator.o\
                                   	obj/Drone.o obj/Surface.o obj/Dr3D_gnuplot_api.o obj/Templates.o -lpthread

obj/main.o: src/main.cpp inc/MatrixRot.hh inc/SWektor.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/SWektor.o: src/SWektor.cpp inc/SWektor.hh
	g++ ${CPPFLAGS} -o obj/SWektor.o src/SWektor.cpp

obj/MatrixRot.o: src/MatrixRot.cpp inc/MatrixRot.hh
	g++ ${CPPFLAGS} -o obj/MatrixRot.o src/MatrixRot.cpp

obj/Rectangle.o: src/Rectangle.cpp inc/Rectangle.hh inc/Figure.hh inc/MatrixRot.hh
	g++ ${CPPFLAGS} -o obj/Rectangle.o src/Rectangle.cpp
	
obj/SixPrism.o: src/SixPrism.cpp inc/Figure.hh
	g++ ${CPPFLAGS} -o obj/SixPrism.o src/SixPrism.cpp
	
obj/Rotator.o: src/Rotator.cpp inc/Rotator.hh
	g++ ${CPPFLAGS} -o obj/Rotator.o src/Rotator.cpp
	
obj/Drone.o: src/Drone.cpp inc/Drone.hh
	g++ ${CPPFLAGS} -o obj/Drone.o src/Drone.cpp
	
obj/Surface.o: src/Surface.cpp inc/Surface.hh inc/Obstacle.hh
	g++ ${CPPFLAGS} -o obj/Surface.o src/Surface.cpp
	
obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/Templates.o: src/Templates.cpp src/SMacierz.cpp inc/SMacierz.hh src/SWektor.cpp inc/SWektor.hh
	g++ ${CPPFLAGS} -o obj/Templates.o src/Templates.cpp

clean:
	rm -f obj/*.o dron