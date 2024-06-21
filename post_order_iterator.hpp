// Email: origoldbsc@gmail.com

#ifndef POSTORDERITERATOR_HPP
#define POSTORDERITERATOR_HPP

#include "node.hpp"
#include <stack>
#include <set>
#include <algorithm>

using std::set;
namespace ori {

/**
 * @class PostOrderIterator
 * @brief Iterator for performing post-order traversal on a binary tree: LEFT->RIGHT->ROOT.
 *
 * @tparam T Data type of the node's value.
 */
template <typename T>
class PostOrderIterator {
    
    private:

        Node<T>* current;                // Current node being processed
        std::stack<Node<T>*> stack;      // Stack to track the path and manage backtracking
        set<Node<T>*> visited;           // Set to track visited nodes to prevent reprocessing


        /**
         * @brief Moves the iterator to the next leaf node from the current position.
         * 
         * This helper function traverses down the tree from the current node, 
         * pushing nodes onto the stack until a leaf node is reached. 
         * It starts from the current node and continuously moves to the leftmost child 
         * (if it exists and hasn't been visited yet) until it finds a leaf node.
         * Once a leaf node is found, it becomes the current node.
         */
        void moveToNextLeaf() 
        {
            // Traverse down to the next leaf node
            while (current) 
            {
                
                this->stack.push(current);      // Push the current node onto the stack
                
                // Check if the current node has unvisited children
                if (!this->current->get_children().empty() 
                && this->visited.find(this->current) == this->visited.end())     // Here I checks if the current node is not found in the visited set        
                {
                    // Move to the leftmost child (first child in the children vector)
                    this->current = this->current->get_children().front();
                } 

                // If no unvisited children, break the loop
                else 
                {
                    break;
                }
            }

            // If the stack is not empty, set the current node to the top of the stack
            if (!this->stack.empty()) 
            {
                this->current = this->stack.top();
            } 

            // If the stack is empty, the traversal completed
            else 
            {
                this->current = nullptr;
            }
        }


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
                    throw std::invalid_argument("PostOrderIterator can only be used on binary trees.");
                }
                validateBinaryTree(child);
            }
        }

    public:

        /**
         * @brief Initializes the iterator to start at the given root node.
         * This constructor sets the starting point for traversal and initializes internal structures.
         * It attempts to move to the first leaf node as a starting point for post-order traversal.
         * @param root Root node of the tree from which to start traversal.
         */
        PostOrderIterator(Node<T>* root)
        {
            validateBinaryTree(root);   // Validate the tree to ensure it is binary

            this->current = root;       // Set the current node to the provided root node
            
            // If the current node is not null, move to the next leaf node
            if (this->current) 
            {
                this->moveToNextLeaf();
            }
        }


        /**
         * @brief Copy constructor.
         * @param other The iterator to copy from.
         */
        PostOrderIterator(const PostOrderIterator& other) : current(other.current), stack(other.stack), visited(other.visited) {}


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
         * @brief Advances the iterator to the next node in post-order.
         * This method progresses the iterator by following post-order logic: visiting all children before the node itself.
         * @return Reference to this iterator after incrementing.
         */
        PostOrderIterator& operator++() 
        {
            // If the stack is empty, there are no more nodes to visit
            if (this->stack.empty()) 
            {
                this->current = nullptr;
                return *this;
            }

            this->visited.insert(this->current);        // Mark the current node as visited
            this->stack.pop();                          // Remove the current node from the stack

            // Find the next node using the stack and visited nodes
            if (!this->stack.empty()) 
            {   
                // Get the parent node of the current node
                Node<T>* parent = this->stack.top();

                // Find the position of the current node among its siblings
                auto it = std::find(parent->get_children().begin(), parent->get_children().end(), this->current);       // By find function I identufy the position of the current node within its parent's list of children
                                                                                                                        // Below is the signature of std::find:
                                                                                                                        // template<class InputIt, class T>
                                                                                                                        // InputIt find(InputIt first, InputIt last, const T& value);
                // Find the next sibling that hasn't been visited (if it + 1 is not equal to end(), it means there is another sibling)
                if ((it + 1) != parent->get_children().end())
                {
                    this->current = *(it + 1);  // If the current node has a next sibling, move to it
                    this->moveToNextLeaf();     // Move down to the leaf node from the current position
                } 

                // If no unvisited siblings are left, move up to the parent
                else 
                {
                    this->current = parent;
                }
            } 
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
        bool operator==(const PostOrderIterator& other) const 
        {
            return this->current == other.current;
        }

        /**
         * @brief Compares this iterator with another for inequality.
         * @param other The iterator to compare against.
         */
        bool operator!=(const PostOrderIterator& other) const 
        {
            return !(*this == other);
        }


        /**
         * @brief Assignment operator to assign one iterator to another.
         * @param other The iterator to assign from.
         * @return Reference to this iterator after assignment.
         */
        PostOrderIterator& operator=(const PostOrderIterator& other) 
        {
            if (this != &other) 
            {
                this->current = other.current;
                this->stack = other.stack;
                this->visited = other.visited;
            }
            return *this;
        }
    };
}

#endif
