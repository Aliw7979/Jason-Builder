CC=g++ -std=c++11

all: 1.out

1.out:main.o AllObjects.o IntData.o JsonBuilder.o Object.o StrData.o
		${CC} main.o AllObjects.o IntData.o JsonBuilder.o Object.o StrData.o -o 1.out


main.o: main.cpp JsonBuilder.hpp
		${CC} -c main.cpp

AllObjects.o: AllObjects.cpp AllObjects.hpp 
		${CC} -c AllObjects.cpp

IntData.o: IntData.cpp IntData.hpp Defines.hpp AllObjects.hpp
		${CC} -c IntData.cpp

JsonBuilder.o: JsonBuilder.cpp JsonBuilder.hpp Object.hpp StrData.hpp IntData.hpp Defines.hpp
		${CC} -c JsonBuilder.cpp

Object.o: Object.cpp Object.hpp Defines.hpp AllObjects.hpp
		${CC} -c Object.cpp

StrData.o: StrData.cpp StrData.hpp AllObjects.hpp Defines.hpp
		${CC} -c StrData.cpp


clean:
	rm *.o
	rm 1.out