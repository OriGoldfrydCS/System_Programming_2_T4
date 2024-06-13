// Email: origoldbsc@gmail.com

#ifndef PREORDERITERATOR_HPP
#define PREORDERITERATOR_HPP

#include "node.hpp"
#include <stack>

namespace ori {


/**
 * @class PreOrderIterator
 * @brief Iterator for performing pre-order traversal on a tree.
 *
 * @tparam T Data type of the node's value.
 * @tparam k Maximum number of children a node can have.
 */
template <typename T, int k>
class PreOrderIterator {
    
    private:
        Node<T, k>* current;                // Current node being processed
        std::stack<Node<T, k>*> stack;      // Stack to manage the traversal order

    public:

        /**
         * @brief Initializes the iterator to start at the given node.
         * This constructor sets the starting point for traversal and initializes internal structures.
         * It pushes the initial node onto the stack to begin the traversal.
         * @param node Starting node of the traversal.
         */
        PreOrderIterator(Node<T, k>* node) : current(node) 
        {
            if (current) 
            {
                stack.push(current);
            }
        }


        /**
         * @brief Dereferences the iterator to access the current node's value.
         * @return Reference to the current node.
         */
        Node<T, k>& operator*() 
        {
            return *current;
        }


        /**
         * @brief Accesses members of the current node.
         * @return Pointer to the current node.
         */
        Node<T, k>* operator->() 
        {
            return current;
        }


        /**
         * @brief Advances the iterator to the next node in pre-order.
         * This method progresses the iterator by visiting the current node first and then its children 
         * from left to right. If the current node has children, they are pushed onto the stack in reverse
         * order to ensure that they are processed in the correct sequence.
         * @return Reference to this iterator after incrementing.
         */
        PreOrderIterator& operator++() 
        {
            if (stack.empty()) 
            {
                current = nullptr;
                return *this;
            }

            // Pop the current node
            current = stack.top();
            stack.pop();

            // Push children onto the stack in reverse order to process them in left-to-right order
            const auto& children = current->get_children();
            if (children.size() > 1) 
            {
                stack.push(children[1]);
            }
            if (!children.empty()) 
            {
                stack.push(children[0]);
            }

            if (!stack.empty()) 
            {
                current = stack.top();
            } 
            else 
            {
                current = nullptr;
            }

            return *this;
        }
        

        /**
         * @brief Compares this iterator with another for inequality.
         * @param other The iterator to compare against.
         */
        bool operator!=(const PreOrderIterator& other) {
            return current != other.current;
        }

    
    };
}

#endif
