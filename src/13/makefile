CFFTW = cfftw.o
BINS  = cfftw

CC  = gcc
CXX = g++

LIBS   = -L/usr/local/lib -lm -lfftw3
CFLAGS = -I/usr/local/include
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

cfftw: $(CFFTW)
	$(CC) $(LIBS) $(CFLAGS) -o $@ $(CFFTW) 



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
