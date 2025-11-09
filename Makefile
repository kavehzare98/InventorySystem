.PHONY: all clean build_version

DATE             := $(shell date +"%Y-%m-%d_%H-%M-%S")
COMPILER         := g++
COMPILER_VERSION := -std=c++23
SRC_FILES        := main.cpp
EXEC             := main
BUILD_DIR        := ./executables
SRC_DIR          := ./src
	
build_version:
	$(COMPILER) $(COMPILER_VERSION) $(SRC_DIR)/$(SRC_FILES) -o\
          $(BUILD_DIR)/$(EXEC)_$(DATE)
all:
	$(COMPILER) $(COMPILER_VERSION) $(SRC_DIR)/$(SRC_FILES) -o $(EXEC) 

clean:
	rm $(EXEC)
