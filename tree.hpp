// Email: origoldbsc@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <SFML/Graphics.hpp>
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
            if (root) 
            {  
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
            if (parent && parent->get_children().size() < k) 
            {
                parent->add_child(child); 
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
         * @brief Overloads the stream << operator to provide a tree output.
         * @param os Output stream.
         * @param tree The tree to be printed.
         * @return Reference to the output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, const Tree<T, k>& tree) 
        {
            int depth = tree.calculateDepth(tree.root);         // Calculate the depth of the tree
            int maxWidth = std::pow(k, depth - 1);              // Calculate the maximum width of the tree based on its depth      
            int windowWidth = std::max(1200, maxWidth * 100);   // Set the window width based on the maximum width of the tree
            int windowHeight = std::max(800, depth * 150);      // Set the window height based on the depth of the tree


            // Create an SFML window with the calculated dimensions
            sf::RenderWindow window(sf::VideoMode(static_cast<unsigned int>(windowWidth), static_cast<unsigned int>(windowHeight)), "Tree Visualization");
            
            // Set the frame rate limit for the window
            window.setFramerateLimit(60);

            // Create a view that can be moved 
            sf::View view(sf::FloatRect(0, 0, windowWidth, windowHeight));

            // Font
            sf::Font font;
            if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) 
            {
                std::cerr << "Error loading font\n";
                return os;
            }

            // Main event loop
            while (window.isOpen()) 
            {
                sf::Event event;
                while (window.pollEvent(event)) 
                {
                    if (event.type == sf::Event::Closed) 
                    {
                        window.close();
                    }
                    
                    // Handle mouse wheel scrolling to zoom in and out
                    if (event.type == sf::Event::MouseWheelScrolled) 
                    {
                        if (event.mouseWheelScroll.delta > 0) 
                        {
                            view.zoom(0.9f);
                        } 
                        else 
                        {
                            view.zoom(1.1f);
                        }
                    }

                    // Handle arrow keys to move the view
                    if (event.type == sf::Event::KeyPressed) 
                    {
                        if (event.key.code == sf::Keyboard::Up) 
                        {
                            view.move(0, -50);
                        } 
                        else if (event.key.code == sf::Keyboard::Down) 
                        {
                            view.move(0, 50);
                        } 
                        else if (event.key.code == sf::Keyboard::Left) 
                        {
                            view.move(-50, 0);
                        } 
                        else if (event.key.code == sf::Keyboard::Right) 
                        {
                            view.move(50, 0);
                        }
                    }
                }

                window.clear(sf::Color::White);                      // Clear the window with a white color
                window.setView(view);                                // Set the view for the window
                float initialOffset = windowWidth / (2 * maxWidth);  // Calculate the initial offset for drawing nodes
                tree.drawTree(window, tree.root, font, windowWidth / 2, 50, initialOffset * maxWidth, 0); // Draw the tree
                window.display();                                    // Display the window content
            }

            return os;
        }

        /**
         * @brief Draws the tree nodes and edges on the window.
         * @param window The SFML window to draw on.
         * @param node The current node to draw.
         * @param font The font used for text.
         * @param x X-coordinate for drawing the node.
         * @param y Y-coordinate for drawing the node.
         * @param offset Offset for child nodes.
         */
        void drawTree(sf::RenderWindow& window, Node<T, k>* node, sf::Font& font, float x, float y, float offset, int depth) const {
            if (!node) return;

            sf::CircleShape circle(20);                 // Create a circle shape to represent the node
            circle.setFillColor(sf::Color::Black);      // Set the fill color of the circle to black
            circle.setPosition(x - circle.getRadius(), y - circle.getRadius());     // Set the position of the circle

            // Create a text to display the node's value
            sf::Text text;
            text.setFont(font);
            text.setString(custom_to_string(node->get_value())); 
            text.setCharacterSize(10);  
            text.setFillColor(sf::Color::White);  

            // Center the text within the circle
            sf::FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            text.setPosition(x, y);

            // Draw the circle and text
            window.draw(circle);
            window.draw(text);

            float child_y = y + 100;        // Calculate the y-coordinate for the child nodes

            size_t numChildren = node->get_children().size();           // Get the number of children
            float child_x_start = x - (numChildren - 1) * offset / 2;   // Calculate the starting x-coordinate for the child node  

            // Draw each child node and the line between them
            for (size_t i = 0; i < numChildren; ++i) 
            {
                float child_x = child_x_start + i * offset;  

                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x, y), sf::Color::Black),               // Line starts at the current node
                    sf::Vertex(sf::Vector2f(child_x, child_y), sf::Color::Black)    // Line ends at the child node
                };
                window.draw(line, 2, sf::Lines);    // Draw the line

                drawTree(window, node->get_children()[i], font, child_x, child_y, offset / std::max(static_cast<int>(numChildren), 2), depth + 1); 
            }
        }
        

    private:

        /**
         * @brief Recursively destroys the tree, freeing all nodes.
         * @param node The current node to destroy.
         */
        void destroyTree(Node<T, k>* root) 
        {
            if (root) 
            {
                // std::cout << "Destroying node with value: " << root->get_value() << std::endl; // For debugging
                for (auto& child : root->get_children()) 
                {
                    destroyTree(child);     // Recursively destroy child nodes
                }
                delete root;        // Delete the current node
                root = nullptr;     // Clear the pointer after deletion
            }
        }


        /**
         * @brief Recursively calculates the maximum depth of the tree.
         * @param node The current node to calculate the depth for.
         * @return The maximum depth of the tree.
         */
        int calculateDepth(Node<T, k>* node) const 
        {
            if (!node) return 0;        // Base case: if the node is null, return 0
            int maxDepth = 0;
            
            // Calculate the depth of each child node
            for (auto child : node->get_children())     
            {
                maxDepth = std::max(maxDepth, calculateDepth(child));
            }

            return maxDepth + 1;        // Return the maximum depth plus one for the current node
        }


        /**
         * @brief Converts values to strings with 2 decimal precision.
         * @param value The value to be converted.
         * @return The string representation of the value.
         */
        static std::string custom_to_string(const T& value) 
        {   
            // If the value is a string, return it directly
            if constexpr (std::is_same_v<T, std::string>) 
            {
                return value;
            } 

            // If the value is a Complex number, use its toString method
            else if constexpr (std::is_same_v<T, Complex>) 
            {
                return value.toString();
            } 

            // Format floating-point values with 2 decimal places
            else if constexpr (std::is_floating_point_v<T>) 
            {
                std::ostringstream out;
                out << std::fixed << std::setprecision(2) << value;
                return out.str();
            } 
            else 
            {
                return std::to_string(value);
            }
        }

    };
} 

#endif  