RWDIST = randomWalk.o rwdist.o
RWTIME = randomWalk.o rwtime.o
RWTEST = randomWalk.o test.o
BINS = test rwtime rwdist

CC  = gcc
CXX = g++

CFLAGS  = -O3
LIBS = -lm 

all: $(BINS)

rwdist: $(RWDIST)
	$(CXX) $(RWDIST) -o $@ $(LIBS) $(CFLAGS)

rwtime: $(RWTIME)
	$(CXX) $(RWTIME) -o $@ $(LIBS) $(CFLAGS)

test: $(RWTEST)
	$(CXX) $(RWTEST) -o $@ $(LIBS) $(CFLAGS)


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
