CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

SRC_FILES := main.cpp
HEADER_FILES := tree.hpp

EXECUTABLE := tree

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES) $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SRC_FILES)

clean:
	rm -rf $(EXECUTABLE)

.PHONY: all clean