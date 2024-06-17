// Email: origoldbsc@gmail.com

#include "doctest.h"
#include "tree.hpp"
#include "node.hpp"
#include "complex.hpp"
#include <sstream>

using namespace ori;
using namespace std;

//--------------------------//
// Simple and initial tests //
//--------------------------//

TEST_CASE("Binary Tree Traversals") {
    Tree<int> binaryTree;
    Node<int>* n1 = new Node<int>(1);
    Node<int>* n2 = new Node<int>(2);
    Node<int>* n3 = new Node<int>(3);
    Node<int>* n4 = new Node<int>(4);
    Node<int>* n5 = new Node<int>(5);

    binaryTree.add_root(n1);
    binaryTree.add_sub_node(n1, n2);
    binaryTree.add_sub_node(n1, n3);
    binaryTree.add_sub_node(n2, n4);
    binaryTree.add_sub_node(n2, n5);

    // Pre-order Traversal
    stringstream ss;
    for (auto node = binaryTree.begin_pre_order(); node != binaryTree.end_pre_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 2 4 5 3 ");

    // In-order Traversal
    ss.str("");
    for (auto node = binaryTree.begin_in_order(); node != binaryTree.end_in_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "4 2 5 1 3 ");

    // Post-order Traversal
    ss.str("");
    for (auto node = binaryTree.begin_post_order(); node != binaryTree.end_post_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "4 5 2 3 1 ");
}

TEST_CASE("Trinary Tree Traversals") {
    Tree<double, 3> trinaryTree;
    Node<double, 3>* n1 = new Node<double, 3>(3.14);
    Node<double, 3>* n2 = new Node<double, 3>(2.71);
    Node<double, 3>* n3 = new Node<double, 3>(1.41);

    trinaryTree.add_root(n1);
    trinaryTree.add_sub_node(n1, n2);
    trinaryTree.add_sub_node(n1, n3);

    // BFS Traversal
    stringstream ss;
    for (auto node = trinaryTree.begin_bfs_scan(); node != trinaryTree.end_bfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "3.14 2.71 1.41 ");

    // DFS Traversal
    ss.str("");
    for (auto node = trinaryTree.begin_dfs_scan(); node != trinaryTree.end_dfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "3.14 2.71 1.41 ");

    // Heap Traversal
    ss.str("");
    for (auto node = trinaryTree.myHeap(); node != trinaryTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.41 2.71 3.14 ");
}

TEST_CASE("String Tree Traversals") {
    Tree<string, 3> stringTree;
    Node<string, 3>* n1 = new Node<string, 3>("AAA");
    Node<string, 3>* n2 = new Node<string, 3>("BBB");
    Node<string, 3>* n3 = new Node<string, 3>("CCC");

    stringTree.add_root(n1);
    stringTree.add_sub_node(n1, n2);
    stringTree.add_sub_node(n1, n3);

    // BFS Traversal
    stringstream ss;
    for (auto node = stringTree.begin_bfs_scan(); node != stringTree.end_bfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "AAA BBB CCC ");

    // DFS Traversal
    ss.str("");
    for (auto node = stringTree.begin_dfs_scan(); node != stringTree.end_dfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "AAA BBB CCC ");

    // Heap Traversal
    ss.str("");
    for (auto node = stringTree.myHeap(); node != stringTree.end_heap(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "AAA BBB CCC ");
}

TEST_CASE("Complex Tree Traversals") {
    Tree<Complex> complexTree;
    Node<Complex>* n1 = new Node<Complex>(Complex(1.0, 2.0));
    Node<Complex>* n2 = new Node<Complex>(Complex(3.0, 4.0));
    Node<Complex>* n3 = new Node<Complex>(Complex(5.0, 6.0));

    complexTree.add_root(n1);
    complexTree.add_sub_node(n1, n2);
    complexTree.add_sub_node(n1, n3);

    // BFS Traversal
    stringstream ss;
    for (auto node = complexTree.begin_bfs_scan(); node != complexTree.end_bfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1+2i 3+4i 5+6i ");

    // DFS Traversal
    ss.str("");
    for (auto node = complexTree.begin_dfs_scan(); node != complexTree.end_dfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1+2i 3+4i 5+6i ");

    // Heap Traversal
    ss.str("");
    for (auto node = complexTree.myHeap(); node != complexTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1+2i 3+4i 5+6i ");
}

//--------------------------//
//    Complicated tests     //
//--------------------------//


TEST_CASE("Complex Int Tree Traversals - 6-ary") {
    Tree<int, 6> intTree;
    Node<int, 6>* n1 = new Node<int, 6>(1);
    Node<int, 6>* n2 = new Node<int, 6>(20);
    Node<int, 6>* n3 = new Node<int, 6>(39);
    Node<int, 6>* n4 = new Node<int, 6>(42);
    Node<int, 6>* n5 = new Node<int, 6>(53);
    Node<int, 6>* n6 = new Node<int, 6>(64);
    Node<int, 6>* n7 = new Node<int, 6>(77);
    Node<int, 6>* n8 = new Node<int, 6>(89);
    Node<int, 6>* n9 = new Node<int, 6>(91);

    intTree.add_root(n1);
    intTree.add_sub_node(n1, n2);
    intTree.add_sub_node(n1, n3);
    intTree.add_sub_node(n1, n4);
    intTree.add_sub_node(n1, n5);
    intTree.add_sub_node(n1, n6);
    intTree.add_sub_node(n1, n7);
    intTree.add_sub_node(n2, n8);
    intTree.add_sub_node(n3, n9);

    // BFS Traversal
    stringstream ss;
    for (auto node = intTree.begin_bfs_scan(); node != intTree.end_bfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 20 39 42 53 64 77 89 91 ");

    // DFS Traversal
    ss.str("");
    for (auto node = intTree.begin_dfs_scan(); node != intTree.end_dfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 20 89 39 91 42 53 64 77 ");

    // Heap Traversal
    ss.str("");
    for (auto node = intTree.myHeap(); node != intTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 20 39 42 53 64 77 89 91 ");
}

TEST_CASE("Complex Double Tree Traversals - 5-ary") 
{
    Tree<double, 5> doubleTree;
    Node<double, 5>* n1 = new Node<double, 5>(1.123);
    Node<double, 5>* n2 = new Node<double, 5>(2.456);
    Node<double, 5>* n3 = new Node<double, 5>(3.789);
    Node<double, 5>* n4 = new Node<double, 5>(4.012);
    Node<double, 5>* n5 = new Node<double, 5>(5.345);
    Node<double, 5>* n6 = new Node<double, 5>(6.678);
    Node<double, 5>* n7 = new Node<double, 5>(7.901);
    Node<double, 5>* n8 = new Node<double, 5>(8.234);
    Node<double, 5>* n9 = new Node<double, 5>(9.567);
    Node<double, 5>* n10 = new Node<double, 5>(10.891);

    doubleTree.add_root(n1);
    doubleTree.add_sub_node(n1, n2);
    doubleTree.add_sub_node(n1, n3);
    doubleTree.add_sub_node(n1, n4);
    doubleTree.add_sub_node(n1, n5);
    doubleTree.add_sub_node(n1, n6);
    doubleTree.add_sub_node(n2, n7);
    doubleTree.add_sub_node(n3, n8);
    doubleTree.add_sub_node(n4, n9);
    doubleTree.add_sub_node(n5, n10);

    // BFS Traversal
    stringstream ss;
    for (auto node = doubleTree.begin_bfs_scan(); node != doubleTree.end_bfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.123 2.456 3.789 4.012 5.345 6.678 7.901 8.234 9.567 10.891 ");

    // DFS Traversal
    ss.str("");
    for (auto node = doubleTree.begin_dfs_scan(); node != doubleTree.end_dfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.123 2.456 7.901 3.789 8.234 4.012 9.567 5.345 10.891 6.678 ");

    // Heap Traversal
    ss.str("");
    for (auto node = doubleTree.myHeap(); node != doubleTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.123 2.456 3.789 4.012 5.345 6.678 7.901 8.234 9.567 10.891 ");
}

TEST_CASE("Complex String Tree Traversals - 4-ary") {
    Tree<string, 4> stringTree;
    Node<string, 4>* n1 = new Node<string, 4>("root");
    Node<string, 4>* n2 = new Node<string, 4>("alpha");
    Node<string, 4>* n3 = new Node<string, 4>("beta");
    Node<string, 4>* n4 = new Node<string, 4>("gamma");
    Node<string, 4>* n5 = new Node<string, 4>("delta");
    Node<string, 4>* n6 = new Node<string, 4>("epsilon");
    Node<string, 4>* n7 = new Node<string, 4>("zeta");
    Node<string, 4>* n8 = new Node<string, 4>("eta");
    Node<string, 4>* n9 = new Node<string, 4>("theta");

    stringTree.add_root(n1);
    stringTree.add_sub_node(n1, n2);
    stringTree.add_sub_node(n1, n3);
    stringTree.add_sub_node(n1, n4);
    stringTree.add_sub_node(n1, n5);
    stringTree.add_sub_node(n2, n6);
    stringTree.add_sub_node(n3, n7);
    stringTree.add_sub_node(n4, n8);
    stringTree.add_sub_node(n5, n9);

    // BFS Traversal
    stringstream ss;
    for (auto node = stringTree.begin_bfs_scan(); node != stringTree.end_bfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "root alpha beta gamma delta epsilon zeta eta theta ");

    // DFS Traversal
    ss.str("");
    for (auto node = stringTree.begin_dfs_scan(); node != stringTree.end_dfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "root alpha epsilon beta zeta gamma eta delta theta ");

    // Heap Traversal
    ss.str("");
    for (auto node = stringTree.myHeap(); node != stringTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "alpha beta delta epsilon eta gamma root theta zeta ");
}

TEST_CASE("Complex Number Tree Traversals - 5-ary") {
    Tree<Complex, 5> complexTree;
    Node<Complex, 5>* n1 = new Node<Complex, 5>(Complex(1.1, 2.2));
    Node<Complex, 5>* n2 = new Node<Complex, 5>(Complex(3.3, 4.4));
    Node<Complex, 5>* n3 = new Node<Complex, 5>(Complex(5.5, 6.6));
    Node<Complex, 5>* n4 = new Node<Complex, 5>(Complex(7.7, 8.8));
    Node<Complex, 5>* n5 = new Node<Complex, 5>(Complex(9.9, 11.11));
    Node<Complex, 5>* n6 = new Node<Complex, 5>(Complex(11.11, 12.12));
    Node<Complex, 5>* n7 = new Node<Complex, 5>(Complex(13.13, 14.14));
    Node<Complex, 5>* n8 = new Node<Complex, 5>(Complex(15.15, 16.16));
    Node<Complex, 5>* n9 = new Node<Complex, 5>(Complex(17.17, 18.18));
    Node<Complex, 5>* n10 = new Node<Complex, 5>(Complex(19.19, 21.21));

    complexTree.add_root(n1);
    complexTree.add_sub_node(n1, n2);
    complexTree.add_sub_node(n1, n3);
    complexTree.add_sub_node(n1, n4);
    complexTree.add_sub_node(n1, n5);
    complexTree.add_sub_node(n1, n6);
    complexTree.add_sub_node(n2, n7);
    complexTree.add_sub_node(n3, n8);
    complexTree.add_sub_node(n4, n9);
    complexTree.add_sub_node(n5, n10);

    // BFS Traversal
    stringstream ss;
    for (auto node = complexTree.begin_bfs_scan(); node != complexTree.end_bfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.1+2.2i 3.3+4.4i 5.5+6.6i 7.7+8.8i 9.9+11.11i 11.11+12.12i 13.13+14.14i 15.15+16.16i 17.17+18.18i 19.19+21.21i ");

    // DFS Traversal
    ss.str("");
    for (auto node = complexTree.begin_dfs_scan(); node != complexTree.end_dfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.1+2.2i 3.3+4.4i 13.13+14.14i 5.5+6.6i 15.15+16.16i 7.7+8.8i 17.17+18.18i 9.9+11.11i 19.19+21.21i 11.11+12.12i ");

    // Heap Traversal
    ss.str("");
    for (auto node = complexTree.myHeap(); node != complexTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.1+2.2i 3.3+4.4i 5.5+6.6i 7.7+8.8i 9.9+11.11i 11.11+12.12i 13.13+14.14i 15.15+16.16i 17.17+18.18i 19.19+21.21i ");
}

TEST_CASE("Complex tree for HeapIterator") {

    Tree<double, 1> complexTree;

    Node<double, 1>* n1 = new Node<double, 1>(5.3);
    Node<double, 1>* n2 = new Node<double, 1>(3.1);
    Node<double, 1>* n3 = new Node<double, 1>(8.7);
    Node<double, 1>* n4 = new Node<double, 1>(2.2);
    Node<double, 1>* n5 = new Node<double, 1>(9.6);
    Node<double, 1>* n6 = new Node<double, 1>(4.4);
    Node<double, 1>* n7 = new Node<double, 1>(7.7);
    Node<double, 1>* n8 = new Node<double, 1>(0.5);
    Node<double, 1>* n9 = new Node<double, 1>(1.3);
    Node<double, 1>* n10 = new Node<double, 1>(6.9);
    Node<double, 1>* n11 = new Node<double, 1>(10.2);
    Node<double, 1>* n12 = new Node<double, 1>(4.8);
    Node<double, 1>* n13 = new Node<double, 1>(8.4);
    Node<double, 1>* n14 = new Node<double, 1>(2.7);
    Node<double, 1>* n15 = new Node<double, 1>(6.1);
    Node<double, 1>* n16 = new Node<double, 1>(3.9);
    Node<double, 1>* n17 = new Node<double, 1>(9.8);
    Node<double, 1>* n18 = new Node<double, 1>(2.5);
    Node<double, 1>* n19 = new Node<double, 1>(8.1);
    Node<double, 1>* n20 = new Node<double, 1>(4.6);

    // Setting up the tree with one child per node
    complexTree.add_root(n1);
    complexTree.add_sub_node(n1, n2);
    complexTree.add_sub_node(n2, n3);
    complexTree.add_sub_node(n3, n4);
    complexTree.add_sub_node(n4, n5);
    complexTree.add_sub_node(n5, n6);
    complexTree.add_sub_node(n6, n7);
    complexTree.add_sub_node(n7, n8);
    complexTree.add_sub_node(n8, n9);
    complexTree.add_sub_node(n9, n10);
    complexTree.add_sub_node(n10, n11);
    complexTree.add_sub_node(n11, n12);
    complexTree.add_sub_node(n12, n13);
    complexTree.add_sub_node(n13, n14);
    complexTree.add_sub_node(n14, n15);
    complexTree.add_sub_node(n15, n16);
    complexTree.add_sub_node(n16, n17);
    complexTree.add_sub_node(n17, n18);
    complexTree.add_sub_node(n18, n19);
    complexTree.add_sub_node(n19, n20);

    std::stringstream ss;

    for (auto node = complexTree.myHeap(); node != complexTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }

    CHECK(ss.str() == "0.5 1.3 2.2 2.5 2.7 3.1 3.9 4.4 4.6 4.8 5.3 6.1 6.9 7.7 8.1 8.4 8.7 9.6 9.8 10.2 ");
}


TEST_CASE("HeapIterator iterates through a tree with 100 nodes in reverse order (the largest element inserted to the root)") {
    
    Tree<double, 1> complexTree;

    double startValue = 200;        // Start at the highest value

    // Create nodes and adding them to the tree in descending order
    Node<double, 1>* previous = new Node<double, 1>(startValue);
    complexTree.add_root(previous);

    for (int i = 1; i < 100; i++) 
    {
        double nodeValue = startValue - i;
        Node<double, 1>* newNode = new Node<double, 1>(nodeValue);
        complexTree.add_sub_node(previous, newNode);        // Each node is a child of the previous node
        previous = newNode;
    }

    // Using stringstream to capture the output
    std::stringstream ss;
    ss << std::fixed << std::setprecision(6);  // Match precision to expected output

    // Heap Traversal using provided iterator methods
    for (auto node = complexTree.myHeap(); node != complexTree.end_heap(); ++node) {
        ss << node->get_value() << " ";
    }

    // Construct the expected string for a max-heap
    std::string expected = "";
    for (int i = 99; i >= 0; --i) {
        expected += std::to_string(startValue - i) + " ";
    }

    // Check the heap order
    CHECK(ss.str() == expected);
}

TEST_CASE("Single Node Tree") {
    Tree<int> singleNodeTree;
    Node<int>* n1 = new Node<int>(1);
    singleNodeTree.add_root(n1);

    // Pre-order Traversal
    stringstream ss;
    for (auto node = singleNodeTree.begin_pre_order(); node != singleNodeTree.end_pre_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 ");

    // In-order Traversal
    ss.str("");
    for (auto node = singleNodeTree.begin_in_order(); node != singleNodeTree.end_in_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 ");

    // Post-order Traversal
    ss.str("");
    for (auto node = singleNodeTree.begin_post_order(); node != singleNodeTree.end_post_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 ");

    // Heap Traversal
    ss.str("");
    for (auto node = singleNodeTree.myHeap(); node != singleNodeTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 ");
}


TEST_CASE("Tree with Null Values") {
    Tree<int*> nullValueTree;
    Node<int*>* n1 = new Node<int*>(nullptr);
    Node<int*>* n2 = new Node<int*>(nullptr);
    Node<int*>* n3 = new Node<int*>(nullptr);

    nullValueTree.add_root(n1);
    nullValueTree.add_sub_node(n1, n2);
    nullValueTree.add_sub_node(n1, n3);

    // Pre-order Traversal
    stringstream ss;
    for (auto node = nullValueTree.begin_pre_order(); node != nullValueTree.end_pre_order(); ++node) 
    {
        ss << (node->get_value() == nullptr ? "nullptr" : "value") << " ";
    }
    CHECK(ss.str() == "nullptr nullptr nullptr ");

    // In-order Traversal
    ss.str("");
    for (auto node = nullValueTree.begin_in_order(); node != nullValueTree.end_in_order(); ++node) 
    {
        ss << (node->get_value() == nullptr ? "nullptr" : "value") << " ";
    }
    CHECK(ss.str() == "nullptr nullptr nullptr ");

    // Post-order Traversal
    ss.str("");
    for (auto node = nullValueTree.begin_post_order(); node != nullValueTree.end_post_order(); ++node) 
    {
        ss << (node->get_value() == nullptr ? "nullptr" : "value") << " ";
    }
    CHECK(ss.str() == "nullptr nullptr nullptr ");

    // Heap Traversal
    ss.str("");
    for (auto node = nullValueTree.myHeap(); node != nullValueTree.end_heap(); ++node) 
    {
        ss << (node->get_value() == nullptr ? "nullptr" : "value") << " ";
    }
    CHECK(ss.str() == "nullptr nullptr nullptr ");
}


TEST_CASE("Empty Tree") {
    Tree<int> emptyTree;

    // Pre-order Traversal
    stringstream ss;
    for (auto node = emptyTree.begin_pre_order(); node != emptyTree.end_pre_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "");

    // In-order Traversal
    ss.str("");
    for (auto node = emptyTree.begin_in_order(); node != emptyTree.end_in_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "");

    // Post-order Traversal
    ss.str("");
    for (auto node = emptyTree.begin_post_order(); node != emptyTree.end_post_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "");

    // Heap Traversal
    ss.str("");
    for (auto node = emptyTree.myHeap(); node != emptyTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "");
}

TEST_CASE("Only Left Children") {
    Tree<int> leftChildrenTree;
    Node<int>* n1 = new Node<int>(1);
    Node<int>* n2 = new Node<int>(2);
    Node<int>* n3 = new Node<int>(3);
    Node<int>* n4 = new Node<int>(4);

    leftChildrenTree.add_root(n1);
    leftChildrenTree.add_sub_node(n1, n2);
    leftChildrenTree.add_sub_node(n2, n3);
    leftChildrenTree.add_sub_node(n3, n4);

    // Pre-order Traversal
    stringstream ss;
    for (auto node = leftChildrenTree.begin_pre_order(); node != leftChildrenTree.end_pre_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 2 3 4 ");

    // In-order Traversal
    ss.str("");
    for (auto node = leftChildrenTree.begin_in_order(); node != leftChildrenTree.end_in_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "4 3 2 1 ");

    // Post-order Traversal
    ss.str("");
    for (auto node = leftChildrenTree.begin_post_order(); node != leftChildrenTree.end_post_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "4 3 2 1 ");

    // BFS Traversal
    ss.str("");
    for (auto node = leftChildrenTree.begin_bfs_scan(); node != leftChildrenTree.end_bfs_scan(); ++node)
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 2 3 4 ");

    // DFS Traversal
    ss.str("");
    for (auto node = leftChildrenTree.begin_dfs_scan(); node != leftChildrenTree.end_dfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 2 3 4 ");

    // Heap Traversal
    ss.str("");
    for (auto node = leftChildrenTree.myHeap(); node != leftChildrenTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 2 3 4 ");
}


TEST_CASE("Edge Case: Only Right Children") {
    Tree<int> rightChildrenTree;
    Node<int>* n1 = new Node<int>(1);
    Node<int>* n2 = new Node<int>(2);
    Node<int>* n3 = new Node<int>(3);
    Node<int>* n4 = new Node<int>(4);

    rightChildrenTree.add_root(n1);
    rightChildrenTree.add_sub_node(n1, n2);
    rightChildrenTree.add_sub_node(n1, n3); // Adding the right child to n1
    rightChildrenTree.add_sub_node(n2, n4);

    // Pre-order Traversal
    stringstream ss;
    for (auto node = rightChildrenTree.begin_pre_order(); node != rightChildrenTree.end_pre_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 2 4 3 ");

    // In-order Traversal
    ss.str("");
    for (auto node = rightChildrenTree.begin_in_order(); node != rightChildrenTree.end_in_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "4 2 1 3 ");

    // Post-order Traversal
    ss.str("");
    for (auto node = rightChildrenTree.begin_post_order(); node != rightChildrenTree.end_post_order(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "4 2 3 1 ");

    // BFS Traversal
    ss.str("");
    for (auto node = rightChildrenTree.begin_bfs_scan(); node != rightChildrenTree.end_bfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 2 3 4 ");

    // DFS Traversal
    ss.str("");
    for (auto node = rightChildrenTree.begin_dfs_scan(); node != rightChildrenTree.end_dfs_scan(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 2 4 3 ");

    // Heap Traversal
    ss.str("");
    for (auto node = rightChildrenTree.myHeap(); node != rightChildrenTree.end_heap(); ++node) 
    {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 2 3 4 ");
}
