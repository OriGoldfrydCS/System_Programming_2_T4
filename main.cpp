#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"

using namespace ori;
using namespace std;

int main()
{
    // 5-ary tree that contains complex numbers.
    Tree<Complex, 5> tree;
    Node<Complex, 5>* root_node = new Node<Complex, 5>(Complex(1.1, 2.2));
    Node<Complex, 5>* n1 = new Node<Complex, 5>(Complex(3.3, 4.4));
    Node<Complex, 5>* n2 = new Node<Complex, 5>(Complex(5.5, 6.6));
    Node<Complex, 5>* n3 = new Node<Complex, 5>(Complex(7.7, 8.8));
    Node<Complex, 5>* n4 = new Node<Complex, 5>(Complex(9.9, 1.1));
    Node<Complex, 5>* n5 = new Node<Complex, 5>(Complex(2.2, 3.3));
    Node<Complex, 5>* n6 = new Node<Complex, 5>(Complex(4.4, 5.5));
    Node<Complex, 5>* n7 = new Node<Complex, 5>(Complex(6.6, 7.7));
    Node<Complex, 5>* n8 = new Node<Complex, 5>(Complex(8.8, 9.9));
    Node<Complex, 5>* n9 = new Node<Complex, 5>(Complex(1.0, 1.0));
    Node<Complex, 5>* n10 = new Node<Complex, 5>(Complex(2.0, 2.0));
    Node<Complex, 5>* n11 = new Node<Complex, 5>(Complex(3.0, 3.0));
    Node<Complex, 5>* n12 = new Node<Complex, 5>(Complex(4.0, 4.0));
    Node<Complex, 5>* n13 = new Node<Complex, 5>(Complex(5.0, 5.0));
    Node<Complex, 5>* n14 = new Node<Complex, 5>(Complex(6.0, 6.0));
    Node<Complex, 5>* n15 = new Node<Complex, 5>(Complex(7.0, 7.0));
    Node<Complex, 5>* n16 = new Node<Complex, 5>(Complex(8.0, 8.0));

    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(root_node, n4);
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n1, n6);
    tree.add_sub_node(n2, n7);
    tree.add_sub_node(n2, n8);
    tree.add_sub_node(n3, n9);
    tree.add_sub_node(n3, n10);
    tree.add_sub_node(n4, n11);
    tree.add_sub_node(n4, n12);
    tree.add_sub_node(n5, n13);
    tree.add_sub_node(n5, n14);
    tree.add_sub_node(n6, n15);
    tree.add_sub_node(n6, n16);

    // The tree should look like:
    /**
     *         root = 1.1+2.2i
     *      /     |     |     |     \
     *  3.3+4.4i 5.5+6.6i 7.7+8.8i 9.9+1.1i
     *  / \       / \     / \     / \
     * 2.2+3.3i 4.4+5.5i 6.6+7.7i 8.8+9.9i
     *  / \       / \     / \     / \
     * 1.0+1.0i 2.0+2.0i 3.0+3.0i 4.0+4.0i
     * 5.0+5.0i 6.0+6.0i 7.0+7.0i 8.0+8.0i
     */

    

    cout << "\nBFS traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << endl;
    }
    // Expected output: 1.1+2.2i, 3.3+4.4i, 5.5+6.6i, 7.7+8.8i, 9.9+1.1i, 2.2+3.3i, 4.4+5.5i, 6.6+7.7i, 8.8+9.9i, 1.0+1.0i, 5.0+5.0i, 6.0+6.0i, 7.0+7.0i, 8.0+8.0i, 3.0+3.0i, 4.0+4.0i

    cout << "\nDFS traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << endl;
    }
    // Expected output: 1.1+2.2i, 3.3+4.4i, 2.2+3.3i, 1.0+1.0i, 5.0+5.0i, 4.4+5.5i, 6.0+6.0i, 5.5+6.6i, 6.6+7.7i, 8.8+9.9i, 7.7+8.8i, 7.0+7.0i, 8.0+8.0i, 3.0+3.0i, 4.0+4.0i, 9.9+1.1i

    cout << "\nHeap traversal:" << endl;
    for (auto node = tree.myHeap(); node != tree.end_heap(); ++node) {
        cout << node->get_value() << endl;
    }
    // Expected output depends on the heap property; assuming a min-heap:
    // Output might look like: 1.0+1.0i, 1.1+2.2i, 2.0+2.0i, 2.2+3.3i, 3.0+3.0i, 3.3+4.4i, 4.0+4.0i, 4.4+5.5i, 5.0+5.0i, 5.5+6.6i, 6.0+6.0i, 6.6+7.7i, 7.0+7.0i, 7.7+8.8i, 8.0+8.0i, 8.8+9.9i, 9.9+1.1i
    
    return 0;
}