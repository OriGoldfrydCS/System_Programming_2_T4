#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <iomanip>
#include "node.hpp"
#include "complex.hpp"
#include "pre_order_iterator.hpp"
#include "post_order_iterator.hpp"
#include "in_order_iterator.hpp"
#include "bfs_iterator.hpp"
#include "dfs_iterator.hpp"
#include "heap_iterator.hpp"


namespace ori {

/**
 * @class Tree
 * @brief Generic tree structure to hold elements of any type with a specified number of children.
 *
 * @tparam T Data type of the tree nodes.
 * @tparam k Maximum number of children each node can have.
 */
template <typename T, int k = 2>
class Tree {

    public:

        Node<T, k>* root = nullptr;         // Pointer to the root node of the tree

        /**
         * @brief Constructor that initializes an empty tree.
         */
        Tree() {}


        /**
         * @brief Destructor that cleans up by destroying the tree.
         */
        ~Tree() 
        {
            destroyTree(root);
        }

        
        /**
         * @brief Adds a root node to the tree.
         * @param node A pointer to the node that will become the new root.
         * 
         * If there is already a root, it gets deleted and replaced by the new node.
         */
        void add_root(Node<T, k>* node) 
        {
            // Clean up existing root if it exists
            if (root) {  
                delete root;
            }
            root = node;  // Directly use the passed node as the root
        }


        /**
         * @brief Adds a child node to a specified parent node.
         * @param parent Pointer to the parent node.
         * @param child Pointer to the child node to be added.
         *
         * The function adds the child node to the parent's list of children if the maximum number hasn't been reached.
         */
        void add_sub_node(Node<T, k>* parent, Node<T, k>* child) 
        {
            if (parent && parent->children.size() < k) 
            {
                parent->children.push_back(child);
            }
        }

        // Iterator access functions
        PreOrderIterator<T, k> begin_pre_order() { return PreOrderIterator<T, k>(root); }
        PreOrderIterator<T, k> end_pre_order() { return PreOrderIterator<T, k>(nullptr); }

        PostOrderIterator<T, k> begin_post_order() { return PostOrderIterator<T, k>(root); }
        PostOrderIterator<T, k> end_post_order() { return PostOrderIterator<T, k>(nullptr); }

        InOrderIterator<T, k> begin_in_order() { return InOrderIterator<T, k>(root); }
        InOrderIterator<T, k> end_in_order() { return InOrderIterator<T, k>(nullptr); }

        BFSIterator<T, k> begin_bfs_scan() { return BFSIterator<T, k>(root); }
        BFSIterator<T, k> end_bfs_scan() { return BFSIterator<T, k>(nullptr); }

        BFSIterator<T, k> begin() {  return begin_bfs_scan(); }
        BFSIterator<T, k> end() {  return end_bfs_scan(); }

        DFSIterator<T, k> begin_dfs_scan() { return DFSIterator<T, k>(root); }
        DFSIterator<T, k> end_dfs_scan() { return DFSIterator<T, k>(nullptr); }

        HeapIterator<T, k> myHeap() { return HeapIterator<T, k>(root); }
        HeapIterator<T, k> end_heap() { return HeapIterator<T, k>(nullptr); }


        /**
         * @brief Overloads the stream << operator to provide a simple tree output (for debugging).
         * @param os Output stream.
         * @param tree The tree to be printed.
         * @return Reference to the output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, const Tree<T, k>& tree) {
            if (!tree.root) 
            {
                return os << "Empty tree";
            }

            std::queue<Node<T, k>*> q;
            q.push(tree.root);
            size_t currentLevel = 0;
            size_t nextLevelCount = 1;

            while (!q.empty()) 
            {
                Node<T, k>* currentNode = q.front();
                q.pop();
                nextLevelCount--;

                os << std::setw(10) << currentNode->value << " | ";
                if (!currentNode->children.empty()) 
                {
                    for (const auto& child : currentNode->children) 
                    {
                        os << child->value << " ";
                        q.push(child);
                    }
                } 
                else 
                {
                    os << "- ";
                }
                os << std::endl;

                if (nextLevelCount == 0) 
                {
                    currentLevel++;
                    nextLevelCount = q.size();
                    if (nextLevelCount > 0) 
                    {
                        os << std::string(10 * currentLevel, '-') << std::endl;
                    }
                }
            }
            return os;
        }

    private:

        /**
         * @brief Recursively destroys the tree, freeing all nodes.
         * @param node The current node to destroy.
         */
        void destroyTree(Node<T, k>* node) 
        {
            if (node) 
            {
                for (auto child : node->children) 
                {
                    destroyTree(child);
                }
                delete node;
            }
        }
    };
} 

#endif  