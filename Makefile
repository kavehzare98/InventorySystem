.PHONY: all clean build_version

COMPILER         := g++
COMPILER_VERSION := -std=c++23
EXEC             := main
BUILD_DIR        := ./executables
SRC_DIR          := ./src
	
all:
	$(COMPILER) $(COMPILER_VERSION) $(SRC_DIR)/$(SRC_FILES) -o $(EXEC) 

clean:
	rm $(EXEC)
