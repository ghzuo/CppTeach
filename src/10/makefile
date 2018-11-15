RWDIST = randomWalk.o rwdist.o
RWTIME = randomWalk.o rwtime.o
RWTEST = randomWalk.o test.o
STRCOUNT = strCount.o
BINS = test rwtime rwdist strCount

CC  = gcc -std=c11
CXX = g++ -std=c++11

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
	$(CXX) $(RWDIST) -o $@ $(LIBS) $(CFLAGS)

rwtime: $(RWTIME)
	$(CXX) $(RWTIME) -o $@ $(LIBS) $(CFLAGS)

test: $(RWTEST)
	$(CXX) $(RWTEST) -o $@ $(LIBS) $(CFLAGS)

strCount: $(STRCOUNT)
	$(CXX) $(LIBS) $(CFLAGS) -o $@ $(STRCOUNT)

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
