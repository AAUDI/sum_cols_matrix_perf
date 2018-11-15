sum_cols_matrix.bin : main.o  matrix.o OpenMPTimer.o
	g++ -o main.bin main.o matrix.o OpenMPTimer.o -lm -fopenmp

main.o : main.cpp matrix.hpp
	g++ -c main.cpp

matrix.o : matrix.cpp matrix.hpp
	g++ -c matrix.cpp

OpenMPTimer.o : OpenMPTimer.cpp OpenMPTimer.h
	g++ -c OpenMPTimer.cpp

clean : 
	rm *.o *.bin
