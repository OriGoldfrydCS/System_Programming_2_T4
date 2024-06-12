#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

namespace ori {
template <typename T, int k = 2>
class Node {
public:
    T value;
    std::vector<Node<T, k>*> children;

    Node(const T& val) : value(val) {}

    T get_value() const {  // Ensure this method is available
        return value;
    }
};
}  // namespace ori

#endif  // NODE_HPP