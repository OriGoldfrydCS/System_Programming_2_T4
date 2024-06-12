#include <iostream>
#include <string>
#include "tree.hpp"
#include "node.hpp"
#include "complex.hpp"

int main() {
    // Binary Tree with more nodes (int)
    ori::Tree<int, 2> binaryTree;
    ori::Node<int, 2>* n1 = new ori::Node<int, 2>(1);
    ori::Node<int, 2>* n2 = new ori::Node<int, 2>(2);
    ori::Node<int, 2>* n3 = new ori::Node<int, 2>(3);
    ori::Node<int, 2>* n4 = new ori::Node<int, 2>(4);
    ori::Node<int, 2>* n5 = new ori::Node<int, 2>(5);
    ori::Node<int, 2>* n6 = new ori::Node<int, 2>(6);
    ori::Node<int, 2>* n7 = new ori::Node<int, 2>(7);
    ori::Node<int, 2>* n8 = new ori::Node<int, 2>(8);
    ori::Node<int, 2>* n9 = new ori::Node<int, 2>(9);
    ori::Node<int, 2>* n10 = new ori::Node<int, 2>(10);

    binaryTree.add_root(n1);
    binaryTree.add_sub_node(n1, n2);
    binaryTree.add_sub_node(n1, n3);
    binaryTree.add_sub_node(n2, n4);
    binaryTree.add_sub_node(n2, n5);
    binaryTree.add_sub_node(n3, n6);
    binaryTree.add_sub_node(n3, n7);
    binaryTree.add_sub_node(n4, n8);
    binaryTree.add_sub_node(n4, n9);
    binaryTree.add_sub_node(n5, n10);

    std::cout << "Binary Tree (int):" << std::endl;
    std::cout << binaryTree << std::endl;

    // Pre-order traversal: 1, 2, 4, 8, 9, 5, 10, 3, 6, 7
    std::cout << "Pre-order traversal:" << std::endl;
    for (auto node = binaryTree.begin_pre_order(); node != binaryTree.end_pre_order(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // In-order traversal: 8, 4, 9, 2, 10, 5, 1, 6, 3, 7
    std::cout << "In-order traversal:" << std::endl;
    for (auto node = binaryTree.begin_in_order(); node != binaryTree.end_in_order(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // Post-order traversal: 8, 9, 4, 10, 5, 2, 6, 7, 3, 1
    std::cout << "Post-order traversal:" << std::endl;
    for (auto node = binaryTree.begin_post_order(); node != binaryTree.end_post_order(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // BFS traversal: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    std::cout << "BFS traversal:" << std::endl;
    for (auto node = binaryTree.begin_bfs_scan(); node != binaryTree.end_bfs_scan(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // DFS traversal: 1, 2, 4, 8, 9, 5, 10, 3, 6, 7
    std::cout << "DFS traversal:" << std::endl;
    for (auto node = binaryTree.begin_dfs_scan(); node != binaryTree.end_dfs_scan(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // Heap traversal: 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    std::cout << "Heap traversal:" << std::endl;
    for (auto node = binaryTree.myHeap(); node != binaryTree.end_heap(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // Trinary Tree with more nodes (double)
    ori::Tree<double, 3> trinaryTree;
    ori::Node<double, 3>* n11 = new ori::Node<double, 3>(3.14);
    ori::Node<double, 3>* n12 = new ori::Node<double, 3>(2.71);
    ori::Node<double, 3>* n13 = new ori::Node<double, 3>(1.41);
    ori::Node<double, 3>* n14 = new ori::Node<double, 3>(4.2);
    ori::Node<double, 3>* n15 = new ori::Node<double, 3>(5.5);
    ori::Node<double, 3>* n16 = new ori::Node<double, 3>(6.6);
    ori::Node<double, 3>* n17 = new ori::Node<double, 3>(7.7);
    ori::Node<double, 3>* n18 = new ori::Node<double, 3>(8.8);
    ori::Node<double, 3>* n19 = new ori::Node<double, 3>(9.9);
    ori::Node<double, 3>* n20 = new ori::Node<double, 3>(10.0);

    trinaryTree.add_root(n11);
    trinaryTree.add_sub_node(n11, n12);
    trinaryTree.add_sub_node(n11, n13);
    trinaryTree.add_sub_node(n11, n14);
    trinaryTree.add_sub_node(n12, n15);
    trinaryTree.add_sub_node(n12, n16);
    trinaryTree.add_sub_node(n12, n17);
    trinaryTree.add_sub_node(n13, n18);
    trinaryTree.add_sub_node(n13, n19);
    trinaryTree.add_sub_node(n13, n20);

    std::cout << "Trinary Tree (double):" << std::endl;
    std::cout << trinaryTree << std::endl;

    // BFS traversal: 3.14, 2.71, 1.41, 4.2, 5.5, 6.6, 7.7, 8.8, 9.9, 10
    std::cout << "BFS traversal:" << std::endl;
    for (auto node = trinaryTree.begin_bfs_scan(); node != trinaryTree.end_bfs_scan(); ++node)
    {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    // DFS traversal: 3.14, 2.71, 5.5, 6.6, 7.7, 1.41, 8.8, 9.9, 10
    std::cout << "DFS traversal:" << std::endl;
    for (auto node = trinaryTree.begin_dfs_scan(); node != trinaryTree.end_dfs_scan(); ++node)
    {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    // Heap traversal: 10, 9.9, 8.8, 7.7, 6.6, 5.5, 4.2, 3.14, 2.71, 1.41
    std::cout << "Heap traversal:" << std::endl;
    for (auto node = trinaryTree.myHeap(); node != trinaryTree.end_heap(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // String Tree with more nodes
    ori::Tree<std::string, 3> stringTree;
    ori::Node<std::string, 3>* n21 = new ori::Node<std::string, 3>("hello");
    ori::Node<std::string, 3>* n22 = new ori::Node<std::string, 3>("world");
    ori::Node<std::string, 3>* n23 = new ori::Node<std::string, 3>("cpp");
    ori::Node<std::string, 3>* n24 = new ori::Node<std::string, 3>("tree");
    ori::Node<std::string, 3>* n25 = new ori::Node<std::string, 3>("data");
    ori::Node<std::string, 3>* n26 = new ori::Node<std::string, 3>("structure");
    ori::Node<std::string, 3>* n27 = new ori::Node<std::string, 3>("algorithm");
    ori::Node<std::string, 3>* n28 = new ori::Node<std::string, 3>("programming");
    ori::Node<std::string, 3>* n29 = new ori::Node<std::string, 3>("language");
    ori::Node<std::string, 3>* n30 = new ori::Node<std::string, 3>("computer");

    stringTree.add_root(n21);
    stringTree.add_sub_node(n21, n22);
    stringTree.add_sub_node(n21, n23);
    stringTree.add_sub_node(n21, n24);
    stringTree.add_sub_node(n22, n25);
    stringTree.add_sub_node(n22, n26);
    stringTree.add_sub_node(n22, n27);
    stringTree.add_sub_node(n23, n28);
    stringTree.add_sub_node(n23, n29);
    stringTree.add_sub_node(n23, n30);

    std::cout << "String Tree:" << std::endl;
    std::cout << stringTree << std::endl;

    // BFS traversal: hello, world, cpp, tree, data, structure, algorithm, programming, language, computer
    std::cout << "BFS traversal:" << std::endl;
    for (auto node = stringTree.begin_bfs_scan(); node != stringTree.end_bfs_scan(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // DFS traversal: hello, world, data, structure, algorithm, programming, language, computer, cpp, tree
    std::cout << "DFS traversal:" << std::endl;
    for (auto node = stringTree.begin_dfs_scan(); node != stringTree.end_dfs_scan(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // Heap traversal: world, tree, data, structure, algorithm, programming, language, computer, cpp, hello
    std::cout << "Heap traversal:" << std::endl;
    for (auto node = stringTree.myHeap(); node != stringTree.end_heap(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // Complex Tree with more nodes
    ori::Tree<Complex, 2> complexTree;
    ori::Node<Complex, 2>* n31 = new ori::Node<Complex, 2>(Complex(1.0, 2.0));
    ori::Node<Complex, 2>* n32 = new ori::Node<Complex, 2>(Complex(3.0, 4.0));
    ori::Node<Complex, 2>* n33 = new ori::Node<Complex, 2>(Complex(5.0, 6.0));
    ori::Node<Complex, 2>* n34 = new ori::Node<Complex, 2>(Complex(7.0, 8.0));
    ori::Node<Complex, 2>* n35 = new ori::Node<Complex, 2>(Complex(9.0, 10.0));
    ori::Node<Complex, 2>* n36 = new ori::Node<Complex, 2>(Complex(11.0, 12.0));
    ori::Node<Complex, 2>* n37 = new ori::Node<Complex, 2>(Complex(13.0, 14.0));
    ori::Node<Complex, 2>* n38 = new ori::Node<Complex, 2>(Complex(15.0, 16.0));
    ori::Node<Complex, 2>* n39 = new ori::Node<Complex, 2>(Complex(17.0, 18.0));
    ori::Node<Complex, 2>* n40 = new ori::Node<Complex, 2>(Complex(19.0, 20.0));

    complexTree.add_root(n31);
    complexTree.add_sub_node(n31, n32);
    complexTree.add_sub_node(n31, n33);
    complexTree.add_sub_node(n32, n34);
    complexTree.add_sub_node(n32, n35);
    complexTree.add_sub_node(n33, n36);
    complexTree.add_sub_node(n33, n37);
    complexTree.add_sub_node(n34, n38);
    complexTree.add_sub_node(n34, n39);
    complexTree.add_sub_node(n35, n40);

    std::cout << "Complex Tree:" << std::endl;
    std::cout << complexTree << std::endl;

    // BFS traversal: (1+2i), (3+4i), (5+6i), (7+8i), (9+10i), (11+12i), (13+14i), (15+16i), (17+18i), (19+20i)
    std::cout << "BFS traversal:" << std::endl;
    for (auto node = complexTree.begin_bfs_scan(); node != complexTree.end_bfs_scan(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // DFS traversal: (1+2i), (3+4i), (7+8i), (15+16i), (17+18i), (9+10i), (5+6i), (11+12i), (13+14i), (19+20i)
    std::cout << "DFS traversal:" << std::endl;
    for (auto node = complexTree.begin_dfs_scan(); node != complexTree.end_dfs_scan(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;

    // Heap traversal: (19+20i), (17+18i), (15+16i), (13+14i), (11+12i), (9+10i), (7+8i), (5+6i), (3+4i), (1+2i)
    std::cout << "Heap traversal:" << std::endl;
    for (auto node = complexTree.myHeap(); node != complexTree.end_heap(); ++node)
    {
        std::cout << node->get_value() << ", ";
    }
    std::cout << std::endl;
}