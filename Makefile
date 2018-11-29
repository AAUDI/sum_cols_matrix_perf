#############################################################################################
# Makefile for compiling files  (.cpp .hpp) 
#############################################################################################

ifeq ($(TARGET), 0)
LDFLAGS += -fopenmp #just for OpenMPTimer
CXXFLAGS += -DVERSION1
else
ifeq ($(TARGET), 1)
LDFLAGS += -fopenmp #just for OpenMPTimer
CXXFLAGS += -DVERSION2
else
ifeq ($(TARGET), 2)
CXXFLAGS += -DVERSION2_OPENMP
LDFLAGS += -fopenmp
else 
ifeq ($(TARGET), 3)
CXXFLAGS += -DVERSION2_PTHREADS
LDFLAGS += -lpthread -fopenmp
endif
endif
endif
endif

CXX = g++-5
CXXFLAGS += -std=c++11 
LDFLAGS += -lm

OBJS = main.o matrix.o matrix_template.o OpenMPTimer.o

ifeq ($(TARGET), 0)
ver1.bin : $(OBJS)
	$(CXX) $(CXXFLAGS) -o ver1.bin $(OBJS) $(LDFLAGS)
else 
ifeq ($(TARGET), 1)
ver2.bin : $(OBJS)
	$(CXX) $(CXXFLAGS) -o ver2.bin $(OBJS) $(LDFLAGS)
else 
ifeq ($(TARGET), 2)
ver2_openmp.bin : $(OBJS)
	$(CXX) $(CXXFLAGS) -o ver2_openmp.bin $(OBJS) $(LDFLAGS)
else 
ifeq ($(TARGET), 3)
ver2_pthreads.bin : $(OBJS)
	$(CXX) $(CXXFLAGS) -o ver2_pthreads.bin $(OBJS) $(LDFLAGS)
endif
endif
endif
endif

main.o : main.cpp matrix.hpp matrix_template.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp  $(LDFLAGS)

matrix.o : matrix.cpp matrix.hpp 
	$(CXX) $(CXXFLAGS) -c matrix.cpp $(LDFLAGS)

matrix_template.o : matrix_template.cpp matrix_template.hpp 
	$(CXX) $(CXXFLAGS) -c matrix_template.cpp $(LDFLAGS)

OpenMPTimer.o : OpenMPTimer.cpp 
	$(CXX) $(CXXFLAGS) -c OpenMPTimer.cpp  $(LDFLAGS)

clean : 
	rm *.o *.bin
