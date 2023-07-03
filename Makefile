# Compiler
CC = g++

SRC_DIR=src
HDR_DIR=headers
OBJ_DIR=objects
BUILD_DIR=build

OBJECTS := ZombieArena.o CreateBackground.o Player.o

.PHONY: clean

# Compiler Flags
CFLAGS = -Wall -pedantic

# Library Flags
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Output name
CCOUT=ZombieArena

# Compiled Object Files
COBJ = *.o

#$(OBJ_DIR)/*.o
$(CCOUT): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o -o $(BUILD_DIR)/$(CCOUT) $(LFLAGS)

ZombieArena.o: $(SRC_DIR)/ZombieArena.cpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $(SRC_DIR)/ZombieArena.cpp -o $(OBJ_DIR)/ZombieArena.o

CreateBackground.o: $(SRC_DIR)/CreateBackground.cpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $(SRC_DIR)/CreateBackground.cpp -o $(OBJ_DIR)/CreateBackground.o

Player.o: $(SRC_DIR)/Player.cpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $(SRC_DIR)/Player.cpp -o $(OBJ_DIR)/Player.o

clean:
	rm -rf $(BUILD_DIR)/$(CCOUT); rm -rf $(OBJ_DIR)/*.o
