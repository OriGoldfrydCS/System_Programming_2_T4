// Email: origoldbsc@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

namespace ori {

    /**
    * @brief Represents a node in a k-ary tree.
    * The Node class is a template class that holds a value of type T and has a vector of child nodes.
    *
    * @tparam T The data type of the value stored in the node.
    */
    template <typename T>
    class Node {
        
        private:

            T value;                            // The value stored in the node
            std::vector<Node<T>*> children;     // The vector of pointers to the child nodes

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
             * @brief Provides access to the vector of child nodes.
             * @return Reference to the vector of child nodes.
             */
            std::vector<Node<T>*>& get_children() 
            { 
                return this->children; 
            }

            /**
             * @brief Provides const access to the vector of child nodes.
             * @return Const reference to the vector of child nodes.
             */
            const std::vector<Node<T>*>& get_children() const 
            { 
                return children; 
            }

        /**
         * @brief Adds a child node to the current node.
         * @param child Pointer to the node to be added as a child.
         */
        void add_child(Node<T>* child) 
        { 
            children.push_back(child); 
        }
    };
}  

#endif 