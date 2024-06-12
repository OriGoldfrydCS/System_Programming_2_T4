CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra
SRC_FILES := main.cpp demo.cpp test.cpp test_counter.cpp
HEADER_FILES := complex.hpp node.hpp tree.hpp
EXECUTABLES := main demo test

all: $(EXECUTABLES)

main: main.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -o main main.cpp

demo: demo.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -o demo demo.cpp

test: test.cpp test_counter.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -o test test.cpp test_counter.cpp

clean:
	rm -rf tree $(EXECUTABLES)

.PHONY: all clean
