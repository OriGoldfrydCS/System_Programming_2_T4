// Email: origoldbsc@gmail.com

#ifndef HEAPITERATOR_HPP
#define HEAPITERATOR_HPP

#include "node.hpp"
#include <vector>
#include <algorithm>

namespace ori {

/**
 * @class HeapIterator
 * @brief Iterator for traversing a tree structure as if it were a min heap.
 *
 * @tparam T The data type of the elements stored in the tree nodes.
 * @tparam k The maximum number of children any node in the tree can have.
 */
template <typename T, int k>
class HeapIterator {
    
    private:

        /**
         * @struct CompareNodes
         * @brief Functor for comparing two nodes based on their values.
         * This functor enables the heap to maintain an order based on the node values, using a greater-than
         * comparison to form a min-heap.
         */
        struct CompareNodes 
        {
            bool operator()(Node<T, k>* a, Node<T, k>* b) 
            {
                return a->get_value() > b->get_value(); 
            }
        };

        std::vector<Node<T, k>*> heap;      // Container to store the nodes in heap order


        /**
         * @brief Recursively collects nodes from the tree and stores them in the heap vector.
         * This method performs a depth-first traversal of the tree, adding each node to the heap vector.
         * 
         * @param node The current node to collect.
         */
        void collectNodes(Node<T, k>* node) 
        {
            if (node) 
            {
                heap.push_back(node);
                for (auto child : node->get_children()) 
                {
                    collectNodes(child);
                }
            }
        }
    
    public:
        
        /**
         * @brief Constructs a HeapIterator from the root of a tree.
         * Initializes the iterator by collecting all nodes from the tree, starting at the specified root,
         * and arranging them into a heap based on the node values.
         * 
         * @param node The root node of the tree from which to create the heap.
         */
        HeapIterator(Node<T, k>* node) 
        {
            if (node) 
            {
                collectNodes(node);
                std::make_heap(heap.begin(), heap.end(), CompareNodes());
            }
        }


        /**
         * @brief Dereference operator to access the value of the node at the top of the heap.
         * @return Reference to the value of the node currently at the front of the heap.
         */
        Node<T, k>& operator*() 
        {
            return *heap.front();
        }


        /**
         * @brief Arrow operator to facilitate access to the current top node's members.
         * @return Pointer to the node currently at the front of the heap.
         */
        Node<T, k>* operator->() 
        {
            return heap.front();
        }


        /**
         * @brief Increment operator to move the iterator to the next node in the heap.
         * This method removes the top element from the heap and re-heapifies the remaining elements,
         * effectively moving the iterator to the next highest node according to the heap's comparison criteria.
         
         * @return Reference to this iterator after moving to the next node.
         */
        HeapIterator& operator++() 
        {
            std::pop_heap(heap.begin(), heap.end(), CompareNodes());
            heap.pop_back();
            return *this;
        }


        /**
         * @brief Inequality operator to compare this iterator with another iterator.
         * @param other Another HeapIterator to compare against.
         */
        bool operator!=(const HeapIterator&) const 
        {
            return !heap.empty();
        }
    };
}

#endif