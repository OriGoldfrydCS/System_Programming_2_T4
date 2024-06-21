// Email: origoldbsc@gmail.com

#ifndef BFSITERATOR_HPP
#define BFSITERATOR_HPP

#include "node.hpp"
#include <queue>

using std::queue;
namespace ori {

/**
 * @class BFSIterator
 * @brief Iterator for Breadth-First Search (BFS) traversing on a tree.
 *
 * @tparam T The data type of the elements stored in the tree nodes.
 */
template <typename T>
class BFSIterator {
    
    private:

        queue<Node<T>*> bfsQueue;        // Queue used to hold nodes during the BFS traversal
        Node<T>* current;                // Pointer to the currect node during the process
    
    public:

        /**
         * @brief Constructs a BFSIterator starting at the a root node of a tree.
         * @param root Pointer to the root node of the tree.
         *
         * @details If the root is not null, it is added to the queue to initiate BFS traversal.
         */
        BFSIterator(Node<T>* root) 
        {
            if (root) 
            {
                this->bfsQueue.push(root);
                this->current = bfsQueue.front();
            } 
            else 
            {
                this->current = nullptr;
            }
        }


        /**
         * @brief Copy constructor for BFSIterator.
         * Creates a new iterator that is a copy of an existing one.
         * @param other The iterator to copy from.
         */
        BFSIterator(const BFSIterator& other) : bfsQueue(other.bfsQueue), current(other.current) {}


        /**
         * @brief Dereference operator to access the current node's content.
         * @return Reference to the data stored in the current node.
         */
        Node<T>& operator*() 
        {
            return *this->current;
        }


        /**
         * @brief Arrow operator to able access to the current node's members.
         * @return Pointer to the current node.
         */
        Node<T>* operator->() 
        {
            return this->current;
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

            // Check if there are no more nodes to visit
            if (this->bfsQueue.empty()) 
            {
                this->current = nullptr;      // Set current to nullptr indicating the end of the traversal
                return *this;                 // Return this iterator (equivalent to an end iterator)
            }

            // Remove the current node from the queue
            this->bfsQueue.pop();

            // If the current node is valid (not nullptr), enqueue all children of the current node
            if (this->current) 
            {
                // Iterate over each child of the current node
                for (auto child : current->get_children()) 
                {
                    // Ensure that the child pointer is not null
                    if (child) 
                    {  
                        this->bfsQueue.push(child);      // Add the child to the queue for processing
                    }
                }
            }

            // Set the current node to the next node in the queue, or null if the queue is empty
            this->current = !this->bfsQueue.empty() ? this->bfsQueue.front() : nullptr;

            return *this;
        }


        /**
         * @brief Equality operator checks if two iterators are equal.
         * @param other Another BFSIterator to compare with this iterator.
         * @return True if the iterators point to the same node, false otherwise.
         */
        bool operator==(const BFSIterator& other) const 
        {
            return this->current == other.current;
        }


        /**
         * @brief Inequality operator checks if two iterators are not equivalent.
         * @param other Another BFSIterator to compare with this iterator.
         * @return True if the iterators do not point to the same node, false otherwise.
         */
        bool operator!=(const BFSIterator& other) const 
        {
            return !(*this == other);           // Same as: return current != other.current;
        }


         /**
         * @brief Assignment operator.
         * @param other The iterator to assign from.
         * @return Reference to this iterator after assignment.
         */
        BFSIterator& operator=(const BFSIterator& other) 
        {
            // Check for "self-assignment"
            if (this != &other) 
            {
                BFSIterator temp(other);                 // Create a temporary iterator using the copy constructor
                std::swap(this.queue, temp.bfsQueue);       // Swap the queue member of "this" object with the temporary iterator 
                std::swap(this.current, temp.current);   // Swap the current node pointer with that of the temporary iterator
            }
            
            // Return a reference to this object
            return *this;

            // Other option stuyind in class
            // if (this != &other) 
            // {
            //     queue = other.queue;
            //     current = other.current;
            // }
            // return *this;
        }
    };
}

#endif