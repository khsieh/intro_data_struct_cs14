#Word Ladder Makefile

#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic
OBJS = wordLadder.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

wordLadder.o: wordLadder.cpp wordLadder.h
	$(COMPILE) $(FLAGS) -c wordLadder.cpp

clean:
	rm -rf *~ *.o a.out
