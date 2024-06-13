CXX := g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wsign-conversion -g
SRC_FILES := main.cpp demo.cpp test.cpp test_counter.cpp
HEADER_FILES := complex.hpp node.hpp tree.hpp
EXECUTABLES := main demo test

# Valgrind settings
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

all: $(EXECUTABLES)

main: main.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -o main main.cpp

demo: demo.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -o demo demo.cpp

test: test.cpp test_counter.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -o test test.cpp test_counter.cpp

# Run Valgrind
valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./Catan 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -rf tree $(EXECUTABLES)

.PHONY: all clean
