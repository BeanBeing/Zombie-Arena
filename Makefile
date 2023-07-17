# Compiler
CC = g++

SRC_DIR=src
HDR_DIR=headers
OBJ_DIR=objects
BUILD_DIR=build

OBJECTS= ZombieArena.o CreateBackground.o Player.o

.PHONY: test clean make_object_dir make_build_dir

# Compiler Flags
CFLAGS = -Wall -pedantic

# Library Flags
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Output name
CCOUT= ZombieArena

app: make_build_dir make_object_dir $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o -o $(BUILD_DIR)/$(CCOUT) $(LFLAGS)

make_build_dir:
	mkdir -p $(BUILD_DIR)

make_object_dir:
	mkdir -p $(OBJ_DIR)/

ZombieArena.o: $(SRC_DIR)/ZombieArena.cpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $(SRC_DIR)/ZombieArena.cpp -o $(OBJ_DIR)/ZombieArena.o

CreateBackground.o: $(SRC_DIR)/CreateBackground.cpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $(SRC_DIR)/CreateBackground.cpp -o $(OBJ_DIR)/CreateBackground.o

Player.o: $(SRC_DIR)/Player.cpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $(SRC_DIR)/Player.cpp -o $(OBJ_DIR)/Player.o

test:
	cd $(BUILD_DIR); ./$(CCOUT)

clean:
	rm -rf $(BUILD_DIR); rm -rf $(OBJ_DIR)
