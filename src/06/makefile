RWDIST = randomWalk.o rwdist.o
RWTIME = randomWalk.o rwtime.o
RWTEST = randomWalk.o test.o
BINS = test rwtime rwdist

CC  = gcc
CXX = g++

LIBS = -lm
ifeq ($(DEF), DEBUG)
        CFLAGS = -g -Wall -Wextra 
else
        ifeq ($(DEF), PROF)
                CFLAGS = -O3 -pg 
        else
                CFLAGS = -O3 
        endif
endif

all: $(BINS)

rwdist: $(RWDIST)
	$(CC) $(RWDIST) -o $@ $(LIBS) $(CFLAGS)

rwtime: $(RWTIME)
	$(CC) $(RWTIME) -o $@ $(LIBS) $(CFLAGS)

test: $(RWTEST)
	$(CC) $(RWTEST) -o $@ $(LIBS) $(CFLAGS)


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
