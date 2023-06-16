# Compiler
CC = g++

# .cpp files
OBJS = ./src/*.cpp

# Compiler Flags
FLAGS = -Wall -w -pedantic

# Library Flags
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Output name
OBJC = app


app : $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $(OBJC) $(LFLAGS)

.PHONY: test clean

test: $(OBJC)
	./$(OBJC)

clean: $(OBJC)
	rm -rf $(OBJC)
