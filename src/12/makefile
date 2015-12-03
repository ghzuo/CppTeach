RMSD = rmsd.o
BINS = rmsd

CC  = gcc -std=c11
CXX = g++ -std=c++11

LIBS   = -L/usr/local/lib -lm 
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

rmsd: $(RMSD)
	$(CXX) $(LIBS) $(CFLAGS) -o $@ $(RMSD)

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
