// Email: origoldbsc@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

namespace ori {

    /**
    * @brief Represents a node in a k-ary tree.
    * The Node class is a template class that holds a value of type T and has a vector of child nodes.
    * Each node can have up to k children.
    *
    * @tparam T The data type of the value stored in the node.
    * @tparam k The maximum number of children each node can have. Default is 2 (binary tree).
    */
    template <typename T, int k = 2>
    class Node {
        
        private:
        T value;                            // The value stored in the node
        std::vector<Node<T, k>*> children;  // The vector of pointers to the child nodes

        public:

            /**
             * @brief Constructor that initializes the node with a given value.
             * @param val The value to be stored in the node.
             */
            Node(const T& val) : value(val) {}
            

            /**
             * @brief Retrieves the value stored in the node.
             * @return The value stored in the node.
             */
            T get_value() const 
            {  
                return value;
            }

            /**
             * @brief Adds a child node to the current node.
             * The function adds the child node to the vector of children if the maximum number
             * of children hasn't been reached.
             * @param child A pointer to the child node to be added.
             */
            void add_child(Node<T, k>* child) 
            {
                if (children.size() < k) 
                {
                    children.push_back(child);
                }
            }

            /**
             * @brief Returns the children of the node.
             * @return A reference to the vector of child nodes.
             */
            const std::vector<Node<T, k>*>& get_children() const 
            {
                return children;
            }
    };
}  

#endif 