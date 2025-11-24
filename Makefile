.PHONY: all clean 

COMPILER         := g++
COMPILER_VERSION := -std=c++23
EXEC             := main
SRC_DIR          := src
INC_DIR	         := include

SRC_FILES 	 := $(wildcard $(SRC_DIR)/*.cpp)
	
all:
	$(COMPILER) $(COMPILER_VERSION) -I./$(INC_DIR) $(SRC_FILES) -o $(EXEC) 

clean:
	rm $(EXEC)
