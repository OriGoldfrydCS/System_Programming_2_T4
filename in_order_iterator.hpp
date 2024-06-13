// Email: origoldbsc@gmail.com

#ifndef INORDERITERATOR_HPP
#define INORDERITERATOR_HPP

#include "node.hpp"
#include <stack>
#include <algorithm>

namespace ori {


/**
 * @class InOrderIterator
 * @brief Iterator for performing in-order traversal of a tree with a specified maximum number of children per node.
 * This iterator allows for in-order traversal of a tree, which can be particularly useful in binary trees
 * where in-order traversal visits nodes in a non-decreasing order.
 * 
 * @tparam T The data type of the elements stored in the tree nodes.
 * @tparam k The maximum number of children any node in the tree can have.
 */
template <typename T, int k>
class InOrderIterator {
    
    private:

        Node<T, k>* current;                // Pointer to the current node in the traversal
        std::stack<Node<T, k>*> stack;      // Stack used to manage the traversal of nodes


        /**
         * @brief Helper function to push the left child of each node onto the stack.
         * Recursively pushes the leftmost children of the given node onto the stack until no left child is available.
         * @param node The node from which to start pushing left children.
         */
        void pushLeft(Node<T, k>* node) 
        {
            // Push all the left children of the given node onto the stack
            while (node != nullptr) 
            {
                stack.push(node);
                if (!node->get_children().empty() && node->get_children().size() > 0) 
                {
                    node = node->get_children()[0]; // Go to left child
                } 
                else 
                {
                    break; // No left child exists
                }
            }
        }

    public:

        /**
         * @brief Constructs an InOrderIterator starting at the root of the tree.
         * This constructor initializes the iterator by pushing all the left children of the tree onto a stack,
         * starting with the root, preparing the iterator to begin the in-order traversal from the smallest element.
         * 
         * @param root The root node of the tree from which to start the in-order traversal.
         */
        explicit InOrderIterator(Node<T, k>* root) 
        {
            current = nullptr;
            pushLeft(root);             // Initialize by pushing left children starting from the root.
            if (!stack.empty()) 
            {
                current = stack.top();  // Start with the leftmost node
            }
        }


        /**
         * @brief Dereference operator to access the current node's value.
         * @return Reference to the current node.
         */
        Node<T, k>& operator*() const 
        {
            return *current;
        }


        /**
         * @brief Arrow operator to able access to the current node's members.
         * @return Pointer to the current node.
         */
        Node<T, k>* operator->() const {
            return current;
        }


        /**
         * @brief Increment operator to move the iterator to the next node in in-order sequence.
         * @return Reference to this iterator after advancing to the next node.
         */
        InOrderIterator& operator++() 
        {
            if (stack.empty()) 
            {
                current = nullptr;
                return *this;
            }

            current = stack.top();
            stack.pop();

            // Process the right subtree if it exists
            const auto& children = current->get_children();
            if (children.size() > 1) 
            {
                pushLeft(children[1]); 
            }

            if (!stack.empty()) 
            {
                current = stack.top();
            } 
            else 
            {
                current = nullptr; // If stack is empty, we're done
            }

            return *this;
        }


        /**
         * @brief Inequality operator to compare this iterator with another iterator.
         * @param other Another InOrderIterator to compare against.
         * @return True if the current nodes of the two iterators are different, otherwise false.
         */
        bool operator!=(const InOrderIterator& other) const 
        {
            return current != other.current;
        }
    };
}

#endif