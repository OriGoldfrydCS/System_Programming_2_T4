// Email: origoldbsc@gmail.com

#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace ori;
using namespace std;

int main()
{

    // Binary tree that contains doubles.
    Tree<double> tree;       
    Node<double>* root_node = new Node<double>(1.1);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    
    cout << tree;   // Should print the graph using GUI.

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */
    
    cout << "Pre-order traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    
    cout << "\nPost-order traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "\nIn-order traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    cout << "\nBFS traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "\nDFS traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6 

    cout << "\nGenaral itertor:" << endl;
    for (auto node : tree)
    {
        cout << node.get_value() << " ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "\nHeap traversal:" << endl;
    for (auto node = tree.myHeap(); node != tree.end_heap(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << " " << endl;

    Tree<int, 3> three_ary_tree;
    Node<int, 3>* root_node_3 = new Node<int, 3>(1);
    Node<int, 3>* n1_3 = new Node<int, 3>(2);
    Node<int, 3>* n2_3 = new Node<int, 3>(3);
    Node<int, 3>* n3_3 = new Node<int, 3>(4);
    Node<int, 3>* n4_3 = new Node<int, 3>(5);
    Node<int, 3>* n5_3 = new Node<int, 3>(6);

    three_ary_tree.add_root(root_node_3);
    three_ary_tree.add_sub_node(root_node_3, n1_3);
    three_ary_tree.add_sub_node(root_node_3, n2_3);
    three_ary_tree.add_sub_node(root_node_3, n3_3);
    three_ary_tree.add_sub_node(n1_3, n4_3);
    three_ary_tree.add_sub_node(n2_3, n5_3);

    cout << three_ary_tree; // Should print the graph using GUI.

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    
    return 0;
}