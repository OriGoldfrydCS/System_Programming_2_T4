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
    Tree<int, 2> binaryTree;
    Node<int, 2>* n1 = new Node<int, 2>(1);
    Node<int, 2>* n2 = new Node<int, 2>(2);
    Node<int, 2>* n3 = new Node<int, 2>(3);
    Node<int, 2>* n4 = new Node<int, 2>(4);
    Node<int, 2>* n5 = new Node<int, 2>(5);

    binaryTree.add_root(n1);
    binaryTree.add_sub_node(n1, n2);
    binaryTree.add_sub_node(n1, n3);
    binaryTree.add_sub_node(n2, n4);
    binaryTree.add_sub_node(n2, n5);

    // Pre-order Traversal
    stringstream ss;
    for (auto node = binaryTree.begin_pre_order(); node != binaryTree.end_pre_order(); ++node) {
        ss << node->get_value() << ", ";
    }
    CHECK(ss.str() == "1, 2, 4, 5, 3, ");

    // In-order Traversal
    ss.str("");
    for (auto node = binaryTree.begin_in_order(); node != binaryTree.end_in_order(); ++node) {
        ss << node->get_value() << ", ";
    }
    CHECK(ss.str() == "4, 2, 5, 1, 3, ");

    // Post-order Traversal
    ss.str("");
    for (auto node = binaryTree.begin_post_order(); node != binaryTree.end_post_order(); ++node) {
        ss << node->get_value() << ", ";
    }
    CHECK(ss.str() == "4, 5, 2, 3, 1, ");
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
    for (auto node = trinaryTree.begin_bfs_scan(); node != trinaryTree.end_bfs_scan(); ++node) {
        ss << node->get_value() << ", ";
    }
    CHECK(ss.str() == "3.14, 2.71, 1.41, ");

    // DFS Traversal
    ss.str("");
    for (auto node = trinaryTree.begin_dfs_scan(); node != trinaryTree.end_dfs_scan(); ++node) {
        ss << node->get_value() << ", ";
    }
    CHECK(ss.str() == "3.14, 2.71, 1.41, ");

    // Heap Traversal
    ss.str("");
    for (auto node = trinaryTree.myHeap(); node != trinaryTree.end_heap(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.41 2.71 3.14 ");
}

TEST_CASE("String Tree Traversals") {
    Tree<string, 3> stringTree;
    Node<string, 3>* n1 = new Node<string, 3>("hello");
    Node<string, 3>* n2 = new Node<string, 3>("world");
    Node<string, 3>* n3 = new Node<string, 3>("cpp");

    stringTree.add_root(n1);
    stringTree.add_sub_node(n1, n2);
    stringTree.add_sub_node(n1, n3);

    // BFS Traversal
    stringstream ss;
    for (auto node = stringTree.begin_bfs_scan(); node != stringTree.end_bfs_scan(); ++node) {
        ss << node->get_value() << ", ";
    }
    CHECK(ss.str() == "hello, world, cpp, ");

    // DFS Traversal
    ss.str("");
    for (auto node = stringTree.begin_dfs_scan(); node != stringTree.end_dfs_scan(); ++node) {
        ss << node->get_value() << ", ";
    }
    CHECK(ss.str() == "hello, world, cpp, ");

    // Heap Traversal
    ss.str("");
    for (auto node = stringTree.myHeap(); node != stringTree.end_heap(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "cpp hello world ");
}

TEST_CASE("Complex Tree Traversals") {
    Tree<Complex, 2> complexTree;
    Node<Complex, 2>* n1 = new Node<Complex, 2>(Complex(1.0, 2.0));
    Node<Complex, 2>* n2 = new Node<Complex, 2>(Complex(3.0, 4.0));
    Node<Complex, 2>* n3 = new Node<Complex, 2>(Complex(5.0, 6.0));

    complexTree.add_root(n1);
    complexTree.add_sub_node(n1, n2);
    complexTree.add_sub_node(n1, n3);

    // BFS Traversal
    stringstream ss;
    for (auto node = complexTree.begin_bfs_scan(); node != complexTree.end_bfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1+2i 3+4i 5+6i ");

    // DFS Traversal
    ss.str("");
    for (auto node = complexTree.begin_dfs_scan(); node != complexTree.end_dfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1+2i 3+4i 5+6i ");

    // Heap Traversal
    ss.str("");
    for (auto node = complexTree.myHeap(); node != complexTree.end_heap(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1+2i 3+4i 5+6i ");
}

//--------------------------//
//    Complicated tests     //
//--------------------------//

#include "doctest.h"
#include "tree.hpp"
#include "node.hpp"
#include "complex.hpp"
#include <sstream>

using namespace ori;
using namespace std;

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
    for (auto node = intTree.begin_bfs_scan(); node != intTree.end_bfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 20 39 42 53 64 77 89 91 ");

    // DFS Traversal
    ss.str("");
    for (auto node = intTree.begin_dfs_scan(); node != intTree.end_dfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 20 89 39 91 42 53 64 77 ");

    // Heap Traversal
    ss.str("");
    for (auto node = intTree.myHeap(); node != intTree.end_heap(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1 20 39 42 53 64 77 89 91 ");
}

TEST_CASE("Complex Double Tree Traversals - 5-ary") {
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
    for (auto node = doubleTree.begin_bfs_scan(); node != doubleTree.end_bfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.123 2.456 3.789 4.012 5.345 6.678 7.901 8.234 9.567 10.891 ");

    // DFS Traversal
    ss.str("");
    for (auto node = doubleTree.begin_dfs_scan(); node != doubleTree.end_dfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.123 2.456 7.901 3.789 8.234 4.012 9.567 5.345 10.891 6.678 ");

    // Heap Traversal
    ss.str("");
    for (auto node = doubleTree.myHeap(); node != doubleTree.end_heap(); ++node) {
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
    for (auto node = stringTree.begin_bfs_scan(); node != stringTree.end_bfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "root alpha beta gamma delta epsilon zeta eta theta ");

    // DFS Traversal
    ss.str("");
    for (auto node = stringTree.begin_dfs_scan(); node != stringTree.end_dfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "root alpha epsilon beta zeta gamma eta delta theta ");

    // Heap Traversal
    ss.str("");
    for (auto node = stringTree.myHeap(); node != stringTree.end_heap(); ++node) {
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
    for (auto node = complexTree.begin_bfs_scan(); node != complexTree.end_bfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.1+2.2i 3.3+4.4i 5.5+6.6i 7.7+8.8i 9.9+11.11i 11.11+12.12i 13.13+14.14i 15.15+16.16i 17.17+18.18i 19.19+21.21i ");

    // DFS Traversal
    ss.str("");
    for (auto node = complexTree.begin_dfs_scan(); node != complexTree.end_dfs_scan(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.1+2.2i 3.3+4.4i 13.13+14.14i 5.5+6.6i 15.15+16.16i 7.7+8.8i 17.17+18.18i 9.9+11.11i 19.19+21.21i 11.11+12.12i ");

    // Heap Traversal
    ss.str("");
    for (auto node = complexTree.myHeap(); node != complexTree.end_heap(); ++node) {
        ss << node->get_value() << " ";
    }
    CHECK(ss.str() == "1.1+2.2i 3.3+4.4i 5.5+6.6i 7.7+8.8i 9.9+11.11i 11.11+12.12i 13.13+14.14i 15.15+16.16i 17.17+18.18i 19.19+21.21i ");
}

