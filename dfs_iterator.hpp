// Email: origoldbsc@gmail.com

#ifndef DFSITERATOR_HPP
#define DFSITERATOR_HPP

#include "node.hpp"
#include <stack>
#include <algorithm>

using std::stack;
namespace ori {

/**
 * @class DFSIterator
 * @brief Iterator for performing Depth-First Search (DFS) on a tree.
 *
 * @tparam T The data type of the elements stored in the tree nodes.
 * @tparam k The maximum number of children any node in the tree can have.
 */
template <typename T, int k>
class DFSIterator {

    private:
        stack<Node<T, k>*> dfsStack;      // Stack used to hold nodes during the DFS traversal
    
    public:
        
        /**
         * @brief Constructs a DFSIterator starting at the specified node of a tree (which is the "currect" node).
         * The constructor initializes the traversal by pushing the starting node onto the stack, if it is not null.
         * @param node Pointer to the initial node from where DFS traversal begins.
         */
        DFSIterator(Node<T, k>* node) : dfsStack() 
        {
            if (node) 
            {
                this->dfsStack.push(node);
            }
        }

        /**
         * @brief Copy constructor.
         * @param other The DFSIterator to copy.
         */
        DFSIterator(const DFSIterator& other) : dfsStack(other.dfsStack) {}


        /**
         * @brief Dereference operator to access the current node's *content*.
         * @return Reference to the data stored in the current node.
         */
        Node<T, k>& operator*() 
        {
            return *this->dfsStack.top();
        }


        /**
         * @brief Arrow operator to able access to the current node's members (the top element in the stack).
         * @return Pointer to the current node.
         */
        Node<T, k>* operator->() 
        {
            return this->dfsStack.top();
        }


        /**
         * @brief Increment operator to move the iterator to the next node in the DFS traversal.
         * @return Reference to the updated iterator after moving to the next node.
         *
         * @details This method advances the iterator by popping the current node from the stack
         * and then pushing all of its children onto the stack. This ensures that the next node
         * visited is the first child of the current node, adhering to the depth-first principle.
         */
        DFSIterator& operator++() 
        {
            Node<T, k>* current = this->dfsStack.top();
            this->dfsStack.pop();

            // Push all children of the current node onto the stack, in reverse order to visit the leftmost child first.
            const auto& children = current->get_children(); 
            for (auto it = children.rbegin(); it != children.rend(); ++it) 
            {
                this->dfsStack.push(*it);
            }
            return *this;
        }


        /**
         * @brief Equality operator.
         * Compares this iterator with another for equivalence.
         * @param other Another DFSIterator to compare to.
         * @return True if both iterators have the same current node, false otherwise.
         */
        bool operator==(const DFSIterator& other) const
        {
            // Check if both stacks are empty
            if (this->dfsStack.empty() && other.dfsStack.empty()) 
            {
                return true;
            }

            // Check if both stacks are not empty and have the same element on the top
            else if (!this->dfsStack.empty() && !other.dfsStack.empty()) 
            {
                return this->dfsStack.top() == other.dfsStack.top();
            }

            // One stack is empty and the other is not
            else 
            {
                return false;
            }
        }


        /**
         * @brief Inequality operator checks if two iterators are not equivalent.
         * @param other Another DFSIterator to compare with this iterator.
         */
        bool operator!=(const DFSIterator& other) 
        {
            return !(*this == other);
        }

        /**
         * @brief Assignment operator.
         * @param other The DFSIterator to assign from.
         * @return Reference to this instance after assignment.
         */
        DFSIterator& operator=(const DFSIterator& other)
        {
            if (this != &other) 
            {
                this->dfsStack = other.dfsStack;    // Copy the stack
            }
            return *this;
        }
    };
}

#endif