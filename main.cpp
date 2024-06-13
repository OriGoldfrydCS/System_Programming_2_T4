// Email: origoldbsc@gmail.com

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

    std::cout << "Binary Tree (int):" << std::endl;
    std::cout << binaryTree;


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

    std::cout << "Trinary Tree (double):" << std::endl;
    std::cout << trinaryTree << std::endl;


    // String Tree with more nodes
    ori::Tree<std::string, 3> stringTree;
    ori::Node<std::string, 3>* n21 = new ori::Node<std::string, 3>("AAA");
    ori::Node<std::string, 3>* n22 = new ori::Node<std::string, 3>("BBB");
    ori::Node<std::string, 3>* n23 = new ori::Node<std::string, 3>("CCC");
    ori::Node<std::string, 3>* n24 = new ori::Node<std::string, 3>("DDD");
    ori::Node<std::string, 3>* n25 = new ori::Node<std::string, 3>("EEE");
    ori::Node<std::string, 3>* n26 = new ori::Node<std::string, 3>("FFF");
    ori::Node<std::string, 3>* n27 = new ori::Node<std::string, 3>("GGG");
    ori::Node<std::string, 3>* n28 = new ori::Node<std::string, 3>("HHH");
    ori::Node<std::string, 3>* n29 = new ori::Node<std::string, 3>("III");
    ori::Node<std::string, 3>* n30 = new ori::Node<std::string, 3>("GGG");

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

    std::cout << "String Tree:" << std::endl;
    std::cout << stringTree << std::endl;



    // Complex Tree with more nodes
    ori::Tree<Complex, 3> complexTree;
    ori::Node<Complex, 3> * n31 = new ori::Node<Complex, 3>(Complex(1.0, 2.0));
    ori::Node<Complex, 3> * n32 = new ori::Node<Complex, 3>(Complex(3.0, 4.0));
    ori::Node<Complex, 3>* n33 = new ori::Node<Complex, 3>(Complex(5.0, 6.0));
    ori::Node<Complex, 3>* n34 = new ori::Node<Complex, 3>(Complex(7.0, 8.0));
    ori::Node<Complex, 3>* n35 = new ori::Node<Complex, 3>(Complex(9.0, 10.0));
    ori::Node<Complex, 3>* n36 = new ori::Node<Complex, 3>(Complex(11.0, 12.0));
    ori::Node<Complex, 3>* n37 = new ori::Node<Complex, 3>(Complex(13.0, 14.0));
    ori::Node<Complex, 3>* n38 = new ori::Node<Complex, 3>(Complex(15.0, 16.0));
    ori::Node<Complex, 3>* n39 = new ori::Node<Complex, 3>(Complex(17.0, 18.0));
    ori::Node<Complex, 3>* n40 = new ori::Node<Complex, 3>(Complex(19.0, 20.0));

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

    std::cout << "Complex Tree:" << std::endl;
    std::cout << complexTree << std::endl;



    // Large tre
    ori::Tree<int, 3> largeTree;
    int currentValue = 1;

    // Create root
    ori::Node<int, 3>* lroot = new ori::Node<int, 3>(currentValue++);
    largeTree.add_root(lroot);

    // First level
    ori::Node<int, 3>* child1 = new ori::Node<int, 3>(currentValue++);
    ori::Node<int, 3>* child2 = new ori::Node<int, 3>(currentValue++);
    ori::Node<int, 3>* child3 = new ori::Node<int, 3>(currentValue++);
    largeTree.add_sub_node(lroot, child1);
    largeTree.add_sub_node(lroot, child2);
    largeTree.add_sub_node(lroot, child3);

    // Second level
    for (int i = 0; i < 3; i++) 
    {
        ori::Node<int, 3>* child = new ori::Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child1, child);
    }
    for (int i = 0; i < 3; i++) 
    {
        ori::Node<int, 3>* child = new ori::Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child2, child);
    }
    for (int i = 0; i < 3; i++) 
    {
        ori::Node<int, 3>* child = new ori::Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child3, child);
    }

    // Third level
    for (int i = 0; i < 3; i++) 
    {
        ori::Node<int, 3>* child = new ori::Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child1->get_children()[0], child);
    }
    for (int i = 0; i < 3; i++) 
    {
        ori::Node<int, 3>* child = new ori::Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child2->get_children()[0], child);
    }
    for (int i = 0; i < 3; i++) 
    {
        ori::Node<int, 3>* child = new ori::Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child3->get_children()[0], child);
    }

    std::cout << "Large 3-ary Tree (int):" << std::endl;
    std::cout << largeTree;

    // BFS traversal
    std::cout << "BFS traversal:" << std::endl;
    for (auto node = largeTree.begin_bfs_scan(); node != largeTree.end_bfs_scan(); ++node) {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    // DFS traversal
    std::cout << "DFS traversal:" << std::endl;
    for (auto node = largeTree.begin_dfs_scan(); node != largeTree.end_dfs_scan(); ++node) {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    // Heap traversal
    std::cout << "Heap traversal:" << std::endl;
    for (auto node = largeTree.myHeap(); node != largeTree.end_heap(); ++node) {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;



    // 1-ary Tree with double values
    ori::Tree<double, 1> doubleTree;
    ori::Node<double, 1>* dn1 = new ori::Node<double, 1>(1.14);
    ori::Node<double, 1>* dn2 = new ori::Node<double, 1>(2.44);
    ori::Node<double, 1>* dn3 = new ori::Node<double, 1>(3.78);
    ori::Node<double, 1>* dn4 = new ori::Node<double, 1>(4.09);
    ori::Node<double, 1>* dn5 = new ori::Node<double, 1>(5.77);
    ori::Node<double, 1>* dn6 = new ori::Node<double, 1>(6.07);
    ori::Node<double, 1>* dn7 = new ori::Node<double, 1>(7.01);
    ori::Node<double, 1>* dn8 = new ori::Node<double, 1>(8.67);
    ori::Node<double, 1>* dn9 = new ori::Node<double, 1>(9.32);
    ori::Node<double, 1>* dn10 = new ori::Node<double, 1>(10.57);

    doubleTree.add_root(dn1);
    doubleTree.add_sub_node(dn1, dn2);
    doubleTree.add_sub_node(dn2, dn3);
    doubleTree.add_sub_node(dn3, dn4);
    doubleTree.add_sub_node(dn4, dn5);
    doubleTree.add_sub_node(dn5, dn6);
    doubleTree.add_sub_node(dn6, dn7);
    doubleTree.add_sub_node(dn7, dn8);
    doubleTree.add_sub_node(dn8, dn9);
    doubleTree.add_sub_node(dn9, dn10);

    // BFS traversal
    std::cout << "BFS traversal:" << std::endl;
    for (auto node = doubleTree.begin_bfs_scan(); node != doubleTree.end_bfs_scan(); ++node) 
    {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    // DFS traversal
    std::cout << "DFS traversal:" << std::endl;
    for (auto node = doubleTree.begin_dfs_scan(); node != doubleTree.end_dfs_scan(); ++node) 
    {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    // Heap traversal
    std::cout << "Heap traversal:" << std::endl;
    for (auto node = doubleTree.myHeap(); node != doubleTree.end_heap(); ++node) 
    {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "1-ary Tree of double:" << std::endl;
    std::cout << doubleTree;



    // 3-ary Tree with an upside-down 'V' shape
    ori::Tree<int, 3> vTree;

    ori::Node<int, 3>* rootNode = new ori::Node<int, 3>(20);
    vTree.add_root(rootNode);

    ori::Node<int, 3>* left1 = new ori::Node<int, 3>(15);
    ori::Node<int, 3>* left2 = new ori::Node<int, 3>(10);
    ori::Node<int, 3>* left3 = new ori::Node<int, 3>(5);

    ori::Node<int, 3>* right1 = new ori::Node<int, 3>(25);
    ori::Node<int, 3>* right2 = new ori::Node<int, 3>(30);
    ori::Node<int, 3>* right3 = new ori::Node<int, 3>(35);

    vTree.add_sub_node(rootNode, left1);
    vTree.add_sub_node(left1, left2);
    vTree.add_sub_node(left2, left3);

    vTree.add_sub_node(rootNode, right1);
    vTree.add_sub_node(right1, right2);
    vTree.add_sub_node(right2, right3);

    std::cout << "BFS traversal of V-shaped Tree:" << std::endl;
    for (auto node = vTree.begin_bfs_scan(); node != vTree.end_bfs_scan(); ++node) 
    {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "DFS traversal of V-shaped Tree:" << std::endl;
    for (auto node = vTree.begin_dfs_scan(); node != vTree.end_dfs_scan(); ++node) 
    {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "Heap traversal:" << std::endl;
    try {
        for (auto node = vTree.myHeap(); node != vTree.end_heap(); ++node) {
            std::cout << node->get_value() << " ";
        }
    } catch (std::exception& e) {
        std::cerr << "Error during heap traversal: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << vTree;

    return 0;
}