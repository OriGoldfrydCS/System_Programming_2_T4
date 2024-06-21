// Email: origoldbsc@gmail.com

#include "complex.hpp"
#include <sstream>

using std::string;
using std::ostringstream;
using std::ostream;

namespace ori {

    /**
     * @brief Constructor for Complex class.
     * @param r Real part of the complex number (default is 0.0).
     * @param i Imaginary part of the complex number (default is 0.0).
     */
    Complex::Complex(double r = 0.0, double i = 0.0) : real(r), image(i) {}


    /**
     * @brief Destructor for the Complex class.
     * @details This destructor is trivial because the Complex class does not manage any resources for allocation of memory.
     * If Complex objects are created on the heap within a certain scope, 
     * for example using `Complex* c = new Complex(1.0, 2.0);`, ensure to call `delete c;` 
     * at the end of the scope to properly release the allocated memory. This avoids memory leaks.
     */
    Complex::~Complex() {}

    /**
     * @brief Overload the == operator for comparison.
     * @param other The other complex number to compare with.
     * @return True if the complex numbers are equal, false otherwise.
     */
    bool Complex::operator==(const Complex& other) const 
    {
        return real == other.real && image == other.image;
    }


    /**
     * @brief Overload the != operator for comparison.
     * @param other The other complex number to compare with.
     * @return True if the complex numbers are not equal, false otherwise.
     */
    bool Complex::operator!=(const Complex& other) const 
    {
        return !(*this == other);
    }


    /**
     * @brief Overload the > operator for comparison.
     * @param other The other complex number to compare with.
     * @return True if this complex number is greater than the other.
     */
    bool Complex::operator>(const Complex& other) const 
    {
        return (real * real + image * image) > (other.real * other.real + other.image * other.image);
    }

    // Overload the < operator for comparison
    bool Complex::operator<(const Complex& other) const 
    {
        return !(*this > other) && (*this != other);
    }


    /**
     * @brief Converts the complex number to a string representation.
     * @return A string in the form "real+imagi" or "real-imagi".
     */
    string Complex::toString() const 
    {
        ostringstream oss;
        oss << real << (image >= 0 ? "+" : "") << image << "i";
        return oss.str();
    }


    /**
     * @brief Overloads the << operator for outputting a complex number.
     * @param os The output stream.
     * @param c The complex number to output.
     * @return The output stream.
     */
    ostream& operator<<(std::ostream& os, const Complex& c) 
    {
        os << c.real << (c.image >= 0 ? "+" : "") << c.image << "i";
        return os;
    }
}


