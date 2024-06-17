// Email: origoldbsc@gmail.com

#include <iostream>
#include <string>
#include "tree.hpp"
#include "node.hpp"
#include "complex.hpp"

using namespace ori;
using std::cout;
using std::endl;
using std::string;

int main() {

    // Binary Tree (int)
    Tree<int> binaryTree;
    Node<int>* n1 = new Node<int>(1);
    Node<int>* n2 = new Node<int>(2);
    Node<int>* n3 = new Node<int>(3);
    Node<int>* n4 = new Node<int>(4);
    Node<int>* n5 = new Node<int>(5);
    Node<int>* n6 = new Node<int>(6);
    Node<int>* n7 = new Node<int>(7);
    Node<int>* n8 = new Node<int>(8);
    Node<int>* n9 = new Node<int>(9);
    Node<int>* n10 = new Node<int>(10);

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

    cout << "Binary Tree (int):" << endl;

    // Pre-order traversal: 1 2 4 8 9 5 10 3 6 7
    cout << "Pre-order traversal:" << endl;
    for (auto node = binaryTree.begin_pre_order(); node != binaryTree.end_pre_order(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // In-order traversal: 8 4 9 2 10 5 1 6 3 7
    cout << "In-order traversal:" << endl;
    for (auto node = binaryTree.begin_in_order(); node != binaryTree.end_in_order(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Post-order traversal: 8 9 4 10 5 2 6 7 3 1
    cout << "Post-order traversal:" << endl;
    for (auto node = binaryTree.begin_post_order(); node != binaryTree.end_post_order(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // BFS traversal: 1 2 3 4 5 6 7 8 9 10
    cout << "BFS traversal:" << endl;
    for (auto node = binaryTree.begin_bfs_scan(); node != binaryTree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // DFS traversal: 1 2 4 8 9 5 10 3 6 7
    cout << "DFS traversal:" << endl;
    for (auto node = binaryTree.begin_dfs_scan(); node != binaryTree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Heap traversal: 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    cout << "Heap traversal:" << endl;
    for (auto node = binaryTree.myHeap(); node != binaryTree.end_heap(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << binaryTree << endl;



    // Trinary Tree (double)
    Tree<double, 3> trinaryTree;
    Node<double, 3>* n11 = new Node<double, 3>(3.14);
    Node<double, 3>* n12 = new Node<double, 3>(2.71);
    Node<double, 3>* n13 = new Node<double, 3>(1.41);
    Node<double, 3>* n14 = new Node<double, 3>(4.2);
    Node<double, 3>* n15 = new Node<double, 3>(5.5);
    Node<double, 3>* n16 = new Node<double, 3>(6.6);
    Node<double, 3>* n17 = new Node<double, 3>(7.7);
    Node<double, 3>* n18 = new Node<double, 3>(8.8);
    Node<double, 3>* n19 = new Node<double, 3>(9.9);
    Node<double, 3>* n20 = new Node<double, 3>(10.0);

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

    cout << "Trinary Tree (double):" << endl;

    // BFS traversal: 3.14 2.71 1.41 4.2 5.5 6.6 7.7 8.8 9.9 10
    cout << "BFS traversal:" << endl;
    for (auto node = trinaryTree.begin_bfs_scan(); node != trinaryTree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // DFS traversal: 3.14 2.71 5.5 6.6 7.7 1.41 8.8 9.9 10
    cout << "DFS traversal:" << endl;
    for (auto node = trinaryTree.begin_dfs_scan(); node != trinaryTree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Heap traversal: 10 9.9 8.8 7.7 6.6 5.5 4.2 3.14 2.71 1.41
    cout << "Heap traversal:" << endl;
    for (auto node = trinaryTree.myHeap(); node != trinaryTree.end_heap(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << trinaryTree << endl;


    // String Tree 
    Tree<string, 3> stringTree;
    Node<string, 3>* n21 = new Node<string, 3>("AAA");
    Node<string, 3>* n22 = new Node<string, 3>("BBB");
    Node<string, 3>* n23 = new Node<string, 3>("CCC");
    Node<string, 3>* n24 = new Node<string, 3>("DDD");
    Node<string, 3>* n25 = new Node<string, 3>("EEE");
    Node<string, 3>* n26 = new Node<string, 3>("FFF");
    Node<string, 3>* n27 = new Node<string, 3>("GGG");
    Node<string, 3>* n28 = new Node<string, 3>("HHH");
    Node<string, 3>* n29 = new Node<string, 3>("III");
    Node<string, 3>* n30 = new Node<string, 3>("JJJ");

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

    cout << "String Tree:" << endl;

    // BFS traversal: AAA BBB CCC DDD EEE FFF GGG HHH III JJJ 
    cout << "BFS traversal:" << endl;
    for (auto node = stringTree.begin_bfs_scan(); node != stringTree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // DFS traversal: AAA BBB EEE FFF GGG CCC HHH III JJJ DDD
    cout << "DFS traversal:" << endl;
    for (auto node = stringTree.begin_dfs_scan(); node != stringTree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Heap traversal: AAA BBB CCC DDD EEE FFF GGG HHH III JJJ
    cout << "Heap traversal:" << endl;
    for (auto node = stringTree.myHeap(); node != stringTree.end_heap(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << stringTree << endl;



    // Complex Tree with more nodes
    Tree<Complex, 3> complexTree;
    Node<Complex, 3> * n31 = new Node<Complex, 3>(Complex(1.0, 2.0));
    Node<Complex, 3> * n32 = new Node<Complex, 3>(Complex(3.0, 4.0));
    Node<Complex, 3>* n33 = new Node<Complex, 3>(Complex(5.0, 6.0));
    Node<Complex, 3>* n34 = new Node<Complex, 3>(Complex(7.0, 8.0));
    Node<Complex, 3>* n35 = new Node<Complex, 3>(Complex(9.0, 10.0));
    Node<Complex, 3>* n36 = new Node<Complex, 3>(Complex(11.0, 12.0));
    Node<Complex, 3>* n37 = new Node<Complex, 3>(Complex(13.0, 14.0));
    Node<Complex, 3>* n38 = new Node<Complex, 3>(Complex(15.0, 16.0));
    Node<Complex, 3>* n39 = new Node<Complex, 3>(Complex(17.0, 18.0));
    Node<Complex, 3>* n40 = new Node<Complex, 3>(Complex(19.0, 20.0));

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

    cout << "Complex Tree:" << endl;

    // BFS traversal: (1+2i) (3+4i) (5+6i) (7+8i) (9+10i) (11+12i) (13+14i) (15+16i) (17+18i) (19+20i)
    cout << "BFS traversal:" << endl;
    for (auto node = complexTree.begin_bfs_scan(); node != complexTree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // DFS traversal: (1+2i) (3+4i) (7+8i) (15+16i) (17+18i) (9+10i) (5+6i) (11+12i) (13+14i) (19+20i)
    cout << "DFS traversal:" << endl;
    for (auto node = complexTree.begin_dfs_scan(); node != complexTree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Heap traversal: (19+20i) (17+18i) (15+16i) (13+14i) (11+12i) (9+10i) (7+8i) (5+6i) (3+4i) (1+2i)
    cout << "Heap traversal:" << endl;
    for (auto node = complexTree.myHeap(); node != complexTree.end_heap(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << complexTree << endl;



    // Large (int) tree
    Tree<int, 3> largeTree;
    int currentValue = 1;

    Node<int, 3>* lroot = new Node<int, 3>(currentValue++);
    largeTree.add_root(lroot);

    // First level
    Node<int, 3>* child1 = new Node<int, 3>(currentValue++);
    Node<int, 3>* child2 = new Node<int, 3>(currentValue++);
    Node<int, 3>* child3 = new Node<int, 3>(currentValue++);
    largeTree.add_sub_node(lroot, child1);
    largeTree.add_sub_node(lroot, child2);
    largeTree.add_sub_node(lroot, child3);

    // Second level
    for (int i = 0; i < 3; i++) 
    {
        Node<int, 3>* child = new Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child1, child);
    }
    for (int i = 0; i < 3; i++) 
    {
        Node<int, 3>* child = new Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child2, child);
    }
    for (int i = 0; i < 3; i++) 
    {
        Node<int, 3>* child = new Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child3, child);
    }

    // Third level
    for (int i = 0; i < 3; i++) 
    {
        Node<int, 3>* child = new Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child1->get_children()[0], child);
    }
    for (int i = 0; i < 3; i++) 
    {
        Node<int, 3>* child = new Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child2->get_children()[0], child);
    }
    for (int i = 0; i < 3; i++) 
    {
        Node<int, 3>* child = new Node<int, 3>(currentValue++);
        largeTree.add_sub_node(child3->get_children()[0], child);
    }

    cout << "Large 3-ary Tree (int):" << endl;

    // BFS traversal: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 
    cout << "BFS traversal:" << endl;
    for (auto node = largeTree.begin_bfs_scan(); node != largeTree.end_bfs_scan(); ++node) 
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // DFS traversal: 1 2 5 14 15 16 6 7 3 8 17 18 19 9 10 4 11 20 21 22 12 13 
    cout << "DFS traversal:" << endl;
    for (auto node = largeTree.begin_dfs_scan(); node != largeTree.end_dfs_scan(); ++node) 
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Heap traversal: 1.14 2.44 3.78 4.09 5.77 6.07 7.01 8.67 9.32 10.57 
    cout << "Heap traversal:" << endl;
    for (auto node = largeTree.myHeap(); node != largeTree.end_heap(); ++node) 
    {
        cout << node->get_value() << " ";
    }

    cout << largeTree << endl;


    // 1-ary Tree with doubles
    Tree<double, 1> doubleTree;
    Node<double, 1>* dn1 = new Node<double, 1>(4.09);
    Node<double, 1>* dn2 = new Node<double, 1>(2.44);
    Node<double, 1>* dn3 = new Node<double, 1>(3.78);
    Node<double, 1>* dn4 = new Node<double, 1>(10.57);
    Node<double, 1>* dn5 = new Node<double, 1>(8.67);
    Node<double, 1>* dn6 = new Node<double, 1>(6.07); 
    Node<double, 1>* dn7 = new Node<double, 1>(7.01);
    Node<double, 1>* dn8 = new Node<double, 1>(1.14);
    Node<double, 1>* dn9 = new Node<double, 1>(9.32);
    Node<double, 1>* dn10 = new Node<double, 1>(5.77);

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

    cout << "1-ary Tree of doubles:" << endl;

    // BFS traversal: 4.09 2.44 3.78 10.57 8.67 6.07 7.01 1.14 9.32 5.77 
    cout << "BFS traversal:" << endl;
    for (auto node = doubleTree.begin_bfs_scan(); node != doubleTree.end_bfs_scan(); ++node) 
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // DFS traversal: 4.09 2.44 3.78 10.57 8.67 6.07 7.01 1.14 9.32 5.77
    cout << "DFS traversal:" << endl;
    for (auto node = doubleTree.begin_dfs_scan(); node != doubleTree.end_dfs_scan(); ++node) 
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Heap traversal: 1.14 2.44 3.78 4.09 5.77 6.07 7.01 8.67 9.32 10.57
    cout << "Heap traversal:" << endl;
    for (auto node = doubleTree.myHeap(); node != doubleTree.end_heap(); ++node) 
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << doubleTree << endl;



    // 3-ary Tree with an upside-down 'V' shape
    Tree<int, 3> vTree;
    Node<int, 3>* rootNode = new Node<int, 3>(20);
    Node<int, 3>* left1 = new Node<int, 3>(15);
    Node<int, 3>* left2 = new Node<int, 3>(10);
    Node<int, 3>* left3 = new Node<int, 3>(5);
    Node<int, 3>* right1 = new Node<int, 3>(25);
    Node<int, 3>* right2 = new Node<int, 3>(30);
    Node<int, 3>* right3 = new Node<int, 3>(35);
    
    vTree.add_root(rootNode);
    vTree.add_sub_node(rootNode, left1);
    vTree.add_sub_node(left1, left2);
    vTree.add_sub_node(left2, left3);
    vTree.add_sub_node(rootNode, right1);
    vTree.add_sub_node(right1, right2);
    vTree.add_sub_node(right2, right3);

    cout << "V-shaped Tree:" << endl;

    // BFS traversal: 4.09 2.44 3.78 10.57 8.67 6.07 7.01 1.14 9.32 5.77 
    cout << "BFS traversal:" << endl;
    for (auto node = vTree.begin_bfs_scan(); node != vTree.end_bfs_scan(); ++node) 
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // DFS traversal: 4.09 2.44 3.78 10.57 8.67 6.07 7.01 1.14 9.32 5.77 
    cout << "DFS traversal:" << endl;
    for (auto node = vTree.begin_dfs_scan(); node != vTree.end_dfs_scan(); ++node) 
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Heap traversal: 1.14 2.44 3.78 4.09 5.77 6.07 7.01 8.67 9.32 10.57 
    cout << "Heap traversal:" << endl;
    
    for (auto node = vTree.myHeap(); node != vTree.end_heap(); ++node) 
    {
        cout << node->get_value() << " ";
    }
    
    cout << vTree << endl;

    return 0;
}