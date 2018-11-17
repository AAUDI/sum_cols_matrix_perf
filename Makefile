sum_cols_matrix.bin : main.o  matrix.o OpenMPTimer.o
	g++-5 -o main.bin main.o matrix.o OpenMPTimer.o -lm -fopenmp

main.o : main.cpp matrix.hpp
	g++-5 -c main.cpp -fopenmp

matrix.o : matrix.cpp matrix.hpp
	g++-5 -c matrix.cpp -fopenmp

OpenMPTimer.o : OpenMPTimer.cpp OpenMPTimer.h
	g++-5 -c OpenMPTimer.cpp -fopenmp

clean : 
	rm *.o *.bin
