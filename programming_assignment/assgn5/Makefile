#risk Graph Makefile

#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic
OBJS = riskGraph.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

riskGraph.o: riskGraph.cpp riskGraph.h
	$(COMPILE) $(FLAGS) -c riskGraph.cpp

clean:
	rm -rf *~ *.o a.out
