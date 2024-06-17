// Email: origoldbsc@gmail.com

#ifndef HEAPITERATOR_HPP
#define HEAPITERATOR_HPP

#include "node.hpp"
#include <vector>
#include <algorithm>

using std::vector;
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
         * @brief Functor for comparing two nodes based on their values, and acts as comparator.
         * This functor checks if the value of node `a` is greater than the value of node `b`.
         * By providing this comparison to heap algorithms, it ensures that the smallest element 
         * is always at the front of the heap, thus maintaining a min-heap structure.
         *
         * @details
         * (1) The operator() is called by heap algorithms to compare two elements.
         * (2) If `a` is greater than `b`, it returns true, which the heap algorithms use to arrange
         * the elements such that the smallest element can bubble up to the front.
         */
        struct CompareNodes 
        {
            bool operator()(Node<T, k>* a, Node<T, k>* b) 
            {
                return a->get_value() > b->get_value(); 
            }
        };

        vector<Node<T, k>*> heap;      // Vector to store the nodes in heap order


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
                // Add the current node to the heap vecto
                this->heap.push_back(node);
                
                // Recursively collect all children of the current node
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
         * and arranging them into a heap based on their values.
         * 
         * @param node The root node of the tree from which to create the heap.
         */
        HeapIterator(Node<T, k>* node) 
        {
            if (node) 
            {
                // Collect all nodes from the tree by collectNodes() helper function
                this->collectNodes(node); 

                // Arrange the collected nodes into a heap based on the node values                                       
                std::make_heap(heap.begin(), heap.end(), CompareNodes());
            }
        }


        /**
         * @brief Copy constructor.
         * @param other The HeapIterator to copy.
         */
        HeapIterator(const HeapIterator& other) : heap(other.heap) {}


        /**
         * @brief Dereference operator to access the value of the node at the top of the heap.
         * @return Reference to the value of the node currently at the front of the heap.
         */
        Node<T, k>& operator*() 
        {
            return *this->heap.front();
        }


        /**
         * @brief Arrow operator to facilitate access to the current top node's members.
         * @return Pointer to the node currently at the front of the heap.
         */
        Node<T, k>* operator->() 
        {
            return this->heap.front();
        }


        /**
         * @brief Increment operator to move the iterator to the next node in the heap.
         * This method removes the top element from the heap and re-heapifies the remaining elements,
         * effectively moving the iterator to the next highest node according to the heap's comparison criteria.
         
         * @return Reference to this iterator after moving to the next node.
         */
        HeapIterator& operator++() 
        {
            // Move the smallest element to the end of the vector
            std::pop_heap(this->heap.begin(), this->heap.end(), CompareNodes());   // Works as heapify-down
            
            // Remove the element from the vector
            this->heap.pop_back();
            return *this;
        }


        /**
         * @brief Equality operator to compare this iterator with another iterator.
         * @param other Another HeapIterator to compare against.
         * @return True if both iterators are at the same position, false otherwise.
         */
        bool operator==(const HeapIterator& other) const 
        {
            return this->heap == other.heap; 
        }


        /**
         * @brief Inequality operator to compare this iterator with another iterator.
         * @param other Another HeapIterator to compare against.
         */
        bool operator!=(const HeapIterator& other) const 
        {
            return !(*this == other);
        }

        /**
         * @brief Assignment operator.
         * @param other The iterator to assign from.
         * @return Reference to this iterator after assignment.
         */
        HeapIterator& operator=(const HeapIterator& other)
        {
            if (this != &other) 
            {
                this->heap = other.heap; 
            }
            return *this;
        }
    };
}

#endif