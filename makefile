# Email: origoldbsc@gmail.com
# To run the main program, type after 'make': ./main
# To run the demo program, type after 'make demo': ./demo
# To run the test program, type after 'make test': ./test

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wsign-conversion -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL -lglfw -ldl

# Include directories for SFML and 
INCLUDE_DIRS = -I/path/to/sfml/include

HEADER_FILES = complex.hpp node.hpp tree.hpp pre_order_iterator.hpp post_order_iterator.hpp in_order_iterator.hpp bfs_iterator.hpp dfs_iterator.hpp heap_iterator.hpp
EXECUTABLES = main demo test

# Valgrind settings
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

all: $(EXECUTABLES)

main: main.cpp complex.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o main main.cpp complex.cpp $(LDFLAGS)

demo: demo.cpp complex.cpp $(HEADER_FILES) 
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o demo demo.cpp complex.cpp $(LDFLAGS)

test: test.cpp test_counter.cpp complex.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o test test.cpp test_counter.cpp complex.cpp $(LDFLAGS)

# Run Valgrind
valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -rf $(EXECUTABLES)

.PHONY: all clean
