// Email: origoldbsc@gmail.com

#ifndef INORDERITERATOR_HPP
#define INORDERITERATOR_HPP

#include "node.hpp"
#include <stack>
#include <algorithm>

namespace ori {


/**
 * @class InOrderIterator
 * @brief Iterator for performing in-order traversal of a binary tree: LEFT->ROOT->RIGHT.
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
         * This function ensures that the traversal starts with the leftmost node.
         * @param node The node from which to start pushing left children.
         */
        void pushLeft(Node<T, k>* node) 
        {
            while (node != nullptr) 
            {
                // Push the current node onto the stack
                this->stack.push(node);

                // Check if the current node has children and if there is a left child
                if (!node->get_children().empty() && node->get_children().size() > 0) 
                {
                    node = node->get_children()[0]; // Go to left child (the first child in the vector of the children)
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
        InOrderIterator(Node<T, k>* root) 
        {
            this->current = nullptr;
            this->pushLeft(root);             // Initialize the stack by pushing left children starting from the root (included)
            
            if (!stack.empty()) 
            {
                this->current = this->stack.top();  // The current node is the leftmost node
            }
        }


        /**
         * @brief Copy constructor for InOrderIterator.
         * @param other The iterator to copy from.
         */
        InOrderIterator(const InOrderIterator& other) : current(other.current), stack(other.stack) {}


        /**
         * @brief Dereference operator to access the current node's value.
         * @return Reference to the current node.
         */
        Node<T, k>& operator*() const 
        {
            return *this->current;
        }


        /**
         * @brief Arrow operator to able access to the current node's members.
         * @return Pointer to the current node.
         */
        Node<T, k>* operator->() const 
        {
            return this->current;
        }


        /**
         * @brief Increment operator to move the iterator to the next node in in-order sequence.
         * @return Reference to this iterator after advancing to the next node.
         */
        InOrderIterator& operator++() 
        {
            if (this->stack.empty()) 
            {
                // If the stack is empty, there are no more nodes to visit
                this->current = nullptr;
                return *this;
            }
            
            this->current = this->stack.top();      // Set current to the top node in the stack
            this->stack.pop();                      // Pop the top node from the stack

            // Process the right subtree if it exists
            const auto& children = current->get_children();
            if (children.size() > 1) 
            {
                this->pushLeft(children[1]);        // If there is a right child, push all left children of the right subtree
            }

            // Update the current node to the new top of the stack
            if (!this->stack.empty()) 
            {
                this->current = this->stack.top();
            } 

            // If the stack is empty, set current to nullptr
            else 
            {
                this->current = nullptr;    // If stack is empty, we're done
            }

            return *this;
        }


        /**
         * @brief Equality operator to compare this iterator with another iterator.
         * @param other Another InOrderIterator to compare against.
         * @return True if the current nodes of the two iterators are the same, otherwise false.
         */
        bool operator==(const InOrderIterator& other) const 
        {
            return this->current == other.current;
        }


        /**
         * @brief Inequality operator to compare this iterator with another iterator.
         * @param other Another InOrderIterator to compare against.
         * @return True if the current nodes of the two iterators are different, otherwise false.
         */
        bool operator!=(const InOrderIterator& other) const 
        {
            return !(*this == other);
        }


        /**
         * @brief Assignment operator.
         * @param other The iterator to assign from.
         * @return Reference to this iterator after assignment.
         */
        InOrderIterator& operator=(const InOrderIterator& other) 
        {
            // Check for "self-assignment"
            if (this != &other) 
            {
                this->current = other.current;  // Copy the current node
                this->stack = other.stack;      // Copy the stack
            }
            return *this;
        }
    };
}

#endif