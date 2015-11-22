FFTW = fftw.o
EIGENFFT = eigenfft.o
LAPACK = lapack.o
EIGEN = eigen.o
ARMADILLO = armadillo.o
BINS = fftw eigenfft  eigen armadillo lapack

CC  = gcc -std=c11
CXX = g++ -std=c++11

LIBS   = -L/usr/local/lib -lm -lfftw3 -larmadillo -lblas -llapack
CFLAGS = -I/usr/local/include -I/usr/local/include/eigen3 -I/usr/include/eigen3
ifeq ($(DEF), DEBUG)
        CFLAGS +=  -g -Wall -Wextra
else
        ifeq ($(DEF), PROF)
                CFLAGS += -O3 -pg
        else
                CFLAGS += -O3
        endif
endif


all: $(BINS)

fftw: $(FFTW)
	$(CXX) $(LIBS) $(CFLAGS) -o $@ $(FFTW)
eigenfft: $(EIGENFFT)
	$(CXX) $(LIBS) $(CFLAGS) -o $@ $(EIGENFFT)
lapack: $(LAPACK)
	$(CXX) $(LIBS) $(CFLAGS) -o $@ $(LAPACK)
eigen: $(EIGEN)
	$(CXX) $(LIBS) $(CFLAGS) -o $@ $(EIGEN)
armadillo: $(ARMADILLO)
	$(CXX) $(LIBS) $(CFLAGS) -o $@ $(ARMADILLO)



#############################################################

clean:
	rm -f *.o

cleanall: clean 
	rm -f $(BINS)

##############################################################
.SUFFIXES: .f90 .f .o .mod .F .c .cpp

.c.o:
	$(CC)  $(CFLAGS) -c $<

.cpp.o:
	$(CXX) $(CFLAGS) -c $<
