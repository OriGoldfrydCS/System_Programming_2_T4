#ifndef DFSITERATOR_HPP
#define DFSITERATOR_HPP

#include "node.hpp"
#include <stack>

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
        std::stack<Node<T, k>*> stack;      // Stack used to hold nodes during the DFS traversal
    
    public:
        
        /**
         * @brief Constructs a DFSIterator starting at the specified node of a tree.
         * The constructor initializes the traversal by pushing the starting node onto the stack,
         * if it is not null.
         * @param node Pointer to the initial node from where DFS traversal begins.
         */
        DFSIterator(Node<T, k>* node) : stack() 
        {
            if (node) 
            {
                stack.push(node);
            }
        }


        /**
         * @brief Dereference operator to access the current node's content.
         * @return Reference to the data stored in the current node.
         */
        Node<T, k>& operator*() 
        {
            return *stack.top();
        }


        /**
         * @brief Arrow operator to able access to the current node's members.
         * @return Pointer to the current node.
         */
        Node<T, k>* operator->() 
        {
            return stack.top();
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
            Node<T, k>* current = stack.top();
            stack.pop();

            // Push all children of the current node onto the stack, in reverse order to visit the leftmost child first
            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) 
            {
                stack.push(*it);
            }
            return *this;
        }

        /**
         * @brief Inequality operator checks if two iterators are not equivalent.
         * @param other Another DFSIterator to compare with this iterator.
         */
        bool operator!=(const DFSIterator&) 
        {
            return !stack.empty();
        }
    };
}

#endif