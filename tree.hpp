#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <set>
#include "node.hpp"
#include "complex.hpp"


namespace ori {

template <typename T, int k> class BFSIterator;




template <typename T, int k = 2>
class Tree {
public:

    Node<T, k>* root = nullptr;

    // Constructors and destructor
    Tree() {}
    ~Tree() {
        destroyTree(root);
    }

    // Adding nodes
   void add_root(Node<T, k>* node) {
        if (root) {  // Clean up existing root if it exists
            delete root;
        }
        root = node;  // Directly use the passed node as the root
    }

    // Modified to accept a parent node and a child node pointer
    void add_sub_node(Node<T, k>* parent, Node<T, k>* child) {
        if (parent && parent->children.size() < k) {
            parent->children.push_back(child);
        }
    }

    // Iterators
    class PreOrderIterator {
    public:
        PreOrderIterator(Node<T, k>* node) : current(node) {
            if (current) {
                stack.push(current);
            }
        }
        Node<T, k>& operator*() {
            return *current;
        }

        Node<T, k>* operator->() {
            return current;
        }

        PreOrderIterator& operator++() {
            // Finished traversing this branch
            if (stack.empty()) {
                current = nullptr;
                return *this;
            }

            // Pop the current node
            current = stack.top();
            stack.pop();

            // Right child is pushed first so that left child is processed first
            // Reverse this logic depending on children order preference
            if (current->children.size() > 1) {
                stack.push(current->children[1]);
            }
            if (!current->children.empty()) {
                stack.push(current->children[0]);
            }

            if (!stack.empty()) {
                current = stack.top();
            } else {
                current = nullptr;
            }

            return *this;
        }

        bool operator!=(const PreOrderIterator& other) {
            return current != other.current;
        }

    private:
        Node<T, k>* current;
        std::stack<Node<T, k>*> stack;
    };

    PreOrderIterator begin_pre_order() {
        return PreOrderIterator(root);
    }

    PreOrderIterator end_pre_order() {
        return PreOrderIterator(nullptr);
    }

    class PostOrderIterator {
    public:

        Node<T, k>* current;
        std::stack<Node<T, k>*> stack;
        std::set<Node<T, k>*> visited;

        PostOrderIterator(Node<T, k>* root) {
            current = root;
            if (current) {
                moveToNextLeaf();
            }
        }

        Node<T, k>& operator*() {
            return *current;
        }

        Node<T, k>* operator->() {
            return current;
        }

        // Move to the next leaf node
        void moveToNextLeaf() {
            while (current) {
                stack.push(current);
                if (!current->children.empty() && visited.find(current) == visited.end()) {
                    current = current->children.front();
                } else {
                    break;
                }
            }
            if (!stack.empty()) {
                current = stack.top();
            } else {
                current = nullptr;
            }
        }

        PostOrderIterator& operator++() {
            if (stack.empty()) {
                current = nullptr;
                return *this;
            }

            visited.insert(current);
            stack.pop();

            if (!stack.empty()) {
                Node<T, k>* parent = stack.top();
                auto it = std::find(parent->children.begin(), parent->children.end(), current);
                // Check if there is another child to visit
                if ((it + 1) != parent->children.end()) {
                    current = *(it + 1);
                    moveToNextLeaf();  // Move to the leftmost child of the new current
                } else {
                    current = parent;
                }
            } else {
                current = nullptr;
            }
            return *this;
        }

        bool operator!=(const PostOrderIterator& other) const {
            return current != other.current;
        }
    };

    PostOrderIterator begin_post_order() {
        return PostOrderIterator(root);
    }

    PostOrderIterator end_post_order() {
        return PostOrderIterator(nullptr);
    }



    class InOrderIterator {
    public:
        Node<T, k>* current;
        std::stack<Node<T, k>*> stack;

        explicit InOrderIterator(Node<T, k>* root) {
            current = nullptr;
            pushLeft(root);  // Initialize by pushing left children starting from the root.
            if (!stack.empty()) {
                current = stack.top(); // Start with the leftmost node
            }
        }

        void pushLeft(Node<T, k>* node) {
            // Push all the left children of the given node onto the stack
            while (node != nullptr) {
                stack.push(node);
                if (!node->children.empty() && node->children.size() > 0) {
                    node = node->children[0]; // Go to left child
                } else {
                    break; // No left child exists
                }
            }
        }

        Node<T, k>& operator*() const {
            return *current;
        }

        Node<T, k>* operator->() const {
            return current;
        }

        InOrderIterator& operator++() {
            if (stack.empty()) {
                current = nullptr;
                return *this;
            }

            current = stack.top();
            stack.pop();

            // Now process the right subtree if it exists
            if (current->children.size() > 1) {
                pushLeft(current->children[1]); // Assuming the right child is the second child
            }

            if (!stack.empty()) {
                current = stack.top();
            } else {
                current = nullptr; // If stack is empty, we're done
            }

            return *this;
        }

        bool operator!=(const InOrderIterator& other) const {
            return current != other.current;
        }
    };

    InOrderIterator begin_in_order() {
        return InOrderIterator(root);
    }

    InOrderIterator end_in_order() {
        return InOrderIterator(nullptr);
    }



    class BFSIterator {
    public:
        std::queue<Node<T, k>*> queue;
        Node<T, k>* current;

        explicit BFSIterator(Node<T, k>* root) {
            if (root) {
                queue.push(root);
                current = queue.front();
            } else {
                current = nullptr;
            }
        }

        Node<T, k>& operator*() {
            return *current;
        }

        Node<T, k>* operator->() {
            return current;
        }

        // Advance the iterator to the next node in BFS order
        BFSIterator& operator++() {
            if (queue.empty()) {
                current = nullptr;
                return *this;
            }

            // Remove the current node from the queue
            queue.pop();

            // Enqueue all children of the current node
            if (current) {
                for (auto child : current->children) {
                    if (child) {  // Ensure that the child pointer is not null
                        queue.push(child);
                    }
                }
            }

            // Set the current node to the next node in the queue, or null if the queue is empty
            current = !queue.empty() ? queue.front() : nullptr;

            return *this;
        }

        bool operator!=(const BFSIterator& other) const {
            return current != other.current;
        }
    };

    BFSIterator begin_bfs_scan() {
        return BFSIterator(root);
    }

    BFSIterator end_bfs_scan() {
        return BFSIterator(nullptr);
    }

     BFSIterator begin() {
        return begin_bfs_scan();
    }

    BFSIterator end() {
        return end_bfs_scan();
    }



    class DFSIterator {
    public:
        DFSIterator(Node<T, k>* node) : stack() {
            if (node) {
                stack.push(node);
            }
        }

        Node<T, k>& operator*() {
            return *stack.top();
        }

        Node<T, k>* operator->() {
            return stack.top();
        }

        DFSIterator& operator++() {
            Node<T, k>* current = stack.top();
            stack.pop();
            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
                stack.push(*it);
            }
            return *this;
        }

        bool operator!=(const DFSIterator& ) {
            return !stack.empty();
        }

    private:
        std::stack<Node<T, k>*> stack;
    };

    DFSIterator begin_dfs_scan() {
        return DFSIterator(root);
    }

    DFSIterator end_dfs_scan() {
        return DFSIterator(nullptr);
    }


    class HeapIterator {
    public:
        HeapIterator(Node<T, k>* node) {
            if (node) {
                collectNodes(node);
                std::make_heap(heap.begin(), heap.end(), CompareNodes());
            }
        }

        Node<T, k>& operator*() {
            return *heap.front();
        }

        Node<T, k>* operator->() {
            return heap.front();
        }

        HeapIterator& operator++() {
            std::pop_heap(heap.begin(), heap.end(), CompareNodes());
            heap.pop_back();
            return *this;
        }

        bool operator!=(const HeapIterator&) const {
            return !heap.empty();
        }

    private:
        struct CompareNodes {
            bool operator()(Node<T, k>* a, Node<T, k>* b) {
                return a->value > b->value;
            }
        };

        std::vector<Node<T, k>*> heap;

        void collectNodes(Node<T, k>* node) {
            if (node) {
                heap.push_back(node);
                for (auto child : node->children) {
                    collectNodes(child);
                }
            }
        }
    };


    HeapIterator myHeap() {
        return HeapIterator(root);
    }

    HeapIterator end_heap() {
        return HeapIterator(nullptr);
    }


    // Output operator for debuging
    friend std::ostream& operator<<(std::ostream& os, const Tree<T, k>& tree) {
        if (!tree.root) {
            return os << "Empty tree";
        }

        std::queue<Node<T, k>*> q;
        q.push(tree.root);
        size_t currentLevel = 0;
        size_t nextLevelCount = 1;

        while (!q.empty()) {
            Node<T, k>* currentNode = q.front();
            q.pop();
            nextLevelCount--;

            os << std::setw(10) << currentNode->value << " | ";
            if (!currentNode->children.empty()) {
                for (const auto& child : currentNode->children) {
                    os << child->value << " ";
                    q.push(child);
                }
            } else {
                os << "- ";
            }
            os << std::endl;

            if (nextLevelCount == 0) {
                currentLevel++;
                nextLevelCount = q.size();
                if (nextLevelCount > 0) {
                    os << std::string(10 * currentLevel, '-') << std::endl;
                }
            }
        }

        return os;
    }

private:
 

    void destroyTree(Node<T, k>* node) {
        if (node) {
            for (auto child : node->children) {
                destroyTree(child);
            }
            delete node;
        }
    }
};

} 

#endif  