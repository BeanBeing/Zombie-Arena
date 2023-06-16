# Compiler
CC = g++

# .cpp files
OBJS = ./src/*.cpp

# Compiler Flags
FLAGS = -Wall -w -pedantic

# Library Flags
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Output name
OBJC = ZombieArena

# Compiled Object files
COBJ = *.o

app : $(COBJ)
	$(CC) $(FLAGS) $(LFLAGS) -o $(OBJC) $(COBJ)

ZombieArena.o: $(OBJS) ./headers/ZombieArena.hpp
	$(CC) -c ./src/ZombieArena.cpp

CreateBackground.o: $(OBJS) ./headers/ZombieArena.hpp
	$(CC) -c ./src/CreateBackground.cpp

Player.o: $(OBJS) ./headers/Player.hpp
	$(CC) -c ./src/Player.cpp

.PHONY: test clean

test: $(OBJC)
	./$(OBJC)

clean: $(OBJC)
	rm -rf $(OBJC)
