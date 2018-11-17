sum_cols_matrix.bin : main.o  matrix.o matrix_template.o OpenMPTimer.o
	g++-5 -o main.bin main.o matrix.o matrix_template.o OpenMPTimer.o -lm -fopenmp -std=c++11

main.o : main.cpp matrix.hpp matrix_template.hpp
	g++-5 -c main.cpp -fopenmp -std=c++11

matrix.o : matrix.cpp matrix.hpp
	g++-5 -c matrix.cpp -fopenmp -std=c++11

matrix_template.o : matrix_template.cpp matrix_template.hpp
	g++-5 -c matrix_template.cpp -fopenmp -std=c++11

OpenMPTimer.o : OpenMPTimer.cpp OpenMPTimer.h
	g++-5 -c OpenMPTimer.cpp -fopenmp -std=c++11

clean : 
	rm *.o *.bin
