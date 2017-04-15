#Syntax Tree Make File

#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic
OBJS = syntaxTree.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

syntaxTree.o: syntaxTree.cpp syntaxTree.h
	$(COMPILE) $(FLAGS) -c syntaxTree.cpp

clean:
	rm -rf *~ *.o a.out
