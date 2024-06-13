#ifndef BFSITERATOR_HPP
#define BFSITERATOR_HPP

#include "node.hpp"
#include <queue>

namespace ori {

/**
 * @class BFSIterator
 * @brief Iterator for Breadth-First Search (BFS) traversing on a tree.
 *
 * @tparam T The data type of the elements stored in the tree nodes.
 * @tparam k The maximum number of children any node in the tree can have.
 */
template <typename T, int k>
class BFSIterator {
    
    private:

        std::queue<Node<T, k>*> queue;      // Queqy used to hold nodes during the BFS traversal
        Node<T, k>* current;                // Pointer to the currect node during the process
    
    public:

        /**
         * @brief Constructs a BFSIterator starting at the a root node of a tree.
         * @param root Pointer to the root node of the tree.
         *
         * @details If the root is not null, it is added to the queue to initiate BFS traversal.
         */
        explicit BFSIterator(Node<T, k>* root) 
        {
            if (root) 
            {
                queue.push(root);
                current = queue.front();
            } 
            else 
            {
                current = nullptr;
            }
        }


        /**
         * @brief Dereference operator to access the current node's content.
         * @return Reference to the data stored in the current node.
         */
        Node<T, k>& operator*() 
        {
            return *current;
        }


        /**
         * @brief Arrow operator to able access to the current node's members.
         * @return Pointer to the current node.
         */
        Node<T, k>* operator->() 
        {
            return current;
        }


        /**
         * @brief Increment operator to move the iterator to the next node in the BFS traversal.
         * @return Reference to the updated iterator after moving to the next node.
         *
         * @details This method advances the iterator to the next node in the BFS traversal order.
         * It dequeues the current node and enqueues its children, updating the current node to the next in the queue.
         * If the queue becomes empty, the current node is set to nullptr, indicating the end of traversal.
         */
        BFSIterator& operator++() 
        {
            if (queue.empty()) 
            {
                current = nullptr;
                return *this;
            }

            // Remove the current node from the queue
            queue.pop();

            // Enqueue all children of the current node
            if (current) {
                for (auto child : current->children) 
                {
                    
                    // Ensure that the child pointer is not null
                    if (child) 
                    {  
                        queue.push(child);
                    }
                }
            }

            // Set the current node to the next node in the queue, or null if the queue is empty
            current = !queue.empty() ? queue.front() : nullptr;

            return *this;
        }

        /**
         * @brief Inequality operator checks if two iterators are not equivalent.
         * @param other Another BFSIterator to compare with this iterator.
         * @return True if the iterators do not point to the same node, false otherwise.
         */
        bool operator!=(const BFSIterator& other) const 
        {
            return current != other.current;
        }
    };
}

#endif