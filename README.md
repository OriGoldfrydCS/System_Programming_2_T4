# Generic K-ary Tree Implementation with Visualization

## Overview
This project provides a generic implementation of a K-ary tree data structure.

The tree supports various traversal methods, including Breadth-First Search (BFS), Depth-First Search (DFS), In-order, Pre-order, and Post-order traversals. Additionally, the tree can be traversed as a min-heap.
The project also includes a visualization component that uses the SFML (Simple and Fast Multimedia Library) to display the tree in a graphical window. 

## Classes
### Node Class

This class represents a node in the K-ary tree.
It stores the value of the node and a vector of pointers to its child nodes.
The class provides methods to retrieve the node's value and access its child nodes.

### Tree Class

This is the main class that represents the K-ary tree data structure.
It provides methods to add a root node, add child nodes to a parent node, and perform various traversal operations (BFS, DFS, In-order, Pre-order, Post-order, and Heap).
The class also includes an overloaded << operator that allows for the visualization of the tree using SFML.
The destroyTree() method is responsible for recursively destroying the tree and freeing the memory occupied by the nodes.

### Iterator Classes

PreOrderIterator, PostOrderIterator, InOrderIterator, BFSIterator, DFSIterator, and HeapIterator are classes that provide iterators for traversing the tree in different ways.
Each iterator class follows the specified traversal order and provides the necessary functionality to make the iterator functional.

### Complex Class

This class represents a complex number with real and imaginary parts.
It provides various operators for comparing, adding, and converting complex numbers to strings.

## Usage

To use this project, you can build your own tree in the `main.cpp` file. The project supports primitive data types (like int, double), std::string, and the Complex class.
