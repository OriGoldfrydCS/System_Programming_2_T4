// Email: origoldbsc@gmail.com

#ifndef PREORDERITERATOR_HPP
#define PREORDERITERATOR_HPP

#include "node.hpp"
#include <stack>

namespace ori {

/**
 * @class PreOrderIterator
 * @brief Iterator for performing pre-order traversal on a binary tree: ROOT->LEFT->RIGHT.
 *
 * @tparam T Data type of the node's value.
 * @tparam k Maximum number of children a node can have.
 */
template <typename T>
class PreOrderIterator {
    
    private:

        Node<T>* current;                // Current node being processed
        std::stack<Node<T>*> stack;      // Stack to manage the traversal order


        /**
         * @brief Helper function to validate that the tree is binary.
         * Recursively checks all nodes in the tree to ensure no node has more than two children.
         * @param node The node from which to start the validation.
         * @throws std::invalid_argument if any node has more than two children.
         */
        void validateBinaryTree(Node<T>* node)
        {
            if (!node) return;
            for (const auto& child : node->get_children()) 
            {
                if (node->get_children().size() > 2) 
                {
                    throw std::invalid_argument("PreOrderIterator can only be used on binary trees.");
                }
                validateBinaryTree(child);
            }
        }

    public:

        /**
         * @brief Initializes the iterator to start at the given node.
         * This constructor sets pushes the initial node onto the stack to begin the traversal.
         * @param node Starting node of the traversal.
         */
        PreOrderIterator(Node<T>* node) : current(node) 
        {
            validateBinaryTree(node);       // Validate the tree to ensure it is binary

            // If the starting node is not null
            if (this->current) 
            {
                this->stack.push(this->current);
            }
        }


        /**
         * @brief Copy constructor.
         * @param other The iterator to copy from.
         */
        PreOrderIterator(const PreOrderIterator& other) : current(other.current), stack(other.stack) {}


        /**
         * @brief Dereferences the iterator to access the current node's value.
         * @return Reference to the current node.
         */
        Node<T>& operator*() 
        {
            return *this->current;
        }


        /**
         * @brief Accesses members of the current node.
         * @return Pointer to the current node.
         */
        Node<T>* operator->() 
        {
            return this->current;
        }


        /**
         * @brief Advances the iterator to the next node in pre-order.
         * This method progresses the iterator by visiting the current node first and then its children 
         * from left to right. If the current node has children, they are pushed onto the stack in reverse
         * to ensure that they are processed in the correct order.
         * @return Reference to this iterator after incrementing.
         */
        PreOrderIterator& operator++() 
        {
            // Check if the stack is empty. If so, there are no more nodes to visit
            if (this->stack.empty()) 
            {
                this->current = nullptr;
                return *this;
            }

            // Pop the current node from the top of the stack
            this->current = this->stack.top();
            this->stack.pop();

            // Get the children of the current node
            const auto& children = this->current->get_children();

            // Push the children onto the stack in reverse order to process them in left-to-right order
            if (children.size() > 1) 
            {
                this->stack.push(children[1]);      // If there are more than one child, push the right child first
            }
            if (!children.empty()) 
            {
                this->stack.push(children[0]);      // Push the left child
            }

            // Update the current node to the top of the stack
            if (!this->stack.empty()) 
            {
                this->current = this->stack.top();
            } 

            // If the stack is empty, we're done
            else 
            {
                this->current = nullptr;
            }

            return *this;
        }
        

        /**
         * @brief Compares this iterator with another for equality.
         * @param other The iterator to compare against.
         * @return True if the iterators point to the same node, otherwise false.
         */
        bool operator==(const PreOrderIterator& other) const 
        {
            return this->current == other.current;
        }


        /**
         * @brief Compares this iterator with another for inequality.
         * @param other The iterator to compare against.
         */
        bool operator!=(const PreOrderIterator& other) 
        {
            return !(*this == other);
        }


        /**
         * @brief Assignment operator to assign one iterator to another.
         * @param other The iterator to assign from.
         * @return Reference to this iterator after assignment.
         */
        PreOrderIterator& operator=(const PreOrderIterator& other) 
        {
            if (this != &other) 
            {
                this->current = other.current;
                this->stack = other.stack;
            }
            return *this;
        }
    };
}

#endif
