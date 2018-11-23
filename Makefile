#############################################################################
# Makefile for compiling files  (.cpp .hpp) 
# please try :
# make TARGET_ARCH 1 (compiling for MULTICORES ARCH (OPENMP))
# make TARGET_ARCH 2 (compiling for MULTICORES ARCH (OPENMP))
# make standard compiling 
#############################################################################

ifeq ($(TARGET_ARCH), 1)
CXXFLAGS += -DOPENMP
LDFLAGS += -fopenmp
else 
ifeq ($(TARGET_ARCH), 2)
CXXFLAGS += -DPTHREADS
LDFLAGS += -lpthread -fopenmp
else
ifeq ($(TARGET_ARCH), 3)
CXXFLAGS += -DGPU
else
CXXFLAGS += -DNO_OPENMP_GPU
LDFLAGS += -fopenmp
endif
endif
endif
CXX = g++-5
CXXFLAGS += -std=c++11
LDFLAGS += -lm
OBJS = main.o matrix.o matrix_template.o OpenMPTimer.o


.PHONY : clean

ifeq ($(TARGET_ARCH), 1)
main_openmp.bin : $(OBJS)
	$(CXX) $(CXXFLAGS) -o main_openmp.bin $(OBJS) $(LDFLAGS)
else 
ifeq ($(TARGET_ARCH), 2)
main_pthreads.bin : $(OBJS)
	$(CXX) $(CXXFLAGS) -o main_pthreads.bin $(OBJS) $(LDFLAGS)
else 
ifeq ($(TARGET_ARCH), 1)
main_gpu.bin : $(OBJS)
	$(CXX) $(CXXFLAGS) -o main_gpu.bin $(OBJS) $(LDFLAGS)
else
main_no_optimization.bin : $(OBJS)
	$(CXX) $(CXXFLAGS) -o main_no_optimization.bin $(OBJS) $(LDFLAGS)
endif
endif
endif
main.o : main.cpp matrix.hpp matrix_template.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp  $(LDFLAGS)

matrix.o : matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp $(LDFLAGS)

matrix_template.o : matrix_template.cpp matrix_template.hpp
	$(CXX) $(CXXFLAGS) -c matrix_template.cpp $(LDFLAGS)

OpenMPTimer.o : OpenMPTimer.cpp OpenMPTimer.h
	$(CXX) $(CXXFLAGS) -c OpenMPTimer.cpp  $(LDFLAGS)

clean : 
	rm *.o
