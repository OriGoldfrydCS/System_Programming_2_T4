// Email: origoldbsc@gmail.com

#ifndef POSTORDERITERATOR_HPP
#define POSTORDERITERATOR_HPP

#include "node.hpp"
#include <stack>
#include <set>
#include <algorithm>

namespace ori {

/**
 * @class PostOrderIterator
 * @brief Iterator for performing post-order traversal on a tree.
 *
 * @tparam T Data type of the node's value.
 * @tparam k Maximum number of children a node can have.
 */
template <typename T, int k>
class PostOrderIterator {
    
    private:

        Node<T, k>* current;                // Current node being processed
        std::stack<Node<T, k>*> stack;      // Stack to track the path and manage backtracking
        std::set<Node<T, k>*> visited;      // Set to track visited nodes to prevent reprocessing


        /**
         * @brief Moves the iterator to the next leaf node from the current position.
         * This helper function pushes nodes onto the stack until a leaf node is reached, starting from the current node.
         */
        void moveToNextLeaf() 
        {
            while (current) 
            {
                // Push the first unvisited child or break if no unvisited children are left
                stack.push(current);
                if (!current->get_children().empty() && visited.find(current) == visited.end())                
                {
                    current = current->get_children().front();
                } 
                else 
                {
                    break;
                }
            }
            if (!stack.empty()) 
            {
                current = stack.top();
            } 
            else 
            {
                current = nullptr;
            }
        }

    public:

        /**
         * @brief Initializes the iterator to start at the given root node.
         * This constructor sets the starting point for traversal and initializes internal structures.
         * It attempts to move to the first leaf node as a starting point for post-order traversal.
         * @param root Root node of the tree from which to start traversal.
         */
        PostOrderIterator(Node<T, k>* root)
        {
            current = root;
            if (current) 
            {
                moveToNextLeaf();
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
         * @brief Advances the iterator to the next node in post-order.
         * This method progresses the iterator by following post-order logic: visiting all children before the node itself.
         * It handles tree structures by maintaining a stack to backtrack to unvisited nodes.
         * @return Reference to this iterator after incrementing.
         */
        PostOrderIterator& operator++() 
        {
            if (stack.empty()) 
            {
                current = nullptr;
                return *this;
            }

            // Mark the current node as visited
            visited.insert(current);
            stack.pop();

            // Process the next node using the stack and visited nodes
            if (!stack.empty()) 
            {
                Node<T, k>* parent = stack.top();
                auto it = std::find(parent->get_children().begin(), parent->get_children().end(), current);
                
                // Find the next sibling that hasn't been visited
                if ((it + 1) != parent->get_children().end())
                {
                    current = *(it + 1);
                    moveToNextLeaf();   // Move down to the leaf node
                } 
                else 
                {
                    current = parent;
                }
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
        bool operator!=(const PostOrderIterator& other) const 
        {
            return current != other.current;
        }
    };
}

#endif
